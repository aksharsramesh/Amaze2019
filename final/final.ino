int i, high = 140, low = 0; 

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
}

void loop() {
  analogWrite(enable, pwm);
  scanX();
  check();
}

void check(){
  switch(irSensors){
    case B00000000: // on white paper 
     back();
     break;
     
     case B10000000: // leftmost sensor on the line
     left();
     break;
      
     case B01000000:
     left();
     break;
     
     case B00100000: 
     left();
     break;
     

     case B00010000: 
     left();
     break;
     
     case B00001000: 
     rightA();
     break;     

     case B00000100: 
     rightA();
     break;
     
     case B00000010: 
     rightA();
     break;
      
     case B00000001: 
     rightA();
     break;       
     
     case B11000000:
     left();
     break;
      
     case B01100000:
     left();
     break;

     case B00110000:
     left(); 
     break;
     
     case B00011000: 
     forward();
     break;          

     case B00001100:
     rightA();
     break; 

     case B00000110:
     rightA();
     break;   
     
     case B00000011:
     rightA();
     break;          
       
     case B11100000:
     left();   
     break;
      
     case B01110000:
     left();
     break;
     
     case B00111000:
     left();
     break;
     
     case B00011100:
     rightA();
     break;  
     
     case B00001110:
     rightA();
     break; 
    
     case B00000111:
     rightA();
     break;   
          
     case B11110000:
     left(); 
     break; 
     
     case B01111000:
     left();       
     break;
      
     case B00111100:
     forward();
     break;  
     
     case B00011110:
     rightA();
     break;  
     
     case B00001111:
     rightA();
     break;  
          
     case B11111000:
     left(); 
     break; 
     
     case B01111100:
     left(); 
     break;
     
     case B00111110:
     rightA();
     break;
     
     case B00011111:
     rightA();
     break;
           
     case B11111100:
     left(); 
     break; 
     
     case B01111110:
     forward();
     break;
     
     case B00111111:
     rightA();
     break;
     
    
     case B11111110:
     leftX(); 
     break; 
     
     case B01111111:
     rightX();
     break;  
     
     case B11111111:
      rightX();        
      break;  
   
    default:
      rightX();
      //forwardL();
  }
}

void forward()
{
  analogWrite(in1p, high);
  analogWrite(in2p,high);
  analogWrite(in1n,low);
  analogWrite(in2n,low);
}
void forwardL()
{
  analogWrite(in1p, high-40);
  analogWrite(in2p,high-40);
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
  analogWrite(in1n,high);
  analogWrite(in2p,high);
  analogWrite(in2n,low); 
}
void rightX()
{
  analogWrite(in1p,low);
  analogWrite(in1n,high+20);
  analogWrite(in2p,high+20);
  analogWrite(in2n,low); 
}
void rightA()
{
  analogWrite(in1p,low);
  analogWrite(in1n,high+15);
  analogWrite(in2p,high+15);
  analogWrite(in2n,low); 
}
void left()
{
  analogWrite(in1p,high);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,high); 
}
void leftX()
{
  analogWrite(in1p,high+20);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,high+20); 
}
void halt()
{
  analogWrite(in1p,low);
  analogWrite(in1n,low);
  analogWrite(in2p,low);
  analogWrite(in2n,low); 
}


void scanX(){
  for ( byte count = 0; count < 8; count++)
  {
    bitWrite(irSensors, count, !digitalRead(irPins[count]));
  } 
}
