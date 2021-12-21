#include <Stepper.h> //Chama a Biblioteca Stepper do Motor de Passos

const int stepsPerRevolution = 500; //Define StepsPerRevolution como uma variavel do tipo inteira e constante (apenas leitura)
  
Stepper myStepper(stepsPerRevolution, 8,10,9,11);  //Inicializa a biblioteca utilizando as portas de 8 a 11 para 

void setup() // Função de Configuração Inicial
{ 
 myStepper.setSpeed(60);  //Determina a velocidade inicial do motor 
} 
  
void loop()  // Função de Execução Infinita
{ 
 for (int i = 0; i<=3; i++) //Estrutura de Repetição
 {
 myStepper.step(-512);  //Gira o motor no sentido horario a 90 graus
 delay(2000); //Define espera de 2 segundos
 }
  
 for (int i = 0; i<=2; i++) //Estrutura de Repetição
 {
 myStepper.step(682);  //Gira o motor no sentido anti-horario a 120 graus
 delay(2000);//Define espera de 2 segundos 
 }
 

 for (int i = 10; i<=60; i=i+10)//Estrutura de Repetição
 {
 myStepper.setSpeed(i);  //Gira o motor no sentido horario
 myStepper.step(40*i); //Aumenta a velocidade gradativamente
 }
 delay(2000); //Define espera de 2 segundos
}
