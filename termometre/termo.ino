#include <dht.h>

dht DHT;

#define DHT11_PIN 6

void setup() {

 Serial.begin(9600);

}

void loop() {

 int okunanDeger = DHT.read11(DHT11_PIN);
  
  int  sic = DHT.temperature;
  int  nem = DHT.humidity;
 
  int K = (sic + 273);
  int F = ((sic *9)/5)+32;
    
  Serial.print("SICAKLIK Celcius: ");
  Serial.println(DHT.temperature);
  
  Serial.print("SICAKLIK Fahrenheit: ");
  Serial.println(F);
  
  Serial.print("SICAKLIK Kelvin: ");
  Serial.println(K);
  
  Serial.print("Nem: ");
  Serial.println (nem);
   Serial.print("\n");
    Serial.print("\n");
     Serial.print("\n");
      Serial.print("\n");
       Serial.print("\n");
        Serial.print("\n");
         Serial.print("\n");
  delay(1120);

}
