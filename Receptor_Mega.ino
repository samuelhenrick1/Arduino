#include <Adafruit_GFX.h>      //Carrega a biblioteca do display
#include <Adafruit_PCD8544.h>  //Carrega a biblioteca grafica do display
#include <VirtualWire.h> //Carrega a biblioteca do receptor
 
byte message[VW_MAX_MESSAGE_LEN];    // Cria uma variavel do tipo bytes com nome de "mensagem"  para armazenar as mensagens recebidas
byte msgLength = VW_MAX_MESSAGE_LEN; // Cria uma variavel do tipo bytes com nome de "tamanho da mensagem" para armazenar o tamanho das mensagens
 
// Pinagem do LCD :
// pin 8 - Serial clock out (SCLK)
// pin 9 - Serial data out (DIN)
// pin 10 - Data/Command select (D/C)
// pin 11 - LCD chip select (CS/CE)
// pin 12 - LCD reset (RST)

Adafruit_PCD8544 display = Adafruit_PCD8544(8, 9, 10, 11, 12); //Inicializa e seta os parametros do display
 

void setup() //Função de Configuração Inicial
{
  Serial.begin(9600); //Inicializa o monitor serial ao passo do tempo inserido
    vw_set_rx_pin(5); // Define o pino 5 do Arduino como entrada de dados do receptor
    vw_setup(2000);   // Bits por segundo
    vw_rx_start();    // Inicializa o receptor
 
  display.begin(); //Inicia o display
  display.setContrast(50); //Ajusta o contraste do display
  display.clearDisplay();   //Apaga o buffer e o display
  display.setTextSize(1);  //Seta o tamanho do texto
  display.setTextColor(BLACK); //Seta a cor do texto
  display.setCursor(0,0);  //Seta a posição do cursor
  display.print("Aguardando..."); //Exibe a pensagem aguardando no display
  display.display(); //Pede para exibir no display
  delay(2000); //Travamento de 2 segundos
}
 
void loop() //Função de repetição infinita
{
uint8_t message[VW_MAX_MESSAGE_LEN];    //Prepara mensagem
uint8_t msgLength = VW_MAX_MESSAGE_LEN;  //Prepara o tamanho da mensagem
 
  display.setCursor(0, 0);  //Seta a posição do cursor no display
    if (vw_get_message(message, &msgLength)) // Estrutura de Decisão e Verificação de tem algum bloqueio no "get" message
    {
        Serial.print("Recebido: "); //Se tiver tudo okay, acusará no display como recebido
        display.clearDisplay();   //Apaga o buffer e o display
        for (int i = 0; i < msgLength; i++) //Estrutura de Repetição enquanto for menor que o tamanho da mensagem, faça ao passo de 1 e 1
       {
          Serial.write(message[i]); //Escreva mensagem recebida no serial
          display.write(message[i]);  //Mostre no display
          display.display(); //Retorne conforme configurado o display
       }
    Serial.println(); //Imprima pulando uma linha
    }
}
