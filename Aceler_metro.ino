#include<Wire.h> //Carrega a biblioteca Wire
#include <LiquidCrystal.h> //Carrega a biblioteca do LCD

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); // Inicializa o LCD
const int MPU=0x68;   //Endereco I2C do MPU6050
int AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ; //Variaveis do tipo inteira para armazenar valores dos sensores

void setup() //Função de Configuração inicial
{
  Serial.begin(9600);   //Inicializa o LCD
  lcd.begin(20, 4); //Define o tamanho o LCD (20 colunas e 4 linhas)
  Wire.begin(); //Inicializa a biblioteca Wire
  Wire.beginTransmission(MPU); //Começa a transmissão para a variável do I2C
  Wire.write(0x6B);  //Começa a gravação no endereço do I2C com o endereço escrito
   
  Wire.write(0);   //Inicializa o MPU-6050
  Wire.endTransmission(true); //Verifica o fim da transmissão se é verdadeira para começar
     
  lcd.setCursor(0,0);//Informacoes iniciais do display para mensagem abaixo Coluna 0 / Linha 0
  lcd.print("Acelerometro"); //Imprime mensagem na tela
  lcd.setCursor(0,2); //Informacoes iniciais do display para mensagem abaixo Coluna 0 / Linha 2
  lcd.print("Giroscopio"); //Imprime mensagem na tela
}

void loop() //Função de Repetição infinita
{
  Wire.beginTransmission(MPU);//Começa a transmissão para a variável do I2C 
  Wire.write(0x3B);  //Começa a gravação no endereço do I2C com o endereço escrito
  Wire.endTransmission(false); //Verifica se o fim da transmissão é falta, isto é, verdadeira
  Wire.requestFrom(MPU,14,true);   //Solicita os dados do sensor
  
  //Armazena o valor dos sensores nas variaveis correspondentes
  AcX=Wire.read()<<8|Wire.read();  //0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)     
  AcY=Wire.read()<<8|Wire.read();  //0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ=Wire.read()<<8|Wire.read();  //0x3F (ACCEL_ZOUT_H) & 0x40 (ACCEL_ZOUT_L)
  Tmp=Wire.read()<<8|Wire.read();  //0x41 (TEMP_OUT_H)   & 0x42 (TEMP_OUT_L)
  GyX=Wire.read()<<8|Wire.read();  //0x43 (GYRO_XOUT_H) & 0x44 (GYRO_XOUT_L)
  GyY=Wire.read()<<8|Wire.read();  //0x45 (GYRO_YOUT_H) & 0x46 (GYRO_YOUT_L)
  GyZ=Wire.read()<<8|Wire.read();  //0x47 (GYRO_ZOUT_H) & 0x48 (GYRO_ZOUT_L)
   
  //Envia valor X do acelerometro para a serial e o LCD
  Serial.print("AcX = "); Serial.print(AcX);
  lcd.setCursor(0,1); //Posiciona na Coluna 0 e Linha 1
  lcd.print("X="); //Imprime na tela o texto entre aspas
  lcd.print(AcX); //Imprime o valor da variavel
   
  //Envia valor Y do acelerometro para a serial e o LCD
  Serial.print(" | AcY = "); Serial.print(AcY);
  lcd.setCursor(7,1); //Posiciona na Coluna 7 e Linha 1
  lcd.print("Y=");//Imprime na tela o texto entre aspas
  lcd.print(AcY);//Imprime o valor da variavel
   
  //Envia valor Z do acelerometro para a serial e o LCD
  Serial.print(" | AcZ = "); Serial.print(AcZ);
  lcd.setCursor(13,1);//Posiciona na Coluna 13 e Linha 1
  lcd.print("Z=");//Imprime na tela o texto entre aspas
  lcd.print(AcZ); //Imprime o valor da variavel
   
  //Envia valor da temperatura para a serial e o LCD
  //Calcula a temperatura em graus Celsius
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);
  lcd.setCursor(13,0);//Posiciona na Coluna 13 e Linha 0
  lcd.print("T:");//Imprime na tela o texto entre aspas
  lcd.print(Tmp/340.00+36.53); //Imprime o valor da variavel
   
  //Envia valor X do giroscopio para a serial e o LCD
  Serial.print(" | GyX = "); Serial.print(GyX);
  lcd.setCursor(0,3); //Posiciona na Coluna 0 e Linha 3
  lcd.print("X=");//Imprime na tela o texto entre aspas
  lcd.print(GyX); //Imprime o valor da variavel
   
  //Envia valor Y do giroscopio para a serial e o LCD  
  Serial.print(" | GyY = "); Serial.print(GyY);
  lcd.setCursor(7,3);//Posiciona na Coluna 7 e Linha 3
  lcd.print("Y=");//Imprime na tela o texto entre aspas
  lcd.print(GyY); //Imprime o valor da variavel
   
  //Envia valor Z do giroscopio para a serial e o LCD
  Serial.print(" | GyZ = "); Serial.println(GyZ);
  lcd.setCursor(13,3);//Posiciona na Coluna 13 e Linha 3
  lcd.print("Z=");//Imprime na tela o texto entre aspas
  lcd.print(GyZ); //Imprime o valor da variavel
   
  delay(300);   //Aguarda 300 ms e reinicia o processo

}
