//Árvore de natal
int interruptor = 12, estado, l1 = 2, l2 = 4, l3 = 7, l4 = 8;
void setup(){
    Serial.begin(9600);
	pinMode(interruptor,INPUT);
	pinMode(l1,OUTPUT);
  	pinMode(l2,OUTPUT);
  	pinMode(l3,OUTPUT);
  	pinMode(l4,OUTPUT);
}

void loop(){
    estado = digitalRead(interruptor);
    Serial.println(estado);
    
    if(estado == 0){
        digitalWrite(l1, HIGH);
        digitalWrite(l2, HIGH);
        digitalWrite(l3, HIGH);
        digitalWrite(l4, HIGH);
        delay(1500);
        digitalWrite(l1, LOW);
        digitalWrite(l2, LOW);
        digitalWrite(l3, LOW);
        digitalWrite(l4, LOW);
        delay(1500);
    }else{
        digitalWrite(l1, HIGH);
        delay(500);
        digitalWrite(l1, LOW);
        digitalWrite(l2, HIGH);
        delay(500);
        digitalWrite(l2, LOW);
        digitalWrite(l3, HIGH);
        delay(500);
        digitalWrite(l3, LOW);
        digitalWrite(l4, HIGH);
        delay(500);
        digitalWrite(l4, LOW);
    }
}
