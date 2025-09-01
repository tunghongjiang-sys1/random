// C++ code for HC-SR04 with LED
float distance = 0;  // use float instead of int

long readUltrasonicDistance(int triggerPin, int echoPin) {
  pinMode(triggerPin, OUTPUT);  
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);

  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin, LOW);

  pinMode(echoPin, INPUT);
  return pulseIn(echoPin, HIGH);
}

void setup() {
  pinMode(4, OUTPUT);     // LED pin
  Serial.begin(9600);
  digitalWrite(4, LOW);   // start OFF
}

void loop() {
  // Convert time to distance in cm
  distance = (0.034 * readUltrasonicDistance(2, 3)) / 2; 

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // LED ON if < 10 cm, otherwise OFF
  if (distance > 0 && distance < 10) {
    digitalWrite(4, HIGH);
  } else {
    digitalWrite(4, LOW);
  }

  delay(500);
}

///////////////////////////////////////

// C++ code
//
#include <Servo.h>

Servo servo_3;

void setup()
{
  servo_3.attach(3, 500, 2500);
}

void loop()
{
  servo_3.write(0);
  delay(2000); // Wait for 2000 millisecond(s)
  servo_3.write(90);
  delay(2000); // Wait for 2000 millisecond(s)
  servo_3.write(180);
  delay(2000); // Wait for 2000 millisecond(s)
  servo_3.write(90);
  delay(2000); // Wait for 2000 millisecond(s)
}
