#include <MIDI.h>

// MIDI settings
MIDI_CREATE_DEFAULT_INSTANCE();

// Motor control pins
const int motorPin1 = 9;  // Motor control pin 1
const int motorPin2 = 10; // Motor control pin 2

// Variables to store MIDI data
int currentVelocity = 0;
int currentNote = 0;

void setup() {
  // Initialize MIDI
  MIDI.begin(MIDI_CHANNEL_OMNI);
  
  // Set up motor control pins as outputs
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  
  // Initialize serial for debugging
  Serial.begin(9600);
}

void loop() {
  // Read MIDI messages
  if (MIDI.read()) {
    switch (MIDI.getType()) {
      case midi::NoteOn:
        currentNote = MIDI.getData1();
        currentVelocity = MIDI.getData2();
        controlMotor(currentVelocity);
        break;
        
      case midi::NoteOff:
        if (MIDI.getData1() == currentNote) {
          currentVelocity = 0;
          controlMotor(0);
        }
        break;
    }
  }
}

void controlMotor(int velocity) {
  // Map MIDI velocity (0-127) to motor speed (0-255)
  int motorSpeed = map(velocity, 0, 127, 0, 255);
  
  // Control motor direction and speed
  if (motorSpeed > 0) {
    analogWrite(motorPin1, motorSpeed);
    analogWrite(motorPin2, 0);
  } else {
    analogWrite(motorPin1, 0);
    analogWrite(motorPin2, 0);
  }
} 