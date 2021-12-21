#include <Servo.h> //Chama a biblioteca Servo

Servo ServoMotor; //Chama o motor de ServoMotor e ativa a função servo no código

int pino_pot = A5; //Pino do potenciometro
int pino_motor = 6; //Pino de controle do motor
int valor; //Variável do tipo inteira chamada "valor"

void setup() // Função de Configuração Inicial
{
  Serial.begin(9600); //Define o uso do monitor serial com velocidade de 9,6 segundos
  ServoMotor.attach(pino_motor); //Degine a função servo no pino 6 que controla o motor
  Serial.println("Aguardando 5 segundos...."); //Exibição no monitor serial uma a mensagem entre aspas
  delay(5000); //Define atraso e espero de 5 segundos
}

void loop() //Função de Execução Infinita
{
  valor = analogRead(pino_pot);   //Le o valor do potenciometro
  valor = map(valor, 0, 1023, 0, 179);   //Converte o valor para uma faixa entre 0 e 179
  Serial.print("Potenciometro: ");   //Mostra o valor no serial monitor
  Serial.println(valor); //Imprime o valor do motor
  ServoMotor.write(valor);   //Envia o valor para o motor
}
