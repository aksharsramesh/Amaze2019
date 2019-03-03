int ir1 = 13, ir2 = 12, led1 = 10, led2 = 11, a, b;

void l();
void r();

void setup() {
  
  pinMode(ir1,INPUT);
  pinMode(led1,OUTPUT);
  pinMode(ir2,INPUT);
  pinMode(led2,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a= digitalRead(ir1);
  b= digitalRead(ir2);
  Serial.println(a);
  Serial.println(b + 100);
  if((a==0 && b==1)==1)
    l();
  else if((b==0 && a==1)==1)
    r();
}

void l(){
  digitalWrite(led1,HIGH);
  delay(100);
  digitalWrite(led1,LOW);
}

void r(){
  digitalWrite(led2,HIGH);
  delay(100);
  digitalWrite(led2,LOW);
}
