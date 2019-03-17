int i; 

const int irPins[8] = {12,11,10,9,8,7,6,5};

int irSensors = B00000000;

//for motor
const byte in1p=14; //motor pins
const byte in1n=15;
const byte in2p=16;
const byte in2n=17;
const byte enable=18;  //pwm pin
int pwm=50;


void setup() {
  for(i=12; i>4 ; i--)
  {
    pinMode(i,INPUT);
  }
  Serial.begin(9600);

  pinMode(in1p,OUTPUT);
  pinMode(in2p,OUTPUT);
  pinMode(in1n,OUTPUT);
  pinMode(in2n,OUTPUT);
}

void loop() {
  scanD();
  check();
}

void check(){
  switch(irSensors){
    case B00000000: 
      forward();
      break;
    case B00011000: 
      forward();
      break;
    case B11111111:
      halt();
      break;
    case B00001100: 
      right();
      break;
    case B01100000: 
      left();
      break;
    default:
      right();
  }
}

void forward()
{
  digitalWrite(in1p,HIGH);
  digitalWrite(in2p,HIGH);
  digitalWrite(in1n,LOW);
  digitalWrite(in2n,LOW);
}
void back()
{
  digitalWrite(in1p,LOW);
  digitalWrite(in1n,HIGH);
  digitalWrite(in2p,LOW);
  digitalWrite(in2n,HIGH);  
}
void right()
{
  digitalWrite(in1p,LOW);
  digitalWrite(in1n,LOW);
  digitalWrite(in2p,HIGH);
  digitalWrite(in2n,LOW); 
}
void left()
{
  digitalWrite(in1p,HIGH);
  digitalWrite(in1n,LOW);
  digitalWrite(in2p,LOW);
  digitalWrite(in2n,LOW); 
}
void halt()
{
  digitalWrite(in1p,LOW);
  digitalWrite(in1n,LOW);
  digitalWrite(in2p,LOW);
  digitalWrite(in2n,LOW); 
}


void scanD(){
  for ( byte count = 0; count < 8; count++)
  {
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
  } 
}
