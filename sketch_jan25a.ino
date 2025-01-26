#include <Servo.h>

const int trigPin = 13;
const int echoPin = 12;

float duration, distance;

Servo myServo;
int pos = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  Serial.begin(9600);
  myServo.attach(9);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration * .0343) / 2;
  Serial.print("distance: ");
  Serial.println(distance);
  delay(100);

  while (distance < 30) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance = (duration * .0343) / 2;
    Serial.print("distance: ");
    Serial.println(distance);
    delay(100);

    for (pos = 40; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 80; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 40; pos <= 80; pos += 1) { // goes from 0 degrees to 180 degrees
      // in steps of 1 degree
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }
    for (pos = 80; pos >= 40; pos -= 1) { // goes from 180 degrees to 0 degrees
      myServo.write(pos);              // tell servo to go to position in variable 'pos'
      delay(10);                       // waits 15ms for the servo to reach the position
    }


  }



}
