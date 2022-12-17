#pragma once
#include <Arduino.h>

#include "ESPAsyncWebServer.h"
#include "motor.h"
#include "music.h"
#include "page.h"

AsyncWebServer server(80);
WiFiEventHandler stationConnectedHandler;
WiFiEventHandler stationDisconnectedHandler;

void setup_http() {
  server.onNotFound([](AsyncWebServerRequest* request) {
    AsyncWebServerResponse* response = request->beginResponse_P(200, "text/html", MAIN_page, sizeof(MAIN_page));
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/", HTTP_GET, [](AsyncWebServerRequest* request) {
    AsyncWebServerResponse* response = request->beginResponse_P(200, "text/html", MAIN_page, sizeof(MAIN_page));
    response->addHeader("Content-Encoding", "gzip");
    request->send(response);
  });
  server.on("/favicon.ico", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(404);
  });
  server.on("/heap", HTTP_GET, [](AsyncWebServerRequest* request) {
    request->send(200, "text/plain", String(ESP.getFreeHeap()));
  });
  server.on("/elephant", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_elephant);
    request->send(200);
  });
  server.on("/harry", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_harry);
    request->send(200);
  });
  server.on("/imperial", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_imperial);
    request->send(200);
  });
  server.on("/mario", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_mario);
    request->send(200);
  });
  server.on("/pink", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_pink);
    request->send(200);
  });
  server.on("/starwars", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_starwars);
    request->send(200);
  });
  server.on("/takeonme", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_takeonme);
    request->send(200);
  });
  server.on("/tetris", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_tetris);
    request->send(200);
  });
  server.on("/godfather", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_godfather);
    request->send(200);
  });
  server.on("/thelick", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_thelick);
    request->send(200);
  });
  server.on("/pirates", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_pirates);
    request->send(200);
  });
  server.on("/axelf", HTTP_GET, [](AsyncWebServerRequest* request) {
    play(song_axelf);
    request->send(200);
  });

  DefaultHeaders::Instance().addHeader("Access-Control-Allow-Origin", "*");
  server.begin();
}

void loop_http() {
}
