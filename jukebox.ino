#include "pitches.h"

//pins
const int buzzerPin = 2;
const int button1Pin = 3;
const int button2Pin = 4;
const int button3Pin = 5;

//songs data
int song1[] = { REST, 4, REST, 8, NOTE_E4, 8, NOTE_A4, 8, NOTE_C5, 8, NOTE_B4, 8 };
int song2[] = { NOTE_FS5, 8, NOTE_FS5, 8, NOTE_D5, 8, NOTE_B4, 8, NOTE_E5, 8 };
int song3[] = { NOTE_E2, 8, NOTE_E3, 8, NOTE_E2, 8, NOTE_D3, 8, NOTE_C3, 8 };
int tempo1 = 80;
int tempo2 = 140;
int tempo3 = 225;

//state variables
bool isPlaying = false; 
int currentSong = 0;    


void setup() {

  Serial.begin(9600);

  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(buzzerPin, OUTPUT);
}

//checks button presses
void loop() {
  
  if (digitalRead(button1Pin) == LOW) {
    currentSong = 1;
    isPlaying = true;
    playSong(song1, sizeof(song1) / sizeof(int), tempo1);

  } else if (digitalRead(button2Pin) == LOW) {
    currentSong = 2;
    isPlaying = true;
    playSong(song2, sizeof(song2) / sizeof(int), tempo2);

  } else if (digitalRead(button3Pin) == LOW) {
    currentSong = 3;
    isPlaying = true;
    playSong(song3, sizeof(song3) / sizeof(int), tempo3);
  } 
}


void playSong(int *melody, int size, int tempo) {

  for (int note = 0; note < size; note += 2) { 
    int duration = 1000 / melody[note + 1] * tempo / 100;

    if (melody[note] == REST) {
      noTone(buzzerPin); 

    } else {
      tone(buzzerPin, melody[note], duration);
    }
    delay(duration * 1.3);           
}

