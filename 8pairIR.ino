int a, i;
void setup() {
  for(i=12; i>4 ; i--)
  {
    pinMode(i,INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  
  /*for(i=13; i>5 ; i--)
  {
    a= analogRead(i);
    Serial.print(a);
    Serial.print("__");
  }*/
  
  for(i=12; i>4 ; i--)
  {
    a= digitalRead(i);
    Serial.print(a);
    Serial.print("__");
  }
  Serial.println("end");
  delay(500);
}
