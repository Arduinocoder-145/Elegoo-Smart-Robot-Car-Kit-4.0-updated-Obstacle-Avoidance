#include <Servo.h>

const int MotoL=5;
const int MotoR=6;
const int RichtL=7;
const int RichtR=8;
const int STBY=3;
const int trig=13;
const int echo=12;



Servo myServo;

void setup() {
  // put your setup code here, to run once:
pinMode(MotoL, OUTPUT);
pinMode(MotoR, OUTPUT);
pinMode(RichtL, OUTPUT);
pinMode(RichtR, OUTPUT);
pinMode(STBY, OUTPUT);
pinMode(trig, OUTPUT);
pinMode(echo, INPUT);
pinMode(A0, INPUT);
pinMode(A1, INPUT);
pinMode(A2, INPUT);

digitalWrite(STBY, HIGH);
myServo.attach(10);
myServo.write(90);
Serial.begin(9600);
}


long ultraschall(){
digitalWrite(trig, LOW);
delayMicroseconds(2);
digitalWrite(trig, HIGH);
delayMicroseconds(10);
digitalWrite(trig, LOW);

long duration=pulseIn(echo, HIGH);
long distance=duration*0.034/2;
return distance;

}



void loop() {
  // put your main code here, to run repeatedly:
long messen=ultraschall();
delay(50);
Serial.print(messen);
Serial.println("cm");
delay(50);
if(messen>23){
  digitalWrite(RichtL, HIGH);
digitalWrite(RichtR, HIGH);
analogWrite(MotoL, 110);
analogWrite(MotoR, 110);

}if(messen<23&&messen<15){
  delay(50);

   digitalWrite(RichtL, LOW);
   digitalWrite(RichtR, LOW);
   analogWrite(MotoL, 0);
   analogWrite(MotoR, 0);
   delay(130);
   analogWrite(MotoL, 120);
   analogWrite(MotoR, 120);
delay(600);
digitalWrite(RichtL, LOW);
   digitalWrite(RichtR, HIGH);
   analogWrite(MotoL, 60);
   analogWrite(MotoR, 120);
  delay(500);

}if(messen<23&&messen>15){
  analogWrite(MotoL, 0);
  analogWrite(MotoR, 0);
  delay(80);
  digitalWrite(RichtL, HIGH);
   digitalWrite(RichtR, LOW);
   analogWrite(MotoL, 120);
   analogWrite(MotoR, 60);
  delay(160);
    for(int drehen=0; drehen<180; drehen+=1){

    myServo.write(drehen);
    delayMicroseconds(2000);

  }for(int drehen=180; drehen>0; drehen-=1){

    myServo.write(drehen);
    delayMicroseconds(2000);

    
  }delay(90);
  myServo.write(90);
}


if(messen<56){
  digitalWrite(RichtL, HIGH);
  digitalWrite(RichtR, HIGH);
  analogWrite(MotoL, 77);
  analogWrite(MotoR, 110);
}if(messen<36){
  digitalWrite(RichtL, HIGH);
  digitalWrite(RichtR, HIGH);
  analogWrite(MotoL, 63);
  analogWrite(MotoR, 125);
}if(messen<27){
  digitalWrite(RichtL, HIGH);
  digitalWrite(RichtR, HIGH);
  analogWrite(MotoL, 54);
  analogWrite(MotoR, 140);
}
}
