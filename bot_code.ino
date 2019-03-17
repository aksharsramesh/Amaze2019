int i, high = 128, low = 0; 

const int irPins[8] = {21,20,19,18,17,16,15,14};

int irSensors = B00000000;

//for motor
const byte in1p=12;
const byte in1n=11;
const byte in2p=10;
const byte in2n=8;
const byte enable=9;
int pwm = 50;


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
  analogWrite(enable, pwm);
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
  analogWrite(in1p, high);
  analogWrite(in2p,high);
  analogWrite(in1n,low);
  analogWrite(in2n,low);
}
void back()
{
  analogWrite(in1p,low);
  analogWrite(in1n,high);
  analogWrite(in2p,low);
  analogWrite(in2n,high);  
}
void right()
{
  analogWrite(in1p,low);
  analogWrite(in1n,low);
  analogWrite(in2p,high);
  analogWrite(in2n,low); 
}
void left()
{
  analogWrite(in1p,high);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,low); 
}
void halt()
{
  analogWrite(in1p,low);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,low); 
}


void scanD(){
  for ( byte count = 0; count < 8; count++)
  {
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
  } 
}
