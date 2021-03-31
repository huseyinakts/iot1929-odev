#include <Joystick.h>
Joystick_ Joystick;
#include <Servo.h>
Servo sg90;
Servo sg902;


#define Pot180 A1
void pot180(int deger2) {
  Joystick.setYAxis(deger2);
  Joystick.sendState();
}
void setup() { 
  
  Joystick.begin();

  sg902.attach(6);
}
void loop() {
  

 
  int pot180deger = analogRead(Pot180);
  pot180(pot180deger);
  int servo_aci2 = map(pot180deger , 0 , 1023 , 0 , 180);
  sg902.write(servo_aci2);
}
