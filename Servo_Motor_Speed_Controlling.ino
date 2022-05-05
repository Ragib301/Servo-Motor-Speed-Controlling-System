#include <Servo.h> // The Servo Motor's library

Servo myServo;   // Declaring the Servo Motor's object
int pos1 = 0;    // A variable for later use

void setup() {
  myServo.attach(9);   // Attaching the servo motor to Digital Pin 9 (PWM)
}

void loop() {
  /* Function parameter description:

    moveTo(d,t);
     Here 'd' is The degree to which the servo motor will rotate.
     and 't' is the amount of time(in milliseconds) the servo motor rotate. */

  moveTo(180, 40);
  moveTo(0, 10);
  moveTo(150, 5);
  moveTo(20, 30);
}

void moveTo(int pos, int wait) {
  if (pos < 180 && pos > 0) {
    if (pos1 < pos) {
      for (int i = pos1; i <= pos; i++) {
        myServo.write(i);
        delay(wait);
      }
      pos1 = pos;
    }
    else if (pos1 > pos) {
      for (int i = pos1; i >= pos; i--) {
        myServo.write(i);
        delay(wait);
      }
      pos1 = pos;
    }
  }
}
