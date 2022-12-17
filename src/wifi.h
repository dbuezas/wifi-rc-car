#pragma once
#include <ArduinoOTA.h>
#include <DNSServer.h>
#include <ESP8266WiFi.h>

#include "motor.h"
#include "music.h"
const byte DNS_PORT = 53;
IPAddress apIP(8, 8, 4, 4);
DNSServer dnsServer;

void onStationConnected(const WiFiEventSoftAPModeStationConnected& evt) {
  play(song_connected);
}

void onStationDisconnected(const WiFiEventSoftAPModeStationDisconnected& evt) {
  play(song_disconnected);
}

void setup_wifi() {
  WiFi.mode(WIFI_AP);
  WiFi.softAPConfig(apIP, apIP, IPAddress(255, 255, 255, 0));
  WiFi.softAP("Week's Amazing Car");
  ArduinoOTA.begin();
  ArduinoOTA.onStart([]() {
    motor.changeDuty(MOTOR_CH_A, 25);
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CCW);
  });
  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    float p = (1.0 * progress / total);
    motor.changeFreq(MOTOR_CH_A, 200 + p * 500);
    if (p == 1) {
      motor.changeDuty(MOTOR_CH_A, 0);
      motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_STANDBY);
      motor.changeFreq(MOTOR_CH_A, MOTOR_FREQ);
    }
  });

  dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
  dnsServer.start(DNS_PORT, "*", apIP);
  stationConnectedHandler = WiFi.onSoftAPModeStationConnected(&onStationConnected);
  stationDisconnectedHandler = WiFi.onSoftAPModeStationDisconnected(&onStationDisconnected);
}
void loop_wifi() {
  ArduinoOTA.handle();
  dnsServer.processNextRequest();
}
