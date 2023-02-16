//semaforo arduino
int ledVermelho=0, ledA=2, ledVerde=1; 
void setup(){
    pinMode(ledVermelho, OUTPUT);
    pinMode(ledVerde, OUTPUT);
    pinMode(ledA, OUTPUT); 
}

void loop(){
    digitalWrite(ledVermelho, HIGH); 
    delay(2000); 
    digitalWrite(ledVermelho, LOW); 
    
    digitalWrite(ledA, HIGH);
    delay(1000);
    digitalWrite(ledA, LOW); 
    
    digitalWrite(ledVerde, HIGH); 
    delay(2000);
    digitalWrite(ledVerde, LOW); 
}
