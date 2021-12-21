int pinoLed = 13; //Define LED no pino 13
int pinoSensorLuz = A0; //Define LDR na porta Analogica 0
int valorLuz = 0; //Define o valor inicial da variavel de Luz
 
void setup() //Função de Configuração Inicial
{
     pinMode(pinoLed,OUTPUT); //Define LED como saída
}
 
void loop() //Função de Execução Infinita
{
  valorLuz = analogRead(pinoSensorLuz); // Declara que valor de LUZ é a leitura da leitura do pino do Sensor de Luz      
  if(valorLuz<750) //Se o valor do sensor for inferior ao declarado
  {                
    digitalWrite(pinoLed,HIGH); //Defina LED como ALTO / Ligado
  }
  else //Senão for verdadeiro o IF, faça isso aqui então
  {                    
    digitalWrite(pinoLed,LOW); //Defina LED com BAIXO / Desligado
  }
  delay(10); //Espere por 10 milisegundos
}
