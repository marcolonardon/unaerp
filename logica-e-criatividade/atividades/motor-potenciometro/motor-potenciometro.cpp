const int pot = A5;
int motor = 3, valor, valorMap, ledVerde=4, ledVermelho=6, ledAmarelo=5;

void setup(){
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
}

void loop(){
    valor = analogRead(pot);
    valorMap = map(valor, 0, 1023, 0, 255);
    analogWrite (motor, valorMap);

    if(valorMap < 100){
        digitalWrite(ledVerde, HIGH);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, LOW);
    }else if(valorMap > 149){
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, LOW);
        digitalWrite(ledVermelho, HIGH);
    }else{
        digitalWrite(ledVerde, LOW);
        digitalWrite(ledAmarelo, HIGH);
        digitalWrite(ledVermelho, LOW);
    }

    Serial.print(valor);
    Serial.print("-");
    Serial.println(valorMap);
}
