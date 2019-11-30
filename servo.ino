#include <Servo.h>
Servo servo;
int n=4; //no of drawers
int i; //to attach motor on respective pins
int a; //iterator for for loop
int up=100;//starting angle
int down=45;//stopping angle
int wait=3000; //wait time before the drawer goes back
char ch;//input data
//a--pin 8  b--pin 9
void setup() 
{
 
  servo.attach(8);
  servo.write(up);
  servo.attach(9);
  servo.write(90);
  servo.attach(10);
  servo.write(75);
  servo.attach(11);
  servo.write(103);
  
  Serial.begin(9600);
}

void loop()
{
  ch=Serial.read();
  {
  Serial.write(ch);
  if (ch=='a')
  {
    servo.attach(8);
    Serial.write('a');

   for(a=up; a >= 60; a=a-1)    
  {                                
    servo.write(a);           
    delay(25); 
  }

  delay(wait);
  
  for(a = 60; a <= up; a=a+2)    
  {                                
    servo.write(a);           
    delay(30); 
  }
  servo.detach();
  }
  
  else if (ch=='b')
  {
    servo.attach(9);
    Serial.write('b');

   for(a=90; a >= 30; a=a-2)    
  {                                
    servo.write(a);           
    delay(10); 
  }

  delay(wait);
  
  for(a = 30; a <= 90; a=a+1)    
  {                                
    servo.write(a);           
    delay(5); 
  }
   servo.detach();
  
  }
 
  else if (ch=='c')
  {
    Serial.write('c');
    servo.attach(10);

   for(a=75; a >= 30; a--)    
  {                                
    servo.write(a);           
    delay(15); 
  }

  delay(wait);
  
  for(a = 30; a <= 75; a++)    
  {                                
    servo.write(a);           
    delay(15); 
  }
   servo.detach();
  
  }
 
  
  else if (ch=='d')
  {
    servo.attach(11);

   for(a=103; a >= 56; a=a-1)    
  {                                
    servo.write(a);           
    delay(15); 
  }

  delay(wait);
  
  for(a = 56; a <= 103; a=a+1)    
  {                                
    servo.write(a);           
    delay(15); 
  }
   servo.detach();
  }
 
 
  }
  ch="";
}
