#include <Wire.h> //Define biblioteca Wire
#include <LiquidCrystal_I2C.h> //Define biblioteca LiquidCrystal com I2C

LiquidCrystal_I2C lcd(0x27,16,2); //Inicializa o display no endereco 0x27
 
void setup() //Função de Configuração inicial
{
 lcd.init(); //Inicia as configurações
}
 
void loop()
{
  lcd.setBacklight(HIGH); //Define luzes do LCD ligadas
  lcd.setCursor(0,0); //Posiciona o cursos na coluna 0, linha 0.
  lcd.print("Arduino e Cia !!"); //Exibe essa mensagem
  lcd.setCursor(0,1); //Posiciona o cursos na coluna 0, linha 1.
  lcd.print("LCD e modulo I2C"); //Exibe essa mensagem
  delay(1000); //Espera 1 segundo
  lcd.setBacklight(LOW); // Apaga as luzes
  delay(1000); // Espera 1 segundo
}
