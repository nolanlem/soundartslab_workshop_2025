// Simple Arduino code to demonstrate a stepper motor with EasyDriver

// Pin connections
const int STEP_PIN = 3;  // Step pin to EasyDriver STEP
const int DIR_PIN = 2;   // Direction pin to EasyDriver DIR
// Optional: MS1 and MS2 for microstepping (connect to pins if using)

const int STEPS_PER_REV = 200;  // For full-step mode (1.8° stepper)
const int DELAY_MS = 5;         // Delay between steps (lower = faster; min ~1-2ms)

void setup() {
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  
  // Optional microstepping setup (uncomment and connect pins)
  // pinMode(4, OUTPUT);  // MS1
  // pinMode(5, OUTPUT);  // MS2
  // digitalWrite(4, LOW);
  // digitalWrite(5, LOW);  // Full steps
  
  Serial.begin(9600);
  Serial.println("Stepper Motor Demo with EasyDriver");
  Serial.println("Rotating clockwise, then counterclockwise");
}

void loop() {
  // Clockwise one revolution
  digitalWrite(DIR_PIN, HIGH);
  Serial.println("Clockwise");
  for (int i = 0; i < STEPS_PER_REV; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(STEP_PIN, LOW);
    delay(DELAY_MS);
  }
  delay(1000);  // Pause
  
  // Counterclockwise one revolution
  digitalWrite(DIR_PIN, LOW);
  Serial.println("Counterclockwise");
  for (int i = 0; i < STEPS_PER_REV; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(DELAY_MS);
    digitalWrite(STEP_PIN, LOW);
    delay(DELAY_MS);
  }
  delay(2000);  // Pause before repeat
}
