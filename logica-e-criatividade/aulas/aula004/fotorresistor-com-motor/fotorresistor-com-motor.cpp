//fotorresistor com motor
int fot=A5, status_fot, motor=2; 
void setup(){
    Serial.begin(9600);
  	pinMode(motor, OUTPUT);
}

void loop(){
    status_fot=analogRead(fot);
  	Serial.println(status_fot);
    if (status_fot<500){
        digitalWrite(motor, 1);
    }else{
        digitalWrite(motor, 0);
    }
}