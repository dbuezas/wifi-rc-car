#include <Arduino.h>

#include "http.h"
#include "motor.h"
#include "music.h"
#include "sockets.h"
#include "wifi.h"

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  setup_motor();
  setup_music();
  setup_http();
  setup_wifi();
  setup_sockets();
  delay(200);  // so the motors repspond
  play(song_thelick);
}
void loop() {
  loop_motor();
  loop_music();
  loop_http();
  loop_wifi();
  loop_sockets();
  int n = wifi_softap_get_station_num();
  if (n == 0) {
    digitalWrite(LED_BUILTIN, (millis() / (n ? 1000 : 100) % 2));
  } else {
    digitalWrite(LED_BUILTIN, false);
  }
}
