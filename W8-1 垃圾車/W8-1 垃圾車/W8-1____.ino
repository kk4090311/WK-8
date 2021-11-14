#include "pitches.h"

int freq = 2000;
int channel = 0;
int resolution = 8;

int tonePin = 12;

int melody[] = {
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5,
  NOTE_C5, NOTE_A4, 
  NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4,
  NOTE_E4, NOTE_GS4, NOTE_B4, NOTE_C5, NOTE_E4,
  
  NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_DS5, NOTE_E5, NOTE_B4, NOTE_D5,
  NOTE_C5, NOTE_A4, 
  NOTE_C4, NOTE_E4, NOTE_A4, NOTE_B4,
  NOTE_E4, NOTE_C5, NOTE_B4, NOTE_A4, 
  
  
};
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4,
  4, 8/3,
  4, 4, 4, 8/3,
  4, 4, 4, 8/3, 4, 
  4, 4, 4, 4, 4, 4, 4,
  4, 8/3,
  4, 4, 4, 8/3,
  4, 4, 4, 8/3, 4,
};

void setup() {
  Serial.begin(115200);
  ledcSetup(channel, freq, resolution);
  ledcAttachPin(tonePin, channel);
}

void loop() {
    for (int thisNote = 0; thisNote < 42; thisNote++) {
      int noteDuration = 1000 / noteDurations[thisNote];
      ledcWriteTone(channel, melody[thisNote]);
      delay(noteDuration);
      ledcWriteTone(channel, 0);
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
    }
}
