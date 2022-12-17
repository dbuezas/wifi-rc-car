#pragma once

typedef struct {
  int tempo;
  int size;
  const int* melody;
} Song;

// notes of the moledy followed by the duration.
// a 4 means a quarter note, 8 an eighteenth , 16 sixteenth, so on
// !!negative numbers are used to represent dotted notes,
// so -4 means a dotted quarter note, that is, a quarter plus an eighteenth!!

// sizeof gives the number of bytes, each int value is composed of two bytes (16 bits)
// there are two values per note (pitch and duration), so for each note there are four bytes

// this calculates the duration of a whole note in ms
// from https://github.com/robsoncouto/arduino-songs
#define NOTE_B0 31
#define NOTE_C1 33
#define NOTE_CS1 35
#define NOTE_D1 37
#define NOTE_DS1 39
#define NOTE_E1 41
#define NOTE_F1 44
#define NOTE_FS1 46
#define NOTE_G1 49
#define NOTE_GS1 52
#define NOTE_A1 55
#define NOTE_AS1 58
#define NOTE_B1 62
#define NOTE_C2 65
#define NOTE_CS2 69
#define NOTE_D2 73
#define NOTE_DS2 78
#define NOTE_E2 82
#define NOTE_F2 87
#define NOTE_FS2 93
#define NOTE_G2 98
#define NOTE_GS2 104
#define NOTE_A2 110
#define NOTE_AS2 117
#define NOTE_B2 123
#define NOTE_C3 131
#define NOTE_CS3 139
#define NOTE_D3 147
#define NOTE_DS3 156
#define NOTE_E3 165
#define NOTE_F3 175
#define NOTE_FS3 185
#define NOTE_G3 196
#define NOTE_GS3 208
#define NOTE_A3 220
#define NOTE_AS3 233
#define NOTE_B3 247
#define NOTE_C4 262
#define NOTE_CS4 277
#define NOTE_D4 294
#define NOTE_DS4 311
#define NOTE_E4 330
#define NOTE_F4 349
#define NOTE_FS4 370
#define NOTE_G4 392
#define NOTE_GS4 415
#define NOTE_A4 440
#define NOTE_AS4 466
#define NOTE_B4 494
#define NOTE_C5 523
#define NOTE_CS5 554
#define NOTE_D5 587
#define NOTE_DS5 622
#define NOTE_E5 659
#define NOTE_F5 698
#define NOTE_FS5 740
#define NOTE_G5 784
#define NOTE_GS5 831
#define NOTE_A5 880
#define NOTE_AS5 932
#define NOTE_B5 988
#define NOTE_C6 1047
#define NOTE_CS6 1109
#define NOTE_D6 1175
#define NOTE_DS6 1245
#define NOTE_E6 1319
#define NOTE_F6 1397
#define NOTE_FS6 1480
#define NOTE_G6 1568
#define NOTE_GS6 1661
#define NOTE_A6 1760
#define NOTE_AS6 1865
#define NOTE_B6 1976
#define NOTE_C7 2093
#define NOTE_CS7 2217
#define NOTE_D7 2349
#define NOTE_DS7 2489
#define NOTE_E7 2637
#define NOTE_F7 2794
#define NOTE_FS7 2960
#define NOTE_G7 3136
#define NOTE_GS7 3322
#define NOTE_A7 3520
#define NOTE_AS7 3729
#define NOTE_B7 3951
#define NOTE_C8 4186
#define NOTE_CS8 4435
#define NOTE_D8 4699
#define NOTE_DS8 4978
#define REST 0
const int melody_elephant[] PROGMEM = { NOTE_C4,-8, NOTE_E4,16, NOTE_G4,8, NOTE_C5,8, NOTE_E5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_FS4,8, NOTE_G4,8, REST,4, REST,2, NOTE_C4,-8, NOTE_E4, 16, NOTE_G4,8, NOTE_C5,8, NOTE_E5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_G4,-2, NOTE_A4,8,  NOTE_DS4,1, NOTE_A4,8, NOTE_E4,8, NOTE_C4,8, REST,4, REST,2, NOTE_C4,-8, NOTE_E4,16, NOTE_G4,8, NOTE_C5,8, NOTE_E5,8, NOTE_D5,8, NOTE_C5,8, NOTE_A4,8, NOTE_FS4,8, NOTE_G4,8, REST,4, REST,4, REST,8, NOTE_G4,8, NOTE_D5,4, NOTE_D5,4, NOTE_B4,8, NOTE_G4,8, REST,8, NOTE_G4,8, NOTE_C5,4, NOTE_C5,4, NOTE_AS4,16, NOTE_C5,16, NOTE_AS4,16, NOTE_G4,16, NOTE_F4,8, NOTE_DS4,8, NOTE_FS4,4, NOTE_FS4,4, NOTE_F4,16, NOTE_G4,16, NOTE_F4,16, NOTE_DS4,16, NOTE_C4,8, NOTE_G4,8, NOTE_AS4,8, NOTE_C5,8, REST,4, REST,2,};

const Song song_elephant PROGMEM = {
  tempo: 132,
  size: sizeof(melody_elephant) / sizeof(melody_elephant[0]),
  melody: melody_elephant,
};

const int melody_harry[] PROGMEM = { REST, 2, NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, NOTE_G4, 2, NOTE_D5, 4, NOTE_C5, -2,  NOTE_A4, -2, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4, NOTE_F4, 2, NOTE_GS4, 4, NOTE_D4, -1,  NOTE_D4, 4, NOTE_G4, -4, NOTE_AS4, 8, NOTE_A4, 4,  NOTE_G4, 2, NOTE_D5, 4, NOTE_F5, 2, NOTE_E5, 4, NOTE_DS5, 2, NOTE_B4, 4, NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_B4, 4, NOTE_G4, -1, NOTE_AS4, 4, NOTE_D5, 2, NOTE_AS4, 4, NOTE_D5, 2, NOTE_AS4, 4, NOTE_DS5, 2, NOTE_D5, 4, NOTE_CS5, 2, NOTE_A4, 4, NOTE_AS4, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_D4, 4, NOTE_D5, -1, REST,4, NOTE_AS4,4, NOTE_D5, 2, NOTE_AS4, 4, NOTE_D5, 2, NOTE_AS4, 4, NOTE_F5, 2, NOTE_E5, 4, NOTE_DS5, 2, NOTE_B4, 4, NOTE_DS5, -4, NOTE_D5, 8, NOTE_CS5, 4, NOTE_CS4, 2, NOTE_AS4, 4, NOTE_G4, -1, };

const Song song_harry PROGMEM = {
  tempo: 144,
  size: sizeof(melody_harry) / sizeof(melody_harry[0]),
  melody: melody_harry,
};

const int melody_imperial[] PROGMEM = { NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8, NOTE_A4,-4, NOTE_A4,-4, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_A4,16, NOTE_F4,8, REST,8, NOTE_A4,4, NOTE_A4,4, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2, NOTE_E5,4, NOTE_E5,4, NOTE_E5,4, NOTE_F5,-8, NOTE_C5,16, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2, NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16, NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16, NOTE_C5,4, NOTE_A4,-8, NOTE_C5,16, NOTE_E5,2, NOTE_A5,4, NOTE_A4,-8, NOTE_A4,16, NOTE_A5,4, NOTE_GS5,-8, NOTE_G5,16, NOTE_DS5,16, NOTE_D5,16, NOTE_DS5,8, REST,8, NOTE_A4,8, NOTE_DS5,4, NOTE_D5,-8, NOTE_CS5,16, NOTE_C5,16, NOTE_B4,16, NOTE_C5,16, REST,8, NOTE_F4,8, NOTE_GS4,4, NOTE_F4,-8, NOTE_A4,-16, NOTE_A4,4, NOTE_F4,-8, NOTE_C5,16, NOTE_A4,2,};

const Song song_imperial PROGMEM = {
  tempo: 120,
  size: sizeof(melody_imperial) / sizeof(melody_imperial[0]),
  melody: melody_imperial,
};

const int melody_mario[] PROGMEM = { NOTE_E5, 8, NOTE_E5, 8, REST, 8, NOTE_E5, 8, REST, 8,  NOTE_C5, 8, NOTE_E5, 8, NOTE_G5, 4, REST, 4, NOTE_G4, 8, REST, 4, NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4, NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8, REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4, NOTE_C5, -4, NOTE_G4, 8, REST, 4, NOTE_E4, -4, NOTE_A4, 4, NOTE_B4, 4, NOTE_AS4, 8, NOTE_A4, 4, NOTE_G4, -8, NOTE_E5, -8, NOTE_G5, -8, NOTE_A5, 4, NOTE_F5, 8, NOTE_G5, 8, REST, 8, NOTE_E5, 4, NOTE_C5, 8, NOTE_D5, 8, NOTE_B4, -4, REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8, REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4, NOTE_C5,2, REST,2, REST,4, NOTE_G5,8, NOTE_FS5,8, NOTE_F5,8, NOTE_DS5,4, NOTE_E5,8, REST,8, NOTE_GS4,8, NOTE_A4,8, NOTE_C4,8, REST,8, NOTE_A4,8, NOTE_C5,8, NOTE_D5,8, REST,4, NOTE_DS5,4, REST,8, NOTE_D5,-4, NOTE_C5,2, REST,2, NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, REST,1, NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4, NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4, NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4, NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8, REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4, NOTE_C5,-4, NOTE_G4,8, REST,4, NOTE_E4,-4, NOTE_A4,4, NOTE_B4,4, NOTE_AS4,8, NOTE_A4,4, NOTE_G4,-8, NOTE_E5,-8, NOTE_G5,-8, NOTE_A5,4, NOTE_F5,8, NOTE_G5,8, REST,8, NOTE_E5,4, NOTE_C5,8, NOTE_D5,8, NOTE_B4,-4, NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8, NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2, NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8, NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2, NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,8, NOTE_E5,8, REST,1, NOTE_C5,8, NOTE_C5,4, NOTE_C5,8, REST,8, NOTE_C5,8, NOTE_D5,4,  NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2, NOTE_E5,8, NOTE_E5,8, REST,8, NOTE_E5,8, REST,8, NOTE_C5,8, NOTE_E5,4, NOTE_G5,4, REST,4, NOTE_G4,4, REST,4, NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_D5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_A5,-8, NOTE_G5,-8, NOTE_F5,-8, NOTE_E5,8, NOTE_C5,4, NOTE_A4,8, NOTE_G4,2,  NOTE_E5,8, NOTE_C5,4, NOTE_G4,8, REST,4, NOTE_GS4,4, NOTE_A4,8, NOTE_F5,4, NOTE_F5,8, NOTE_A4,2, NOTE_B4,8, NOTE_F5,4, NOTE_F5,8, NOTE_F5,-8, NOTE_E5,-8, NOTE_D5,-8, NOTE_C5,8, NOTE_E4,4, NOTE_E4,8, NOTE_C4,2,
    //game over sound
NOTE_C5,-4, NOTE_G4,-4, NOTE_E4,4,  NOTE_A4,-8, NOTE_B4,-8, NOTE_A4,-8, NOTE_GS4,-8,  NOTE_AS4,-8, NOTE_GS4,-8, NOTE_G4,8, NOTE_D4,8, NOTE_E4,-2, };
const Song song_mario PROGMEM = {
  tempo: 200,
  size: sizeof(melody_mario) / sizeof(melody_mario[0]),
  melody: melody_mario,
};

const int melody_pink[] PROGMEM = { NOTE_DS4,8, NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8, NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8, NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,  NOTE_E4,2, REST,4, REST,8, NOTE_DS4,4, NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8, NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_G4,8, NOTE_B4,-8, NOTE_E5,8, NOTE_DS5,1, NOTE_D5,2, REST,4, REST,8, NOTE_DS4,8,  NOTE_E4,-4, REST,8, NOTE_FS4,8, NOTE_G4,-4, REST,8, NOTE_DS4,8, NOTE_E4,-8, NOTE_FS4,8,  NOTE_G4,-8, NOTE_C5,8, NOTE_B4,-8, NOTE_E4,8, NOTE_G4,-8, NOTE_B4,8, NOTE_AS4,2, NOTE_A4,-16, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16,  NOTE_E4,-4, REST,4, REST,4, NOTE_E5,-8, NOTE_D5,8, NOTE_B4,-8, NOTE_A4,8, NOTE_G4,-8, NOTE_E4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_AS4,16, NOTE_A4,-8, NOTE_G4,-16, NOTE_E4,-16, NOTE_D4,-16, NOTE_E4,16, NOTE_E4,16, NOTE_E4,2, };
const Song song_pink PROGMEM = {
  tempo: 120,
  size: sizeof(melody_pink) / sizeof(melody_pink[0]),
  melody: melody_pink,
};

const int melody_starwars[] PROGMEM = { NOTE_AS4, 8, NOTE_AS4, 8, NOTE_AS4, 8, NOTE_F5, 2, NOTE_C6, 2, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4, NOTE_AS5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_G5, 2, NOTE_C5, 8, NOTE_C5, 8, NOTE_C5, 8, NOTE_F5, 2, NOTE_C6, 2, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F6, 2, NOTE_C6, 4,   NOTE_AS5, 8, NOTE_A5, 8, NOTE_AS5, 8, NOTE_G5, 2, NOTE_C5, -8, NOTE_C5, 16, NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_D5, 8, NOTE_E5, 4, NOTE_C5, -8, NOTE_C5, 16, NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_C6, -8, NOTE_G5, 16, NOTE_G5, 2, REST, 8, NOTE_C5, 8,   NOTE_D5, -4, NOTE_D5, 8, NOTE_AS5, 8, NOTE_A5, 8, NOTE_G5, 8, NOTE_F5, 8, NOTE_F5, 8, NOTE_G5, 8, NOTE_A5, 8, NOTE_G5, 4, NOTE_D5, 8, NOTE_E5, 4, NOTE_C6, -8, NOTE_C6, 16, NOTE_F6, 4, NOTE_DS6, 8, NOTE_CS6, 4, NOTE_C6, 8, NOTE_AS5, 4, NOTE_GS5, 8, NOTE_G5, 4, NOTE_F5, 8, NOTE_C6, 1};
const Song song_starwars PROGMEM = {
  tempo: 150,
  size: sizeof(melody_starwars) / sizeof(melody_starwars[0]),
  melody: melody_starwars,
};

const int melody_takeonme[] PROGMEM = { NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8, NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,   REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8, NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_FS5,8,NOTE_D5,8, NOTE_B4,8, REST,8, NOTE_B4,8, REST,8, NOTE_E5,8,  REST,8, NOTE_E5,8, REST,8, NOTE_E5,8, NOTE_GS5,8, NOTE_GS5,8, NOTE_A5,8, NOTE_B5,8,  NOTE_A5,8, NOTE_A5,8, NOTE_A5,8, NOTE_E5,8, REST,8, NOTE_D5,8, REST,8, NOTE_FS5,8,  REST,8, NOTE_FS5,8, REST,8, NOTE_FS5,8, NOTE_E5,8, NOTE_E5,8, NOTE_FS5,8, NOTE_E5,8,  };
const Song song_takeonme PROGMEM = {
  tempo: 180,
  size: sizeof(melody_takeonme) / sizeof(melody_takeonme[0]),
  melody: melody_takeonme,
};

const int melody_tetris[] PROGMEM = {    NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8, NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4, NOTE_E5, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_C5,8,  NOTE_B4,8,NOTE_A4, 4,  NOTE_A4,8,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,NOTE_B4, -4,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,8,  NOTE_A4,4,  NOTE_B4,8,  NOTE_C5,8, NOTE_D5, -4,  NOTE_F5,8,  NOTE_A5,4,  NOTE_G5,8,  NOTE_F5,8,NOTE_E5, -4,  NOTE_C5,8,  NOTE_E5,4,  NOTE_D5,8,  NOTE_C5,8,NOTE_B4, 4,  NOTE_B4,8,  NOTE_C5,8,  NOTE_D5,4,  NOTE_E5,4,NOTE_C5, 4,  NOTE_A4,4,  NOTE_A4,4, REST, 4, NOTE_E5,2,  NOTE_C5,2,NOTE_D5,2,   NOTE_B4,2,NOTE_C5,2,   NOTE_A4,2,NOTE_GS4,2,  NOTE_B4,4,  REST,8, NOTE_E5,2,   NOTE_C5,2,NOTE_D5,2,   NOTE_B4,2,NOTE_C5,4,   NOTE_E5,4,  NOTE_A5,2,NOTE_GS5,2, };
const Song song_tetris PROGMEM = {
  tempo: 130,
  size: sizeof(melody_tetris) / sizeof(melody_tetris[0]),
  melody: melody_tetris,
};

const int melody_godfather[] PROGMEM = {      NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,   NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8,   NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,   NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,      NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,   NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,   NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8,    NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,    NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8,   NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8,    NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,   NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8,        NOTE_E4, 2, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,      NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8, NOTE_G4, 8,   NOTE_E4, 2, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8,   NOTE_B4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_A4, 8, NOTE_E4, 8, NOTE_DS4, 8,      NOTE_D4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,   NOTE_B4, 2, NOTE_D4, 8, NOTE_F4, 8, NOTE_GS4, 8,   NOTE_A4, 2, NOTE_C4, 8, NOTE_C4, 8, NOTE_G4, 8,    NOTE_F4, 8, NOTE_E4, 8, NOTE_G4, 8, NOTE_F4, 8, NOTE_F4, 8, NOTE_E4, 8, NOTE_E4, 8, NOTE_GS4, 8,    NOTE_A4, 2, REST,8, NOTE_A4, 8, NOTE_A4, 8, NOTE_GS4, 8,   NOTE_G4, 2, NOTE_B4, 8, NOTE_A4, 8, NOTE_F4, 8,    NOTE_E4, 2, NOTE_E4, 8, NOTE_G4, 8, NOTE_E4, 8,   NOTE_D4, 2, NOTE_D4, 8, NOTE_D4, 8, NOTE_F4, 8, NOTE_DS4, 8,        NOTE_E4, 2 };
const Song song_godfather PROGMEM = {
  tempo: 80,
  size: sizeof(melody_godfather) / sizeof(melody_godfather[0]),
  melody: melody_godfather,
};

const int melody_thelick[] PROGMEM = { NOTE_D4,8, NOTE_E4,8, NOTE_F4,8, NOTE_G4,8, NOTE_E4,4, NOTE_C4,8, NOTE_D4, 2, };
const Song song_thelick PROGMEM = {
  tempo: 200,
  size: sizeof(melody_thelick) / sizeof(melody_thelick[0]),
  melody: melody_thelick,
};

const int melody_pirates[] PROGMEM = {NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,8,NOTE_D4,8,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,8,NOTE_D4,8,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_D4,4,NOTE_D4,8,NOTE_A3,8,NOTE_C4,8,NOTE_D4,8,NOTE_D4,4,NOTE_D4,4,NOTE_E4,8,NOTE_F4,8,NOTE_F4,4,NOTE_F4,4,NOTE_G4,8,NOTE_E4,8,NOTE_E4,4,NOTE_D4,4,NOTE_C4,8,NOTE_C4,8,NOTE_D4,8,0,4,NOTE_A3,8,NOTE_C4,8,NOTE_D4,8,NOTE_D4,4,NOTE_D4,4,NOTE_E4,8,NOTE_F4,8,NOTE_F4,4,NOTE_F4,4,NOTE_G4,8,NOTE_E4,8,NOTE_E4,4,NOTE_D4,4,NOTE_C4,8,NOTE_D4,4,0,4,NOTE_A3,8,NOTE_C4,8,NOTE_D4,8,NOTE_D4,4,NOTE_D4,4,NOTE_F4,8,NOTE_G4,8,NOTE_G4,4,NOTE_G4,4,NOTE_A4,8,NOTE_A4,8,NOTE_A4,4,NOTE_A4,4,NOTE_G4,8,NOTE_A4,8,NOTE_D4,8,0,4,NOTE_D4,8,NOTE_E4,8,NOTE_F4,8,NOTE_F4,4,NOTE_G4,4,NOTE_A4,4,NOTE_D4,8,0,4,NOTE_D4,8,NOTE_F4,8,NOTE_E4,8,NOTE_E4,4,NOTE_F4,4,NOTE_D4,8,NOTE_E4,4};
const Song song_pirates PROGMEM = {
  tempo: 240,
  size: sizeof(melody_pirates) / sizeof(melody_pirates[0]),
  melody: melody_pirates,
};

const int melody_axelf[] PROGMEM = {NOTE_D4,8,0,8,NOTE_F4,6,NOTE_D4,16,0,16,NOTE_D4,16,NOTE_G4,8,NOTE_D4,8,NOTE_C4,8,NOTE_D4,8,0,8,NOTE_A4,6,NOTE_D4,16,0,16,NOTE_D4,16,NOTE_AS4,8,NOTE_A4,8,NOTE_F4,8,NOTE_D4,8,NOTE_A4,8,NOTE_D5,8,NOTE_D4,16,NOTE_C4,16,0,16,NOTE_C4,16,NOTE_A3,8,NOTE_E4,8,NOTE_D4,2};
const Song song_axelf PROGMEM = {
  tempo: 120,
  size: sizeof(melody_axelf) / sizeof(melody_axelf[0]),
  melody: melody_axelf,
};


const int melody_connected[] PROGMEM = { NOTE_D4,8, NOTE_E4,8 };
const Song song_connected PROGMEM = {
  tempo: 200,
  size: sizeof(melody_connected) / sizeof(melody_connected[0]),
  melody: melody_connected,
};

const int melody_disconnected[] PROGMEM = { NOTE_E4,8, NOTE_D4,8 };
const Song song_disconnected PROGMEM = {
  tempo: 200,
  size: sizeof(melody_disconnected) / sizeof(melody_disconnected[0]),
  melody: melody_disconnected,
};
const int melody_connected2[] PROGMEM = { NOTE_C6,8, };
const Song song_connected2 PROGMEM = {
  tempo: 200,
  size: sizeof(melody_connected2) / sizeof(melody_connected2[0]),
  melody: melody_connected2,
};

const int melody_disconnected2[] PROGMEM = { NOTE_C4, 8};
const Song song_disconnected2 PROGMEM = {
  tempo: 200,
  size: sizeof(melody_disconnected2) / sizeof(melody_disconnected2[0]),
  melody: melody_disconnected2,
};
