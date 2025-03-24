#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Create a DC motor object on port M1 (use 1, 2, 3, or 4 depending on your wiring)
Adafruit_DCMotor *dcMotor = AFMS.getMotor(3); 

void setup() {
  Serial.begin(9600);           // Start serial communication
  AFMS.begin();                 // Initialize the motor shield
  dcMotor->setSpeed(150);       // Set speed (0 to 255, where 255 is max)
  Serial.println("DC Motor Initialized");
}

void loop() {
  Serial.println("Running Forward");
  dcMotor->run(FORWARD);        // Run the motor forward
  delay(2000);                  // Run for 2 seconds

  Serial.println("Running Backward");
  dcMotor->run(BACKWARD);       // Run the motor backward
  delay(2000);                  // Run for 2 seconds

  Serial.println("Stopped");
  dcMotor->run(RELEASE);        // Stop the motor
  delay(1000);                  // Stop for 1 second


//// uncomment this code (highlight and press cmd + /)
//  Serial.println("Running Forward");
//  dcMotor->setSpeed(255);
//  dcMotor->run(FORWARD);        // Run the motor forward
//  delay(2000);                  // Run for 2 seconds
//
//  Serial.println("Running Backward");
//  dcMotor->run(BACKWARD);       // Run the motor backward
//  delay(2000);                  // Run for 2 seconds
//
//  Serial.println("Stopped");
//  dcMotor->run(RELEASE);        // Stop the motor
//  delay(1000);                  // Stop for 1 second
}
