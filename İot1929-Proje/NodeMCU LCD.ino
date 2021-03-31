//Mucitpilot 2020
//Blynk ve ESP8266 Kullanımı Örneği
#define BLYNK_PRINT Serial
//#ifndef UNIT_TEST
#include <Arduino.h>
//#endif

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>


const int trigPin = D2;
const int echoPin = D1;

float sure, uzaklik;
int dolulukorani;

// Blynk uygulamasından aldığınız anahtar(token)'ı buraya giriyoruz.
char auth[] = "wDbLMh2DhKz_2a-uXBw2ZtHoPpZ7S96i";

// Wifi ayarlarınız buraya girilecek.
// şifresiz ağlar içi şifreyi "" olarak bırakın.
char ssid[] = "Dsmart_129";
char pass[] = "70866187";

WidgetLCD lcd(V4);


BlynkTimer timer; //senkronu sağlamak için bir sayaç nesnesi oluşturuluyor.

/////////////////Blynk üzerinden ESP'ye komut gönderme/////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////

////////////////ESP'den BLYNK uygulamasına veri gönderme//////////////////////////////////////


// aşağıdaki fonksiyon ile sunucuya her 1 sn'de bir veri göndereceğiz.
// Uygulama kısmında gösterge nesnesinin özelliği PUSH olarak ayarlanacak.
// Çok sık aralıkla veri göndermeniz (max sn'de 10 veri) sistem tarafından engellendiği için tasarıma dikkat etmek gerek.
void veriGonder()
{
  dolulukorani = ((26-uzaklik)/26)*100;

    if ((dolulukorani > 0) && (dolulukorani < 100))
  {
    lcd.clear();
    lcd.print(2,0,"DOLULUK ORANI");
    lcd.print(7,1,"%");
    lcd.print(8,1,dolulukorani);
     
  }
  else
  {
    lcd.clear();
    lcd.print(2,0,"VERİ ALINIYOR");
  }
}
///////////////////////////////////////////////////////////////////////////////////////////////


void setup()
{
  
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass); //blynk'e bağlanıyoruz
  // Arzu edersebiz server'ı da detaylı olarak belirtebilirsiniz:
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 80);
  //Blynk.begin(auth, ssid, pass, IPAddress(192,168,1,100), 8080);

  timer.setInterval(1000L, veriGonder); //timer nesnesinin veri gönderme aralığını  ve hangi fonksiyon ile veri gönderileceğini tanımlıyoruz.

  pinMode(D2, OUTPUT);
  pinMode(D1, INPUT);
  

}

void loop()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  sure = pulseIn(echoPin, HIGH);
  uzaklik = (sure*.0343)/2;
  Serial.print("Uzaklık: ");
  Serial.println(sure);
  delay(100);

  if(uzaklik <= 5) {

    void steper(int komut);
    
  }

  
  Blynk.run(); //Burası mümkün olduğunca boş olmalı. Blynk'in çalışma mantığı genel olarak bu şekilde. Loop içinde başka işlemler olunca Blynk sunucusu ile olan senkron bozulabiliyor.
  timer.run(); //zamanlamayı kontrol ediyor.
}
