#include <Servo.h>


const int trigPin = 2;
const int echoPin = 3;
const int servoPin = 5;

double duration = 0;
double distance = 0;

Servo myServo;

void setup() {
  Serial.begin( 9600 );
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myServo.attach(servoPin);
  myServo.write(0);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);   
  
  distance = duration / 58.0;
    Serial.print("距離は ");
  Serial.print(distance);
  Serial.println(" cmです");
  
  if (distance <= 20 && distance > 0) {
    myServo.write(90);
  } else {
    myServo.write(0);

  }
}