// L298N Single Motor Test

int IN1 = 9; // arduino output pin 9
int IN2 = 10; // arduino output pin 10
int ENA = 3; // PWM pin

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
}

void loop() {
  // Forward
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 200); // speed (0–255)
  delay(2000); // wait 2 seconds (remember 2000 ms = 2 sec)

  // Stop
  analogWrite(ENA, 0);
  delay(1000); // wait 1 second 

  // Backward
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  analogWrite(ENA, 200);
  delay(2000); // wait 2 seconds 

  // Stop
  analogWrite(ENA, 0);
  delay(1000); // wait 1 second
}
