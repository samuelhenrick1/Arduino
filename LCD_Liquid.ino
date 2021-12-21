#include <LiquidCrystal.h>  //Define a biblioteca LiquidCrystal
 
LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Define os pinos que serão utilizados para ligação ao display
 
void setup() //Funão de Configuração
{
  lcd.begin(16, 2);   //Define o número de colunas e linhas do LCD

}
 
void loop() //Função de Execução Infinita
{
  lcd.clear();   //Limpa a tela
  lcd.setCursor(3, 0);   //Posiciona o cursor na coluna 3, linha 0;
  lcd.print("FILIPEFLOP"); //Envia o texto entre aspas para o LCD
  lcd.setCursor(3, 1); //Posiciona o cursor na coluna 3, linha 1;
  lcd.print(" LCD 16x2"); //Envia o texto entre aspas para o LCD
  delay(5000); //Segura a mensagem por 5 segundos no display
   
  for (int posicao = 0; posicao < 3; posicao++) //Estrutura de Repetição FOR
  {
    lcd.scrollDisplayLeft();   //Rolagem para a esquerda
    delay(300); //Espera 0,3 segundos
  }
   
  for (int posicao = 0; posicao < 6; posicao++) //Estrutura de Repetição FOR
  {
    lcd.scrollDisplayRight();   //Rolagem para a direita
    delay(300); //Espera 0,3 segundos
  }
}
