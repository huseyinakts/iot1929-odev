const int DC = 3;
const int pot = A0;
int motor;
int led = 2;

void setup() {

  Serial.begin(9600);
  pinMode ( DC ,OUTPUT);
  pinMode (led, OUTPUT);
}

void loop() {

  motor = analogRead(pot);
  motor = map(motor, 0 , 1023 , 0 , 255);
  analogWrite(DC, motor);
  Serial.print("RPM: ");
  Serial.println(motor);

  if(motor <= 90) {
    digitalWrite(led , HIGH);
  }
    else 
    digitalWrite(led , LOW);
  
}
