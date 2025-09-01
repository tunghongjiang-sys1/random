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
    digitalWrite(4, HIGH); // first LED
    digitalWrite(5, HIGH); // second LED
    digitalWrite(6, HIGH); // third LED
    digitalWrite(7, HIGH); // fourth LED
    digitalWrite(8, HIGH); // fifth LED
    digitalWrite(9, HIGH); // sixth LED
    digitalWrite(10, HIGH); // seventh LED
    digitalWrite(11, HIGH); // eighth LED
    digitalWrite(12, HIGH); // ninth LED
  } else {
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
    digitalWrite(11, LOW);
    digitalWrite(12, LOW);
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
