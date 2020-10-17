#include<SoftwareSerial.h>
int motorA1 = 6; // Pin  2 of L293
int motorA2 = 5; // Pin  7 of L293
int motorB1 = 9; // Pin 15 of L293
int motorB2 = 10; // Pin 10 of L293
String state;
int v=255;
SoftwareSerial bt(0,1);

void setup() {

  Serial.begin(9600);
  bt.begin(9600);
  pinMode(motorA1, OUTPUT);
  pinMode(motorA2, OUTPUT);
  pinMode(motorB1, OUTPUT);
  pinMode(motorB2, OUTPUT);
  
}

void loop() { 

  if(bt.available()){
    state = bt.readString();
    
    if(state=="on"){
      analogWrite(motorA1, v); 
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, v); 
      analogWrite(motorB2, 0); 
    }
    
    if(state=="back"){
      analogWrite(motorA1, 0); 
      analogWrite(motorA2, v);
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, v); 
    }
    
    if((state=="right")||(state=="write")){
      analogWrite(motorA1, v); 
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, v); 
    }
    
    if(state=="left"){
      analogWrite(motorA1, 0); 
      analogWrite(motorA2, v);
      analogWrite(motorB1, v);
      analogWrite(motorB2, 0); 
    }
    
    if((state=="off")||(state=="of")){
      analogWrite(motorA1, 0); 
      analogWrite(motorA2, 0); 
      analogWrite(motorB1, 0); 
      analogWrite(motorB2, 0); 
    }
    
  }

}
