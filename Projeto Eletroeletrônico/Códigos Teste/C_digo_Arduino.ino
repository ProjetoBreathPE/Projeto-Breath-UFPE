  float inspTime;             
  float PIP;
  float frequency;
  float sensibility;
  float pressure;
  char ventMode; //de string para char, pois enviar um único char para representar é mais rápido. Demanda menos tempo de execução da função.

void setup() {
  Serial.begin(115200, SERIAL_8N1); // SERIAL_8E1 significa palavra de 8 bits com 1 bit de paridade par (E de even) e 1 stop bit. A paridade serve para detecção de erros
  pinMode(A2, INPUT);

}

void loop() {
  //código em ASCII do valor de inspTime para que o raspberry saiba do que se trata esse valor
  PIP = analogRead(A2);
  ventMode = 'C';
  Serial.print("s,"); 
  Serial.print(inspTime);         //print no lugar de println para diminuir o tempo de comunicação. O ln adiciona mais um byte de recuo \r e outro de pular linha \n. Ou seja, 2 bytes a mais para cada print.
  Serial.print(',');
  Serial.print(PIP);
  Serial.print(',');
  Serial.print(frequency);
  Serial.print(',');
  Serial.print(sensibility);
  Serial.print(',');
  Serial.print(ventMode);
  Serial.println(",p");
  delay(1000);
}
