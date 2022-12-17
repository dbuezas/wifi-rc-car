
#pragma once

#include <Arduino.h>
#include <motor.h>
#include <music-songs.h>

Song song;
int i = 2;

void play(Song song_) {
  song = song_;

  i = 0;
}
void setup_music() {
}
void loop_music() {
  if (i > song.size + 2) return;
  if (i == song.size + 2) {
    motor.changeStatus(MOTOR_CH_BOTH, MOTOR_STATUS_STOP);
    motor.changeFreq(MOTOR_CH_BOTH, MOTOR_FREQ);
    i = i + 2;
    return;
  }
  if (i == 0) {
    motor.changeDuty(MOTOR_CH_A, 50);
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
    motor.changeDuty(MOTOR_CH_B, 2);
    motor.changeStatus(MOTOR_CH_A, MOTOR_STATUS_CW);
  }

  static int noteDuration;
  static uint32_t start;
  static int freq = song.melody[i];
  uint32_t now = millis();

  if (now > start + noteDuration) {
    int wholenote = (60000 * 4) / song.tempo;
    // calculates the duration of each note
    int divider = song.melody[i + 1];
    noteDuration = wholenote / abs(divider);
    if (divider < 0) {
      noteDuration *= 1.5;  // increases the duration in half for dotted notes
    }

    // we only play the note for 90% of the duration, leaving 10% as a pause
    freq = song.melody[i];

    // Wait for the specief duration before playing the next note.
    i = i + 2;
    start = now;
  } else {
    bool slient = now > start + noteDuration * 0.9;
    if (freq == 0 || slient) {
      motor.changeFreq(MOTOR_CH_BOTH, MOTOR_FREQ);
    } else {
      motor.changeFreq(MOTOR_CH_BOTH, freq);
    }
  }
}