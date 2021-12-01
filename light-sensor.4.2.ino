//trying to have the motor run as a function so it will be called and then go back to normal waiting for it to go again
#include <Servo.h>

const int servoPin = 9;
Servo myServo;
const int LDR = A0;
int input_val = 0;

void sweep () {
  myServo.write(180);
  Serial.println(180);
  delay (2000);
  myServo.write(0);
  delay (2000);
}

void setup()
{
  Serial.begin(9600);
  myServo.attach (servoPin); 

}

void loop()
{
//measures the light the first time it starts and does't change it
  static int startlevel = analogRead (LDR);

  int change = (input_val - startlevel);

  if (change > 10 ){
    Serial.print ("light has changed ");
    Serial.println (change);
    sweep();
  }
//sets the input vaule and sends to the serial monitor  
  input_val = analogRead(LDR);
  Serial.print("LDR Value is: ");
  Serial.println(input_val);
  delay(1000);
  


}
