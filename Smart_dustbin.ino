#include <Servo.h>

Servo servo;

// Pin definitions
const int trigPin = 5;
const int echoPin = 6;
const int servoPin = 7;
const int ledPin = 10;

// Variables
long duration;
int distance;
int avgDistance[3];

void setup() {
  Serial.begin(9600);
  servo.attach(servoPin);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);
  
  servo.write(0);  // Start with lid closed
  delay(500);
  servo.detach();
  Serial.println("Smart Dustbin Ready!");
}

int measureDistance() {
  // Trigger the ultrasonic pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(15);
  digitalWrite(trigPin, LOW);
  
  // Read the echo pulse
  duration = pulseIn(echoPin, HIGH);
  int dist = duration * 0.034 / 2;  // Convert to cm
  return dist;
}

void loop() {
  // Take 3 distance samples for smoother readings
  for (int i = 0; i < 3; i++) {
    avgDistance[i] = measureDistance();
    delay(10);
  }
  
  // Average the readings
  distance = (avgDistance[0] + avgDistance[1] + avgDistance[2]) / 3;
  
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Open lid if object is close
  if (distance < 50) {
    digitalWrite(ledPin, HIGH);  // Turn on LED to indicate detection
    servo.attach(servoPin);
    servo.write(90);             // Open lid
    delay(3000);
    servo.write(0);              // Close lid
    delay(500);
    servo.detach();
    digitalWrite(ledPin, LOW);   // Turn off LED
  }

  delay(200);
}
