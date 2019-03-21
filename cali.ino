int i, high = 180, low = 0; 

const int irPins[8] = {21,20,19,18,17,16,15,14};

int irSensors = B00000000;

//for motor
const byte in1p=10;//motor pins
const byte in1n=11;
const byte in2p=12;
const byte in2n=13;
const byte enable=9;
int pwm = 60;


void setup() {
  for(i=21; i>13 ; i--)
  {
    pinMode(i,INPUT);
  }
  
  Serial.begin(9600);
  
  pinMode(in1p,OUTPUT);
  pinMode(in2p,OUTPUT);
  pinMode(in1n,OUTPUT);
  pinMode(in2n,OUTPUT);
  pinMode(enable,OUTPUT);
  digitalWrite(enable,HIGH);
  analogWrite(in1p,low);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,low);
}
void loop()
{

}
