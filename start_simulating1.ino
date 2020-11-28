#include<Servo.h>
Servo s;
int open;
int close;
int cont =0;
int lamp=12;
int button=2;
int state;
void setup()
{
  open= analogRead(0);
  close = analogRead(1);
  s.attach(10);
   pinMode(lamp, OUTPUT);
  pinMode(button, INPUT);
   Serial.begin(9600);
}

void loop()
{
  state= digitalRead(button);
  open= analogRead(0);
  close = analogRead(1);
  Serial.print(cont);
  Serial.println();
 if(state==0){
  if(open<100)
  {
    if(cont<5){
    s.write(0);
    delay(1000);
     s.write(90);
   delay(1000);
    cont++;
    }
    else
    {
     digitalWrite(lamp, HIGH);
      delay(500);
       digitalWrite(lamp, LOW);
       delay(500);
      
    }
  }
if(close<1000)
  {
    s.write(180);
    delay(1000);
     s.write(90);
     delay(1000);
  if(cont>0){
  cont--;
  }
  }
 }
  
}
