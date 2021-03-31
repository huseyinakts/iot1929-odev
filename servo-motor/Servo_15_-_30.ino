#include<Servo.h>
Servo iot1929;

void setup()
{
  iot1929.attach(3);
}

void loop()
{
  for(int baslangic = 0 ; baslangic <= 180; baslangic = baslangic + 15 )
  {
   iot1929.write(baslangic);
    delay (500);}
    for(int baslangic=180; baslangic >=0; baslangic = baslangic - 30)
    {iot1929.write(baslangic);
     delay (500);}
}
