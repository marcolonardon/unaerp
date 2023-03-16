//medidor de luminosidade
int led1=2, led2=3, led3=4, led4=5, led5=6, ldr=A5, valor;

void setup(){
    Serial.begin(9600);
    pinMode(led1, OUTPUT);
    pinMode(led2, OUTPUT);
    pinMode(led3, OUTPUT);
    pinMode(led4, OUTPUT);
    pinMode(led5, OUTPUT);
}

void loop(){
    valor = map(analogRead(ldr), 1, 234, 0, 1023); 
    Serial.println(valor);
  
    if(valor == 0){
        digitalWrite(led1, 0);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
    }else if(valor < 200){
        digitalWrite(led1, 1);
        digitalWrite(led2, 0);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
    }else if(valor < 400){
        digitalWrite(led1, 1);
        digitalWrite(led2, 1);
        digitalWrite(led3, 0);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
    }else if(valor < 600){
        digitalWrite(led1, 1);
        digitalWrite(led2, 1);
        digitalWrite(led3, 1);
        digitalWrite(led4, 0);
        digitalWrite(led5, 0);
    }else if(valor < 800){
        digitalWrite(led1, 1);
        digitalWrite(led2, 1);
        digitalWrite(led3, 1);
        digitalWrite(led4, 1);
        digitalWrite(led5, 0);
    }else{
        digitalWrite(led1, 1);
        digitalWrite(led2, 1);
        digitalWrite(led3, 1);
        digitalWrite(led4, 1);
        digitalWrite(led5, 1);
    }
}