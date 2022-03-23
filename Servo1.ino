#include <Servo.h>

int potPin = 0;
int servoPin = 9;
Servo servo;

void setup() {
    servo.attach(servoPin);
}

void loop() {
    int reading = analogRead(potPin);
    int angle = map(reading, 0, 1023, 0, 180);
    servo.write(angle);
}
