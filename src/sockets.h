#pragma once
#include <Arduino.h>

#include "ESPAsyncTCP.h"
#include "motor.h"
#include "music.h"
AsyncWebSocket ws("/ws");  // access at ws://[esp ip]/ws
uint32_t last_action = 0;
void onEvent(AsyncWebSocket* server, AsyncWebSocketClient* client, AwsEventType type, void* arg, uint8_t* data, size_t len) {
  switch (type) {
    case WS_EVT_DISCONNECT: {
      play(song_disconnected2);
      break;
    }
    case WS_EVT_CONNECT: {
      play(song_connected2);
      last_action = millis();
      break;
    }
    case WS_EVT_DATA: {
      motor_command((int8_t)data[0] / 100.0, (int8_t)data[1] / 100.0);
      uint8_t payload[] = {0, data[0], data[1], data[2]};
      ws.binaryAll(payload, sizeof(payload));
      last_action = millis();
      break;
    }
  }
}
void setup_sockets() {
  ws.onEvent(onEvent);
  server.addHandler(&ws);
}

#define STATUS_UPDATE_MS 100
void loop_sockets() {
  static uint32_t last_ms = millis();
  uint32_t now = millis();
  uint16_t delta = now - last_ms;
  static float battery = 10;
  ws.cleanupClients(4);
  if (delta > STATUS_UPDATE_MS) {
    battery = analogRead(A0) / 1024.0 * 6.22;
    struct __attribute__((packed)) {
      uint8_t type = 1;
      uint16_t battery_mv = 1000.0 * battery;
      uint8_t freeHeap_kb = ESP.getFreeHeap() / 1024;
    } payload;
    ws.binaryAll((uint8_t*)&payload, sizeof(payload));

    static uint16 bat_low_count = 0;
    bool bat_low = battery < 1 * 4;
    bat_low_count = bat_low ? bat_low_count + 1 : 0;

    static uint16 bat_empty_count = 0;
    bool bat_empty = battery < .9 * 4;
    bat_empty_count = bat_empty ? bat_empty_count + 1 : 0;

    bool inactive = now - last_action > 60000;
    bool inactive_long = now - last_action > 60000 * 10;

    static bool beeping;
    if ((bat_empty_count > 10000 / STATUS_UPDATE_MS) || inactive_long) {
      motor.changeDuty(MOTOR_CH_BOTH, 0);
      motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_STANDBY);
      ESP.deepSleep(0);
    } else if (bat_low_count > 10000 / STATUS_UPDATE_MS) {
      motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
      motor.changeDuty(MOTOR_CH_A, 25);
      motor.changeFreq(MOTOR_CH_A, (now / 100) % 2 ? 400 : 1000);
      beeping = true;
    } else if (inactive) {
      motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
      motor.changeDuty(MOTOR_CH_A, 25);
      motor.changeFreq(MOTOR_CH_A, (now / 2000) % 4 == 0 ? 400 : MOTOR_FREQ);
      beeping = true;
    } else if (beeping) {
      beeping = false;
      motor.changeFreq(MOTOR_CH_BOTH, MOTOR_FREQ);
    }
    last_ms = now;
  }
}
