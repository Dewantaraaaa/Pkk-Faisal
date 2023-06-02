#include

// define the pins for stepper motors
#define X_STEP_PIN 2
#define X_DIR_PIN 3
#define X_ENABLE_PIN 4

#define Y1_STEP_PIN 6
#define Y1_DIR_PIN 7
#define Y1_ENABLE_PIN 8

#define Y2_STEP_PIN 10
#define Y2_DIR_PIN 11
#define Y2_ENABLE_PIN 12

// initialize the stepper library
Stepper stepperX(200, X_STEP_PIN, X_DIR_PIN);
Stepper stepperY1(200, Y1_STEP_PIN, Y1_DIR_PIN);
Stepper stepperY2(200, Y2_STEP_PIN, Y2_DIR_PIN);

// define the moisture sensor pins and solenoid valve pins
int moistureSensorPin1 = A0;
int moistureSensorPin2 = A1;
int moistureSensorPin3 = A2;

int solenoidValvePin1 = 5;

void setup() {
// set the enable pins as outputs
pinMode(X_ENABLE_PIN, OUTPUT);
pinMode(Y1_ENABLE_PIN, OUTPUT);
pinMode(Y2_ENABLE_PIN, OUTPUT);

// enable the motors
digitalWrite(X_ENABLE_PIN, LOW);
digitalWrite(Y1_ENABLE_PIN, LOW);
digitalWrite(Y2_ENABLE_PIN, LOW);

// set initial position of stepper x to 1 meter
stepperX.setSpeed(50);
stepperX.step(-200);

// set initial position of stepper y to 0
stepperY1.setSpeed(50);
stepperY2.setSpeed(50);

// set moisture sensor and solenoid valve pins as inputs/outputs
pinMode(moistureSensorPin1, INPUT);
pinMode(moistureSensorPin2, INPUT);
pinMode(moistureSensorPin3, INPUT);

pinMode(solenoidValvePin5, OUTPUT);

}

void loop() {
// move stepper x to position 0.5 meter
for(int i=0; i<100; i++) {
stepperX.setSpeed(50);
stepperX.step(1);
delay(10);
}

// move stepper y to position 1.5 meter with moisture check
for(int i=0; i<300; i++) {
stepperY1.setSpeed(50);
stepperY2.setSpeed(50);
stepperY1.step(1);
stepperY2.step(1);
delay(10);

if(i == 50 || i == 150 || i == 225) { // check moisture at specigic distance
int moisture1 = analogRead(moistureSensorPin1);
int moisture2 = analogRead(moistureSensorPin2);
int moisture3 = analogRead(moistureSensorPin3);

if(moisture1 < 500) { // if soil is dry, open solenoid valve
digitalWrite(solenoidValvePin5, HIGH);
delay(3000); // water for 3 seconds
digitalWrite(solenoidValvePin5, LOW);
}

if(moisture2 < 500) { // if soil is dry, open solenoid valve
digitalWrite(solenoidValvePin5, HIGH);
delay(3000); // water for 3 seconds
digitalWrite(solenoidValvePin5, LOW);
}

if(moisture3 < 500) { // if soil is dry, open solenoid valve
digitalWrite(solenoidValvePin5, HIGH);
delay(3000); // water for 3 seconds
digitalWrite(solenoidValvePin5, LOW);
}
}
}

// move stepper y back to position 0
for(int i=0; i<300; i++) {
stepperY1.setSpeed(50);
stepperY2.setSpeed(50);
stepperY1.step(-1);
stepperY2.step(-1);
delay(10);
}

// move stepper x back to position 1 meter
for(int i=0; i<100; i++) {
stepperX.setSpeed(50);
stepperX.step(-1);
delay(10);
}
}
