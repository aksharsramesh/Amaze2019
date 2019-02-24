int ir = 13, a;
void setup() {
  pinMode(ir,INPUT);
  Serial.begin(9600);
}

void loop() {
  a= digitalRead(ir);
  Serial.println(a);
  delay(1000);
}
