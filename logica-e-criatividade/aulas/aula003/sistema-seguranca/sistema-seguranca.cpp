//sistema de segurança
int ledVermelho=2, ledVerde=7, ledAzul=4, inter=8, status_inter, piezo=13, pir=12, status_pir; 
void setup(){
  	pinMode(pir, INPUT);
  	pinMode(piezo, OUTPUT);
  	pinMode(inter, INPUT);
    pinMode(ledVermelho, OUTPUT);
  	pinMode(ledVerde, OUTPUT);
  	pinMode(ledAzul, OUTPUT);
  
}

void loop(){
  	status_inter=digitalRead(inter);
    if (status_inter==1){
        digitalWrite(ledVerde, 1);
        digitalWrite(ledVermelho, 0);
        status_pir=digitalRead(pir);
    
        if(status_pir==1){
            while(status_inter==1){
                tone(piezo, 666);//valor especifico de hz
                delay(550);
                tone(piezo, 888);
                delay(300);
            }
        }
    }else{
        digitalWrite(ledVermelho, 1);
        digitalWrite(ledVerde, 0);
        noTone(piezo);//desliga o piezo
    }
}
