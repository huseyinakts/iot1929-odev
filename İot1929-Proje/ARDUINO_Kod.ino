#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 
#define SCREEN_HEIGHT 64 

#define OLED_RESET     4 
#define SCREEN_ADDRESS 0x3C 
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT);

int Konum;
int Bekleme;
const int trigPin = 12;
const int echoPin = 13;
float sure, uzaklik, dolulukorani;

int durum=0;
int durum1=0;

void setup(){
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);

  for(int i=8; i<=11; i++){
  pinMode(i,OUTPUT);
  digitalWrite(i,LOW);
 }

  Konum=8;
  Bekleme=4;
}

void loop(){

  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  uzaklik = (sure*.0343)/2;
  dolulukorani = ((26-uzaklik)/26)*100;
  if (dolulukorani>2 && dolulukorani<99) {
    Serial.print("%");
    Serial.println(dolulukorani);
  
  display.clearDisplay();
  display.setTextSize(2,2);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(25,0);
  display.print("Doluluk");

  display.setTextSize(3,3);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(15,25);
  display.print((String)"%"+dolulukorani);
  
  display.display();

    
  }
  
  
  
  if(uzaklik<10 && uzaklik >0){
    solaDon (2000);
  }
  else if(uzaklik>=10){
      sagaDon (2500);
  }
}

void sagaDon (int Adim)
{
  if(durum1==2497){
    for (int i=0; i<Adim; i++)
  {

    delay(Bekleme);
    digitalWrite(Konum,LOW);
    KonumArttir();

  }

  }

  else if(durum1<1500){
    for (int i=0; i<Adim; i++)
  {
    digitalWrite(Konum,HIGH);
    delay(Bekleme);
    digitalWrite(Konum,LOW);
    KonumArttir();
    durum1++;
  }
  }
  durum=0;



}

void solaDon (int Adim)
{
  if(durum==1997){
   for (int i=0; i<Adim; i++)
  {

    delay(Bekleme);
    digitalWrite(Konum,LOW);
    KonumArttir();
  }

  }

   else if (durum<2000){
    for(int i=0; i<Adim; i++)
    {
      digitalWrite(Konum,LOW);
      delay(Bekleme);
      digitalWrite(Konum,HIGH);
      KonumAzalt();
      durum++;
    }
   }
     durum1=0;
}

void durdurma (int Adim)
{
  for (int i=0; i<Adim; i++)
  {

    delay(Bekleme);
    digitalWrite(Konum,LOW);
    KonumArttir();
    durum1=0;
    durum=0;
  }
}

void KonumArttir()
{
  Konum++;
  if (Konum==12) Konum=8;
}

void KonumAzalt()
{
  Konum--;
  if (Konum==7) Konum=11;
}
