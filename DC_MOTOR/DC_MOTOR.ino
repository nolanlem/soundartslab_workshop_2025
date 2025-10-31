#include <Wire.h>
#include <Adafruit_MotorShield.h>

// Create multiple motor shield objects with different I2C addresses
// Default address is 0x60, we'll create 10 shields (40 motors total)
Adafruit_MotorShield AFMS1 = Adafruit_MotorShield(0x60);  // First shield
Adafruit_MotorShield AFMS2 = Adafruit_MotorShield(0x61);  // Second shield
Adafruit_MotorShield AFMS3 = Adafruit_MotorShield(0x62);  // Third shield
Adafruit_MotorShield AFMS4 = Adafruit_MotorShield(0x63);  // Fourth shield
Adafruit_MotorShield AFMS5 = Adafruit_MotorShield(0x64);  // Fifth shield
Adafruit_MotorShield AFMS6 = Adafruit_MotorShield(0x65);  // Sixth shield
Adafruit_MotorShield AFMS7 = Adafruit_MotorShield(0x66);  // Seventh shield
Adafruit_MotorShield AFMS8 = Adafruit_MotorShield(0x67);  // Eighth shield
Adafruit_MotorShield AFMS9 = Adafruit_MotorShield(0x68);  // Ninth shield
Adafruit_MotorShield AFMS10 = Adafruit_MotorShield(0x69); // Tenth shield

// Create arrays to hold all motor objects
Adafruit_DCMotor* motors[40];  // Array to hold all 40 motors

void setup() {
  Serial.begin(9600);           // Start serial communication
  
  // Initialize all motor shields
  AFMS1.begin();
  AFMS2.begin();
  AFMS3.begin();
  AFMS4.begin();
  AFMS5.begin();
  AFMS6.begin();
  AFMS7.begin();
  AFMS8.begin();
  AFMS9.begin();
  AFMS10.begin();
  
  // Initialize all motors
  // First shield motors (0-3)
  motors[0] = AFMS1.getMotor(1);
  motors[1] = AFMS1.getMotor(2);
  motors[2] = AFMS1.getMotor(3);
  motors[3] = AFMS1.getMotor(4);
  
  // Second shield motors (4-7)
  motors[4] = AFMS2.getMotor(1);
  motors[5] = AFMS2.getMotor(2);
  motors[6] = AFMS2.getMotor(3);
  motors[7] = AFMS2.getMotor(4);
  
  // Continue for all shields...
  // (Similar pattern for motors 8-39)
  
  // Set initial speed for all motors
  for(int i = 0; i < 40; i++) {
    motors[i]->setSpeed(150);
  }
  
  Serial.println("All DC Motors Initialized");
}

void loop() {
  // Motor 1 sequence
  Serial.println("Motor 1: Running Forward");
  dcMotor1->run(FORWARD);
  delay(300);
  dcMotor1->run(RELEASE);
  delay(300);

  // Motor 2 sequence
  Serial.println("Motor 2: Running Forward");
  dcMotor2->run(FORWARD);
  delay(300);
  dcMotor2->run(RELEASE);
  delay(300);

  // Motor 3 sequence
  Serial.println("Motor 3: Running Forward");
  dcMotor3->run(FORWARD);
  delay(300);
  dcMotor3->run(RELEASE);
  delay(300);

  // Motor 4 sequence
  Serial.println("Motor 4: Running Forward");
  dcMotor4->run(FORWARD);
  delay(300);
  dcMotor4->run(RELEASE);
  delay(300);
}
