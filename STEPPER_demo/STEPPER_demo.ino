#include <Wire.h>
#include <Adafruit_MotorShield.h>
Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *stepper = AFMS.getStepper(200, 1); // m1/m2 or m3/4

// move Voltage Knob on Variable Power supply to 4 V and set current knob halfway


// wiring: 

// on arduino      on stepper motor 
// M1 (top)    --> Blue 
// M1 (bottom) --> Red
// M2 (top)    --> Green 
// M2 (bottom) --> Black 


void setup() {
  Serial.begin(9600); // baud rate (for viewing serial output, good for debuggings)
  AFMS.begin(); // initialize motor
  stepper->setSpeed(1); // 0 - 255, controls power delivered to motor, 
}
void loop() {
  Serial.println("Forward 200 steps");
  stepper->step(200, FORWARD, SINGLE); // 360 deg / 1.8 deg per step = 200 steps for 1 revolution 
  delay(1000); // wait  1000ms = 1 sec
  Serial.println("Backward 200 steps");
  stepper->step(200, BACKWARD, SINGLE);
  delay(1000); // wait 1 sec
}
