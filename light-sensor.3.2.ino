#include <Servo.h>



const int LDR=(A0);
int lightlevel = (0);
const int ;
int angle = 0;
Servo myServo;
const int delayt = 1000;

void runMotor(){
  angle = 0;
  myServo.write(angle);
  delay (2000);

  angle = 180;
  myServo.write(angle);
  delay (2000);
}


void setup() {
  // put your setup code here, to run once:
Serial.begin (9600); 

}


void loop() {
  // put your main code here, to run repeatedly:
  static int startlight= analogRead(LDR);
  lightlevel = analogRead(LDR);
  
  myServo.write(angle);
  
  Serial.print("startlight: ");
  Serial.println(startlight);
  delay(delayt);
  
  Serial.print ("light level");
  Serial.println(lightlevel);
  delay(delayt);
    
  
  if (lightlevel > startlight){
    angle = 180;
    Serial.print("angle");
    Serial.println(angle);
  }
  else {
    angle = 0;
    Serial.print("angle");
    Serial.println(angle);
  }



}
