const int led = 13;
int a;

void liga(int num){
  digitalWrite(led, HIGH);   
  delay(num);                
  digitalWrite(led, LOW);    
}

void limparSerial() {
  while (Serial.available() > 0) {
    Serial.read();  
  }
}

void setup() {
  Serial.begin(9600);        
  pinMode(led, OUTPUT);      
}

void loop() {
  
  Serial.println("Digite um caractere:");
  limparSerial();
  while (Serial.available() <= 0);  
  char caractere = Serial.read();
  Serial.print("Caractere: ");
  Serial.println(caractere);
  delay(1000);

  Serial.println("Digite um número inteiro:");
  limparSerial();
  while (Serial.available() <= 0);  
  int inteiro = Serial.parseInt();
  Serial.print("Número inteiro: ");
  Serial.println(inteiro);
  delay(1000);

  Serial.println("Digite um número float:");
  limparSerial();
  while (Serial.available() <= 0);  
  float flutuante = Serial.parseFloat();
  Serial.print("Número float: ");
  Serial.println(flutuante);
  delay(1000);

  Serial.println("Digite uma string:");
  limparSerial();
  while (Serial.available() <= 0);  
  String texto = Serial.readStringUntil('\n'); 
  Serial.print("String: ");
  Serial.println(texto);
  delay(1000);

  unsigned int contador = 0;
  Serial.println("Contando pulsos...");
  limparSerial();
  while (contador < 10) {
    contador++;
    Serial.print("Contador: ");
    Serial.println(contador);
    delay(500);
  }

  unsigned long tempoInicio = millis();
  limparSerial();
  while (millis() - tempoInicio < 5000) {
    float tempoEmSegundos = (millis() - tempoInicio) / 1000.0;
    Serial.print("Tempo em segundos: ");
    Serial.println(tempoEmSegundos, 2);
    delay(500);
  }

  Serial.println("Digite um número para controlar o LED:");
  limparSerial();
  while (Serial.available() <= 0);  
  a = Serial.parseInt();
  if (a > 0) {
    Serial.print("Ligando o LED por ");
    Serial.print(a);
    Serial.println(" milissegundos.");
    liga(a);
  } else {
    Serial.println("Por favor, insira um número válido.");
  }
  delay(1000);
}
