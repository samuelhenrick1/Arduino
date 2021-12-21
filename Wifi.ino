#include <SoftwareSerial.h> //Chama a biblioteca SoftwareSerial
 
SoftwareSerial esp8266(2, 3); //Define como RX pino 2, TX pino 3

#define DEBUG true //Configura o depurador como verdadeiro
 
void setup() //Função de Configuração Inicial
{
  Serial.begin(9600); //Inicia monitor serial
  esp8266.begin(19200); //Inicia o módulo Wifi
  sendData("AT+RSTrn", 2000, DEBUG); // Reseta os dados contidos 
  //sendData("AT+CWJAP="SSID","SENHA="rn", 2000, DEBUG); // Conecta a rede wireless
  delay(3000); //Define atraso de 3 segundos
  sendData("AT+CWMODE=1rn", 1000, DEBUG); //Configura o módulo como estação
  sendData("AT+CIFSRrn", 1000, DEBUG);   // Mostra o endereco IP
  sendData("AT+CIPMUX=1rn", 1000, DEBUG);   // Configura para multiplas conexoes
  sendData("AT+CIPSERVER=1,80rn", 1000, DEBUG);   // Inicia o web server na porta 80
}
 
void loop() //Função de Execução Infinita
{
  if (esp8266.available())   // Verifica se o ESP8266 esta enviando dados
  {
    if (esp8266.find("+IPD,")) //Estrutura de Decisão IF de "IPD"
    {
      delay(300); //Define atraso de 3 milisegundos
      int connectionId = esp8266.read() - 48; //Cria variável inteira de ID de Conexão conforme o controlador lê
 
      String webpage = "<head><meta http-equiv=""refresh"" content=""3"">"; //Cria variavel texto com comando em HTML
      webpage += "</head><h1><u>ESP8266 - Web Server</u></h1><h2>Porta"; //Continuação do STRING + HTML
      webpage += "Digital 8: "; //Continuação do STRING + HTML
      int a = digitalRead(8); //Verifica o pino 8 
      webpage += a;//Continuação do STRING + HTML
      webpage += "<h2>Porta Digital 9: ";//Continuação do STRING + HTML
      int b = digitalRead(9); //Verifica o pino 9
      webpage += b;//Continuação do STRING + HTML
      webpage += "</h2>";//Continuação do STRING + HTML
 
      String cipSend = "AT+CIPSEND=";  //Variavel do tipo texto de envio de pacote de dados
      cipSend += connectionId; //Envia o ID da conexão
      cipSend += ","; //Envia o texto ","
      cipSend += webpage.length(); //Envia o texto da variável WebPage e o Tamanho/Largura da Pagina/Pacote
      cipSend += "rn"; // //Envia a senha para logar
 
      sendData(cipSend, 1000, DEBUG); //Depuração dos dados da conexão
      sendData(webpage, 1000, DEBUG); //Depuração das informações
 
      String closeCommand = "AT+CIPCLOSE=";
      closeCommand += connectionId; // Anexa ID da Conexão
      closeCommand += "rn"; //Anexa a senha do wifi
 
      sendData(closeCommand, 3000, DEBUG);
    }
  }
}
 
String sendData(String command, const int timeout, boolean debug)   // Envio dos comandos AT para o modulo
{
  String response = ""; //Variavel string (texto) chamada resposta
  esp8266.print(command); //Define impressão do comando do modulo Wifi
  long int time = millis(); //Define uma variavel numérica longa/inteira de tempo e milésimos
  while ( (time + timeout) > millis()) //Estrutura de Repetição que manipula Tempo e Tempo de Saida maior que o Milesimos do Controlador
  {
    while (esp8266.available()) //Repita isso enquanto o módulo estiver disponível
    {
      // O módulo possui dados, então exiba sua saída na janela serial.
      char c = esp8266.read(); // Leia o próximo caractere
      response += c; //Resposta recebe o caracter "C"
    }
  }
  if (debug) //Estrutura de Repetição do Módulo
  {
    Serial.print(response); //Imprimia resposta
  }
  return response; //Retorne resposta
}
