int a, i, rled = 4, bled = 3, blinled = 2, gled = 14; 
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
  check();
}

void check(){
  switch(irSensors){
    case B00000000: 
      green();
      break;
    case B00011000: 
      green();
      break;
    case B11111111:
      red();
      break;
    case B00001100: 
      blue();
      break;
    case B01100000: 
      blin();
      break;
    default:
      def();
  }
}

void red(){
  digitalWrite(rled,HIGH);
  delay(10);
  digitalWrite(rled,LOW);
}


void green(){
  digitalWrite(gled,HIGH);
  delay(10);
  digitalWrite(gled,LOW);
}


void blue(){
  digitalWrite(bled,HIGH);
  delay(10);
  digitalWrite(bled,LOW);
}


void blin(){
  digitalWrite(blinled,HIGH);
  delay(10);
  digitalWrite(blinled,LOW);
}


void def(){
  digitalWrite(15,HIGH);
  delay(10);
  digitalWrite(15,LOW);
}


void scanD(){
  for ( byte count = 0; count < 8; count++)
  {
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
  } 
}
