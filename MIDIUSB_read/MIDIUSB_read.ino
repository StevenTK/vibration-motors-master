/*
 * MIDIUSB_test.ino
 *
 * Created: 4/6/2015 10:47:08 AM
 * Author: gurbrinder grewal
 * Modified by Arduino LLC (2015)
 */ 

#include "MIDIUSB.h"

// First parameter is the event type (0x09 = note on, 0x08 = note off).
// Second parameter is note-on/note-off, combined with the channel.
// Channel can be anything between 0-15. Typically reported to the user as 1-16.
// Third parameter is the note number (48 = middle C).
// Fourth parameter is the velocity (64 = normal, 127 = fastest).

void setup() {
  Serial.begin(115200);
}

// First parameter is the event type (0x0B = control change).
// Second parameter is the event type, combined with the channel.
// Third parameter is the control number number (0-119).
// Fourth parameter is the control value (0-127).


void playNote(byte noteNum, byte velocity) {
  Serial.print("Note Number: ");
  Serial.println(noteNum);
  Serial.print("Velocity: ");
  Serial.println(velocity);
}

void controlChange (byte ccNum, byte val) {
  Serial.print("Control Number: ");
  Serial.println(ccNum);
  Serial.print("Value: ");
  Serial.println(val);
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    if (rx.header != 0) {

      if (rx.byte1 == 144) { //NoteOn messages
          Serial.println("Received NoteOn Message on Channel 1"); 
          playNote(rx.byte2, rx.byte3);
      }

      if (rx.byte1 == 176) {//ControlChange messages
          Serial.println("Received ControlChange Message: "); 
          controlChange(rx.byte2, rx.byte3);
      }

      
      Serial.print("Received: ");
      Serial.print("Header: ");
    //  Serial.print(rx.header);
      Serial.print(rx.header, DEC);
      Serial.print("- Data 1: ");
      Serial.print(rx.byte1, DEC);
      Serial.print("- Data 2: ");
      Serial.print(rx.byte2, DEC);
      Serial.print("- Data 3: ");
      Serial.println(rx.byte3, DEC);
    }
  } while (rx.header != 0);
}
