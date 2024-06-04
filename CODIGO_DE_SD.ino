#include "Ultrasonic.h" //INCLUSÃO DA BIBLIOTECA NECESSÁRIA PARA FUNCIONAMENTO DO CÓDIGO

const int echoPin = 5; //PINO DIGITAL UTILIZADO PELO HC-SR04 ECHO(RECEBE)
const int trigPin = 6; //PINO DIGITAL UTILIZADO PELO HC-SR04 TRIG(ENVIA)
const int motor1 = 12;
const int motor2 = 13;



Ultrasonic ultrasonic(trigPin,echoPin); //INICIALIZANDO OS PINOS DO ARDUINO

int distancia; //VARIÁVEL DO TIPO INTEIRO
String result; //VARIÁVEL DO TIPO STRING

void setup(){
  pinMode(echoPin, INPUT); //DEFINE O PINO COMO ENTRADA (RECEBE)
  pinMode(trigPin, OUTPUT); //DEFINE O PINO COMO SAIDA (ENVIA)
  pinMode(motor1, OUTPUT);
  pinMode(motor2, OUTPUT);
  Serial.begin(9600); //INICIALIZA A PORTA SERIAL
  }

//MÉTODO RESPONSÁVEL POR CALCULAR A DISTÂNCIA
void hcsr04(){
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM UM PULSO BAIXO "LOW"
    delayMicroseconds(2); //INTERVALO DE 2 MICROSSEGUNDOS
    digitalWrite(trigPin, HIGH); //SETA O PINO 6 COM PULSO ALTO "HIGH"
    delayMicroseconds(10); //INTERVALO DE 10 MICROSSEGUNDOS
    digitalWrite(trigPin, LOW); //SETA O PINO 6 COM PULSO BAIXO "LOW" NOVAMENTE
    //FUNÇÃO RANGING, FAZ A CONVERSÃO DO TEMPO DE
    //RESPOSTA DO ECHO EM CENTIMETROS, E ARMAZENA
    //NA VARIAVEL "distancia"
    distancia = (ultrasonic.Ranging(CM)); //VARIÁVEL GLOBAL RECEBE O VALOR DA DISTÂNCIA MEDIDA
    result = String(distancia); //VARIÁVEL GLOBAL DO TIPO STRING RECEBE A DISTÂNCIA(CONVERTIDO DE INTEIRO PARA STRING)
    delay(0); //INTERVALO DE 500 MILISSEGUNDOS
 }

 void loop(){
  
  hcsr04(); // FAZ A CHAMADA DO MÉTODO "hcsr04()"
  Serial.print("Distancia "); //IMPRIME O TEXTO NO MONITOR SERIAL
  Serial.print(result); ////IMPRIME NO MONITOR SERIAL A DISTÂNCIA MEDIDA
  Serial.println("cm"); //IMPRIME O TEXTO NO MONITOR SERIAL

  if (distancia > 50){
    // Ligar motores
    digitalWrite(motor1, HIGH);
    digitalWrite(motor2, HIGH);
  } else {
    // desligar motores
    digitalWrite(motor1, LOW);
    digitalWrite(motor2, LOW);
  }
}
