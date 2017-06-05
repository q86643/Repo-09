#include <LiquidCrystal.h> // include the library code
LiquidCrystal lcd(12, 7, 5, 4, 3,13); // initialize interface pins

const byte ledPin=10;
const byte TrigPin = 8;
const byte EchoPin = 9;
long duration;

void setup()
{
Serial.begin(9600);
pinMode(TrigPin,OUTPUT);
pinMode(EchoPin,INPUT);
digitalWrite(ledPin,HIGH);
attachInterrupt(0,doEncoder,LOW);
}

void loop(){
if(LOW){
digitalWrite(ledPin,HIGH);
}
else{
digitalWrite(ledPin,LOW);
}
}

void doEncoder() 
{
  long cm;
digitalWrite(TrigPin,LOW);
delayMicroseconds(2);
digitalWrite(TrigPin,HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin,LOW);
delayMicroseconds(2);
duration = pulseIn(EchoPin,HIGH);
cm = duration/58;
if(cm>0)
{
  delay(2000);
  Serial.print( "Distance = ");
  Serial.print(cm);
  Serial.println("cm");
   lcd.clear();
   lcd.print("Distance = ");
   lcd.print(cm);
}

} 

