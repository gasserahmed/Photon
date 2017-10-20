/*
 case 1:Searching for light source
 case 2:Stop
 case 3:Moving
*/
int enA = 10;
int in1 = 9;
int in2 = 11;

int enB = 6;
int in3 = 3;
int in4 = 5;
int environment=0;


const int inp1 = A0;
const int inp2 = A1;
const int inp3 = A2;
int h_speed=100;
int l_speed=100;

void setup(){
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enB, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);

  pinMode(inp1,INPUT);
  pinMode(inp2,INPUT);
  pinMode(inp3,INPUT);

  searching();
  Serial.begin(9600);
}

void loop(){

  float x1 = analogRead(inp1);
  float x2 = analogRead(inp2);
  float x3 = analogRead(inp3);
  float diff1=abs(x1-x2);
  float diff2=abs(x1-x3);
  float diff3=diff1/diff2;
  float avg=(x1+x2+x3)/3;
  float diff4=avg-environment;
  

  if(diff3<0.15)//Right Eye
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, l_speed);
    analogWrite(enB, h_speed);

  }
  else if(diff3>3)//Left Eye
  {
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
    analogWrite(enA, l_speed);
    analogWrite(enB, h_speed);
  }
  else if(diff4>200){
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, l_speed);
    analogWrite(enB, l_speed);
  }
  else{
    analogWrite(enA, 0);
    analogWrite(enB, 0);
  }


  Serial.println(diff4);

  
}
void searching(){		
  int timer=4;
  float avg;
  while(timer>0)
  {
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
    analogWrite(enA, h_speed);
    analogWrite(enB, l_speed);


    float x1 = analogRead(inp1);
    float x2 = analogRead(inp2);
    float x3 = analogRead(inp3);
    avg=(x1+x2+x3)/3;
    environment=environment+avg;

    delay(1000);
    timer--;  
  }
  environment=environment/4;
}













