#include <Wire.h> 
const int dacAddress = 0x60; 
int led = 9; 
   void setup() 
               { 
                Serial.begin(9600); 
                Wire.begin(); 
                } 
    void loop() 
               { 
                int pwmvalue=analogRead(A0); 
                analogWrite(led,pwmvalue/4); 
                Serial.println(pwmvalue/4);  
                delay(10); 
                for (int i = 0; i < 360; i++) 
                { 
                int dacValue = map(sin(i * PI / 180) * 2047 + 2048, -2047, 4095, 0, 
4095); 
                Wire.beginTransmission(dacAddress); 
                Wire.write(64);   
                Wire.write(dacValue >> 4);   
                Wire.write((dacValue & 15) << 4);   
                Wire.endTransmission(); 
                delayMicroseconds(100); 
                } 
                }