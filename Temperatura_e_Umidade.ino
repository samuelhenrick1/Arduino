#include "DHT.h" //Chama a biblioteca DHT
#define DHTPIN A1 // Pino Analógico A1 onde conecta no sensor na porta 2 (Dados)
#define DHTTYPE DHT11 // Aqui define o tipo de sensor usado, no caso o DHT 11
 
DHT dht(DHTPIN, DHTTYPE); //Configura o sensor com o nome "DHT", onde ele faz referência ao PINO e ao TIPO do sensor descrito no código
 
void setup() // Função de Configuração Inicial
{
  Serial.begin(9600); //Monitor Serial defindo em bytes por segundo
  Serial.println("Teste do Sensor"); //Comando de "exibição" em LCD
  dht.begin(); //Inicializa o sensor
}
 
void loop() // Função de Execução Infinita
{
  float h = dht.readHumidity(); //Variável "H" do tipo float fará a leitura da umidade
  float t = dht.readTemperature(); //Variável "T" do tipo float fará a leitura da temperatura

  if (isnan(t) || isnan(h)) //Estutura de Condição com OU LÓGICO que resulta em verdadeiro se pelo menos um dos operandos é verdadeiro.
  {
    Serial.println("Failed to read from DHT"); //Exibe a mensagem de erro caso não verifique
  } 
  else
  {
    Serial.print("Umidade: "); //Exibe a mensagem "Umidade"
    Serial.print(h); //Exibe o valor da variável "H"
    Serial.print(" %t"); //Exibe o texto
    Serial.print("Temperatura: "); // Existe a mensagem "Temperatura"
    Serial.print(t); //Exibe o resultado da variável
    Serial.println(" *C"); //Exibe o texto
  }
}
