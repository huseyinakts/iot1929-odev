#include <Joystick.h>
Joystick_ Joystick;
#include <Servo.h>
Servo sg90;
Servo sg902;

#define Pot90 A0
void pot90(int deger1) {
  Joystick.setXAxis(deger1);
  Joystick.sendState();
}

#define Pot180 A1
void pot180(int deger2) {
  Joystick.setYAxis(deger2);
  Joystick.sendState();
}
void setup() { 
  
  Joystick.begin();
  sg90.attach(5);
  sg902.attach(6);
}
void loop() {
  
  int pot90deger = analogRead(Pot90);
  pot90(pot90deger);
  int servo_aci = map(pot90deger , 0 , 1023 , 0 , 90);
  sg90.write(servo_aci);
 
  int pot180deger = analogRead(Pot180);
  pot180(pot180deger);
  int servo_aci2 = map(pot180deger , 0 , 1023 , 0 , 180);
  sg902.write(servo_aci2);
}
