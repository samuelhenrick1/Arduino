int botao = 7; //Define entrada 7 como variável do tipo inteira para o Botão
int led = 13; //Define entrada 13 como variável do tipo inteira para o LED
bool estadoLed = 0; //Cria uma variavel do estado de led booleano com posição inicial 
 
void setup() //Função de Configuração Inicial
{
  pinMode(botao, INPUT_PULLUP); // Define o pino do botao como entrada "INPUT" 
  pinMode(led, OUTPUT); //Define o LED como saida "OUTPUT"
}
 
void loop() //Função de Configuração de Repetição Infinita
{
  if(digitalRead(botao) == LOW) // Estrutura de Repetição que verifica se o botão for pressionado
  {
    estadoLed = !estadoLed; // Troca o estado do LED
    digitalWrite(led, estadoLed); //Escreve em LED na variavel Estado de Led
    while(digitalRead(botao) == LOW); //Enquanto o Botão pressionado for igual a BAIXO
    delay(100); //Atrase 0,1 segundo
  }    
}
