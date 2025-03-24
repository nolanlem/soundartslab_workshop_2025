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
  dcMotor->run(FORWARD);
  for (int i = 0; i<20; i++){
  dcMotor->setSpeed(255);
  delay(100); // on time 
  dcMotor->setSpeed(0);
  delay(500); // off time 
  
  
  }

}
