int a, i;
const int irPins[8] = {12,11,10,9,8,7,6,5};
int irSensors = B00000000;
void setup() {
  for(i=12; i>4 ; i--)
  {
    pinMode(i,INPUT);
  }
  Serial.begin(9600);
}

void loop() {
  scanD();  
}


void scanD(){
  for ( byte count = 0; count < 8; count++)
  {
    bitWrite(irSensors, count, digitalRead(irPins[count]));
  } 
}
/*for(i=12; i>4 ; i--)
  {
    a= digitalRead(i);
    Serial.print(a);
    Serial.print("__");
  }
  Serial.println("end");
  delay(500);*/
