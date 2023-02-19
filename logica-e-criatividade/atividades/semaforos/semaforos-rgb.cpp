//semaforos arduino
int ledVermelho=2, ledVerde=7, ledAzul=4, ledVermelho2=8, ledVerde2=13, ledAzul2=12; 
void setup(){
	pinMode(ledVermelho, OUTPUT); pinMode(ledVerde, OUTPUT); pinMode(ledAzul, OUTPUT);
	pinMode(ledVermelho2, OUTPUT); pinMode(ledVerde2, OUTPUT); pinMode(ledAzul2, OUTPUT);
}

void loop(){
	digitalWrite(ledVermelho, HIGH);//vermelho
	digitalWrite(ledVerde2, HIGH);//verde
	delay(5000);

	digitalWrite(ledVerde, HIGH);//amarelo - vermelho verde
	digitalWrite(ledVermelho2, HIGH);//amarelo - verde vermelho
	delay(2000);

	digitalWrite(ledVermelho, LOW);//verde
	digitalWrite(ledVerde2, LOW);//vermelho
	delay(5000);

	digitalWrite(ledVermelho, HIGH);//amarelo
	digitalWrite(ledVerde2, HIGH);//amarelo
	delay(2000);

	digitalWrite(ledVermelho, LOW);
	digitalWrite(ledVerde, LOW);
	digitalWrite(ledVermelho2, LOW);
	digitalWrite(ledVerde2, LOW);  
}
