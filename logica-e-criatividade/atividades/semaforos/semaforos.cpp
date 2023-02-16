//semaforos arduino
int ledVermelho=0, ledA=1, ledVerde=2, ledVermelho2=3, ledA2=4, ledVerde2=5; 
void setup(){
    pinMode(ledVermelho, OUTPUT); pinMode(ledVerde, OUTPUT); pinMode(ledA, OUTPUT); 
    pinMode(ledVermelho2, OUTPUT); pinMode(ledVerde2, OUTPUT); pinMode(ledA2, OUTPUT);
}

void loop(){
    digitalWrite(ledVermelho, HIGH);
  	digitalWrite(ledVerde2, HIGH);
    delay(5000); 
    digitalWrite(ledVermelho, LOW); 
  	digitalWrite(ledVerde2, LOW);
  
  	digitalWrite(ledA, HIGH);
  	digitalWrite(ledA2, HIGH);
  	delay(2000);
  	digitalWrite(ledA, LOW);
  	digitalWrite(ledA2, LOW);
  
  	digitalWrite(ledVerde, HIGH);
  	digitalWrite(ledVermelho2, HIGH);
  	delay(5000);
  	digitalWrite(ledVerde, LOW);
  	digitalWrite(ledVermelho2, LOW);
}
