#include "DHT.h" //Chama a biblioteca DHT do Sensor de Umidade
#define dht_pin A5 //Pino DATA do Sensor ligado na porta Analogica A5
#define DHTTYPE DHT11  //Define o controlador de Umidade
 
DHT dht(dht_pin, DHTTYPE); //A bibioteca define a variário dht que irá trabalhar junto com o A5 + o Controlador
 
void setup() //Função de Configuração Inicial
{
  Serial.begin(9600); //Monitor Serial definido com 9,6 segundos de controle
  delay(1000);   // Aguarda 1 seg antes de acessar as informações do sensor
  dht.begin(); //Inicializa o Sensor
}
 
void loop() //Função de Execução Infinita 
{
  float h = dht.readHumidity(); //Variável "H" do tipo float fará a leitura da umidade
  float t = dht.readTemperature(); //Variável "T" do tipo float fará a leitura da temperatura
 
  // Mostra os valores lidos, na serial
    Serial.print("Umidade: "); //Exibe a mensagem "Umidade"
    Serial.print(h); //Exibe o valor da variável "H"
    Serial.print(" %t"); //Exibe o texto
    Serial.print("Temperatura: "); // Existe a mensagem "Temperatura"
    Serial.print(t); //Exibe o resultado da variável
    Serial.println(" *C"); //Exibe o texto
 
  delay(2000); //Define atraso de 2 segundos
}
