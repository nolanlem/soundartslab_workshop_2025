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
  
  digitalWrite(ENA, HIGH); // speed (0–255)
  delay(100); // wait 2 seconds (remember 2000 ms = 2 sec)

  digitalWrite(ENA, LOW);
  delay(1000);
  
}
