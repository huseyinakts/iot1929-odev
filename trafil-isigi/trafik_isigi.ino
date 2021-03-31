void setup() {
  
  pinMode (2 , OUTPUT);
  pinMode (3 , OUTPUT);
  pinMode (4 , OUTPUT);
  
}

void loop() {
 
  digitalWrite(4,1);
  delay(8000); 
  digitalWrite(3,1);
  delay(2000); 
  digitalWrite(4,0);
  delay(0); 
  digitalWrite(3,0);
  delay(0);
  digitalWrite(2,1);
  delay(5000);
  digitalWrite(2,0);
  delay(0);
  
}
