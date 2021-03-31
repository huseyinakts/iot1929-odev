#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

#define led1 D2
#define led2 D3
#define led3 D4

char auth[] = "";
char ssid[] = "";
char pass[] = "";

BLYNK_WRITE(V1) {
  int pinValue = param.asInt();
  
  if (pinValue==1){
    Serial.println(" AÇIK");
    digitalWrite(led1,HIGH);
    delay(5000);
    digitalWrite(led2,HIGH);
    delay(5000);
    digitalWrite(led3,HIGH);
    delay(5000);
    }
  
  else {
      Serial.println(" KAPALI");
      digitalWrite(led1,LOW);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
    }
}

void setup() {
  Serial.begin(115200);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  Blynk.begin(auth, ssid, pass);  
}
void loop() {
  Blynk.run();
}
