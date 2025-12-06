#include <SoftwareSerial.h> 
SoftwareSerial mySerial(2,3); int 
motorA1 = 8; // Pin  2 of L293 int 
motorA2 = 9; // Pin  7 of L293 int 
motorB1 = 10; // Pin 10 of L293 int 
motorB2 = 11; // Pin 14 of L293 int vel = 
255; // Speed Of Motors (0-255) char 
state = '0'; // Initialise Motors  
void setup() {  Serial.begin(9600); mySerial.begin(9600);// Initialize serial 
communication at 9600 bits per second  
// Set pins as outputs  
pinMode(motorA1, OUTPUT);  
pinMode(motorA2, OUTPUT); pinMode(motorB1, 
OUTPUT); pinMode(motorB2, OUTPUT);  
}   
void loop() {   
if(mySerial.available()>0)  
{ // Reads from bluetooth and stores its value state 
= mySerial.read();  
Serial.println(state);  
}  
if(state=='F'){ // Forward  // 
Serial.println(state);   
digitalWrite(motorA1, 1);  
digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 1);  
digitalWrite(motorB2, 0);  
/*delay(200); 
digitalWrite(motorA1, 0);  
digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 0); */  
}  
if(state=='B'){ // Reverse  
//   Serial.println(state);  
digitalWrite(motorA1, 0);  digitalWrite(motorA2, 1); digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 1);  /*delay(200); digitalWrite(motorA1, 0);  
digitalWrite(motorA2, 0);  digitalWrite(motorB1, 0);  digitalWrite(motorB2, 0); */  
}  
if(state=='R'){ // Right   
//  Serial.println(state);  
digitalWrite(motorA1, 1);  
digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 1);  
/*delay(200); digitalWrite(motorA1, 
0);  digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 0); */  
}  
if(state=='L'){ // Left   //  
Serial.println(state);  
digitalWrite(motorA1, 0);  
digitalWrite(motorA2, 1); 
digitalWrite(motorB1, 1); 
digitalWrite(motorB2, 0);  /*delay(200); 
digitalWrite(motorA1, 0);  
digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 0); */  
}   
if(state=='S'){ // Stop digitalWrite(motorA1, 
0);  digitalWrite(motorA2, 0);  
digitalWrite(motorB1, 0);  
digitalWrite(motorB2, 0);   
}  
} 
