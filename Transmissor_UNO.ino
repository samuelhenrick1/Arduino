#include <VirtualWire.h> //Chama a biblioteca VirtuaWire que controla o módulo
 
String mensagem;//Cria uma variável STRING com o nome MENSAGEM
 
void setup() //Função de Configuração Inicial
{
  Serial.begin(9600); //Configura o Monitor Serial a Iniciar
  vw_set_tx_pin(8);  //Define o pino 8 do Arduino como pino de dados do transmissor
  vw_setup(2000);   // Bits per sec
  Serial.println("Digite o texto e clique em ENVIAR..."); //Exibe essa mensagem no Monitor Serial
}
 
void loop() //Função de Repetição Infinita
{
  char data[40]; //Cria uma variavel do tipo CHAR (Caracteres) com limite de até 40 caraters
  int numero; //Cria uma variavel do tipo inteira com o nome de números
  if (Serial.available() > 0) //Estrutura de Decisão de verificar se o Monitor Serial está ativo
  {
    numero = Serial.readBytesUntil (13,data,40); //Variavel número recebe do monitor a leitura do que foi digitado
    data[numero] = 0; = //Variavel data [posição do número] recebe o valor zero
    Serial.print("Enviado : "); //Exibe o texto "Enviado"
    Serial.print(data); //Exibe a informação enviada
    Serial.print(" - Caracteres : "); //Exibe os caracteres
    Serial.println(strlen(data)); //Exibe o tamanho da mensagem / caracteres enviados
    send(data);    //Envia a mensagem para o RF, como também aguarda o recebimento, com base na configuração da função SEND
  }  
} 
 
void send (char *message) //Função de enviar caracteres e mensagens usada na função acima
{
  vw_send((uint8_t *)message, strlen(message)); //Configura como a mensagem deve ser enviada
  vw_wait_tx(); // Aguarda o envio de dados
}
