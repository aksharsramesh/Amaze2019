int ir = 13, led = 10, a;
void setup() {
  
  pinMode(ir,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a= digitalRead(ir);
  Serial.println(a);
  if(a==1)
  {
    digitalWrite(led,HIGH);
  }
  else
  {
    digitalWrite(led,LOW);
  }
}
