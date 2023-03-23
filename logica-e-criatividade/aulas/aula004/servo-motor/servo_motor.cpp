//servo motor
#include <Servo.h>
int porta_servo=2, i; 
Servo motor;
void setup(){
    motor.attach(porta_servo);
}

void loop(){
    for(i=0; i<181; i++){
  	    motor.write(i);
        delay(15);
    }
    for(i=180; i>0; i--){
  	    motor.write(i);
        delay(15);
    }
    for(i=0; i<91; i++){
  	    motor.write(i);
        delay(15);
    }
    for(i=90; i>0; i--){
        motor.write(i);
        delay(15);
    }  
    for(i=0; i<181; i++){
  	    motor.write(i);
        delay(15);
    }
    for(i=180; i>91; i--){
  	    motor.write(i);
        delay(15);
    }
    for(i=90; i>181; i++){
        motor.write(i);
        delay(15);
    }
    for(i=180; i>0; i--){
        motor.write(i);
        delay(15);
    }
}