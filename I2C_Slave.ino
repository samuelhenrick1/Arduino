#include "Wire.h" //Chama as bibliotecas
bool LED_estado;     // Variável que aramazena o estado no LED que o mestre irá enviar
bool estado; //Variável do tipo booleana 
int  pino_LED = 4; //Declara o LED no pino 4 como variável do tipo inteira

void setup() { //Função de Configuração Inicial
  Wire.begin(0x08);                 // Iniciando a comunicação com o mestre através do endereço 0x08
  Wire.onReceive(Dado_Recebido);    // Quando o escravo receber algo no barramento, ele chama a função 'Dado_Recebido' 
  pinMode(pino_LED,OUTPUT);         // Colocando o LED como saida 
}

void loop() { //Função de Repetição Infinita
    delay(100); //Define atraso
}
 
void Dado_Recebido(int leitura) { //Função criada chamada Dados Recebidos com variavel leitura do tipo inteira
     estado = Wire.read();    // Lê os dados eviados
   if (estado == 1){ //Estrutura de Decisão se o valor do estado é 1 (Ligado ou Verdadeiro)
    digitalWrite(pino_LED,HIGH); //"Escreva" no LED como acesso.
  }
   else{ //Estrutura de Decisão caso a primeira seja inválida
    digitalWrite(pino_LED,LOW); //Apague o LED
  }
}
