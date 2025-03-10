#include <Servo.h>

Servo m1; //Servos are named
Servo m2;
Servo m3;
Servo m4;

const int dugme1 = 12; // we introduced the pins of the buttons
const int dugme2 = 13;

int dugme1state = 0; // we specify the button variables.
bool dugme2state = false;

const int potpin1 = A0; //We introduced the potentiometer pins
const int potpin2 = A1;
const int potpin3 = A2;
const int potpin4 = A3;

int pot1value; // We specified the potentiometer variables.
int pot2value;
int pot3value;
int pot4value;

int pot1aci;
int pot2aci;
int pot3aci;
int pot4aci;

int m1PositionRecord[] = {0,0,0,0,0,0,0,0,0,0}; 
int m2PositionRecord[] = {0,0,0,0,0,0,0,0,0,0};
int m3PositionRecord[] = {0,0,0,0,0,0,0,0,0,0};
int m4PositionRecord[] = {0,0,0,0,0,0,0,0,0,0};

void setup() {
   m1.attach(3); // We introduced which pins we attach the servos 
   m2.attach(5);
   m3.attach(6);
   m4.attach(9);
  
   pinMode(dugme1, INPUT); //Record Mode
   pinMode(dugme2, INPUT); //Play Mode

   Serial.begin(9600); 
}

void loop() 
{   
   pot1value = analogRead(potpin1); //Read potentiometer value between 0-1023
   pot1aci = map(pot1value, 0, 1023,0, 180); // We mapped the value in the range of 0 -1023 to the range 0-140 on the pwm output.  

   pot2value = analogRead(potpin2);
   pot2aci = map(pot2value, 0, 1023, 0, 180);
  
   pot3value = analogRead(potpin3);
   pot3aci = map(pot3value, 0, 1023, 0, 180);
  
   pot4value = analogRead(potpin4);
   pot4aci = map(pot4value, 0, 1023, 0, 180);
  
   m1.write(pot1aci); // Values of the potentiometers to be printed to the servos.
   m2.write(pot2aci);
   m3.write(pot3aci);
   m4.write(pot4aci);
  
   if(digitalRead(dugme1) == HIGH) // increment array depend on how many time button1 pressed
{ 
     delay(250);     
dugme1state++;      
switch(dugme1state)
{      
       case 1:
        m1PositionRecord[0] = pot1aci;         
        m2PositionRecord[0] = pot2aci;
        m3PositionRecord[0] = pot3aci;
        m4PositionRecord[0] = pot4aci;
         Serial.println("Position 1 registered.");         
         break;
        
       case 2:
         m1PositionRecord[1] = pot1aci;
         m2PositionRecord[1] = pot2aci;
         m3PositionRecord[1] = pot3aci;
         m4PositionRecord[1] = pot4aci;
          Serial.println("Position 2 registered.");
          break;
         
       case 3:
         m1PositionRecord[2] = pot1aci;
         m2PositionRecord[2] = pot2aci;
         m3PositionRecord[2] = pot3aci;
         m4PositionRecord[2] = pot4aci;
          Serial.println("Position 3 registered.");
          break;
         
        case 4:
          m1PositionRecord[3] = pot1aci;
         m2PositionRecord[3] = pot2aci;
         m3PositionRecord[3] = pot3aci;
         m4PositionRecord[3] = pot4aci;
          Serial.println("Position 4 registered.");
          break;
         
        case 5:
         m1PositionRecord[4] = pot1aci;
         m2PositionRecord[4] = pot2aci;
         m3PositionRecord[4] = pot3aci;
         m4PositionRecord[4] = pot4aci;
          Serial.println("Position 5 registered.");
          break;
         
            case 6:
         m1PositionRecord[5] = pot1aci;
         m2PositionRecord[5] = pot2aci;
         m3PositionRecord[5] = pot3aci;
         m4PositionRecord[5] = pot4aci;
         Serial.println("Position 6 saved.");
         break;
        
           case 7:
         m1PositionRecord[6] = pot1aci;
         m2PositionRecord[6] = pot2aci;
         m3PositionRecord[6] = pot3aci;
         m4PositionRecord[6] = pot4aci;
         Serial.println("Position 7 registered.");
         break;
        
        case 8:
         m1PositionRecord[7] = pot1aci;
         m2PositionRecord[7] = pot2aci;
         m3PositionRecord[7] = pot3aci;
         m4PositionRecord[7] = pot4aci;
         Serial.println("Position 8 registered.");
         break;
        
           case 9:
         m1PositionRecord[8] = pot1aci;
         m2PositionRecord[8] = pot2aci;
         m3PositionRecord[8] = pot3aci;
         m4PositionRecord[8] = pot4aci;
         Serial.println("Position 9 registered.");
         break;
        
           case 10: 
         m1PositionRecord[9] = pot1aci;
         m2PositionRecord[9] = pot2aci;
         m3PositionRecord[9] = pot3aci;
         m4PositionRecord[9] = pot4aci;
         Serial.println("Position 10 registered.");
         break;
     }
   }

   if(digitalRead(dugme2) == HIGH) //Play Mode
{ 
     dugme2state = true;   
}
  
   if(dugme2state)
{ 
     for(int i = 0; i < 10; i++)
{ 
         m1.write(m1PositionRecord[i]); // it is 0 for the first time, it brings the 1st values we have changed from the sequence at the beginning of the code and prints them to the relevant servo.
delay(350); 
         m2.write(m2PositionRecord[i]);
         delay(350);
         m3.write(m3PositionRecord[i]);
         delay(350);
         m4.write(m4PositionRecord[i]);
                                                                                                                              
         Serial.println(" potentiometer values: ");  
         Serial.println(m1PositionRecord[i]);
         Serial.println(m2PositionRecord[i]);
         Serial.println(m3PositionRecord[i]);
         Serial.println(m4PositionRecord[i]);
         delay(350); // 
       }
   }
   delay(15); 
}
