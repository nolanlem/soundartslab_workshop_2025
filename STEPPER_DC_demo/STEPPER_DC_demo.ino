#include <Wire.h>
#include <Adafruit_MotorShield.h>

Adafruit_MotorShield AFMS = Adafruit_MotorShield();
Adafruit_StepperMotor *stepper = AFMS.getStepper(200, 1); // Stepper on M1/M2
Adafruit_DCMotor *dcMotor = AFMS.getMotor(3);             // DC motor on M3

void setup() {
  Serial.begin(9600);
  AFMS.begin();
  stepper->setSpeed(2);     // Stepper speed in RPM
  dcMotor->setSpeed(150);   // DC motor speed (0–255)
}

void loop() {
  Serial.println("Stepper Forward, DC Forward");
  stepper->step(200, FORWARD, DOUBLE);
  dcMotor->run(FORWARD);
  delay(2000);

  Serial.println("Stepper Backward, DC Backward");
  stepper->step(200, BACKWARD, DOUBLE);
  dcMotor->run(BACKWARD);
  delay(2000);

  Serial.println("Stopping Both");
  dcMotor->run(RELEASE);
  delay(1000);
}
