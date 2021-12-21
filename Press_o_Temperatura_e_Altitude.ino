#include <Wire.h> //Inclui biblioteca que permite comunicação com I2C
#include <U8glib.h> //Inclui biblioteca do LCD implementado nesse teste
#include <Adafruit_Sensor.h> //Inclui bibioteca do sensor Adafruit
#include <Adafruit_BMP280.h> //Inclui bibioteca do tipo do sensor da Adafruit

Adafruit_BMP280 sensor_bmp; // Adiciona função sensor_bmp existente na biblioteca Adafruit_BMP280
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_FAST); //Definições do display OLED SSD1306

void draw() //Função de Desenho em vista do Display Usado
{
  //Comandos graficos para o display devem ser colocados aqui
  u8g.setFont(u8g_font_8x13B); //Define fonte
  u8g.drawRFrame(0, 16, 128, 48, 4); //Define primeiro quadro
  u8g.drawRFrame(0, 0, 128, 16, 4); //Define segundo quadro
  u8g.drawStr(40, 13, "BMP280"); //Desenha esse texto como variavel String nos pontos declarados
  u8g.drawStr(10, 31, "Temp:      C");  //Desenha esse texto como variavel String nos pontos declarados
  u8g.drawCircle(93, 22, 2); //Desenha forma geométrica
  u8g.setPrintPos(55, 31); //Define os pontos do LCD onde terá a seguinte impressão
  u8g.print(sensor_bmp.readTemperature(), 1);    Mostra temperatura
  u8g.drawStr(10, 45, "Pres:"); //Desenha esse texto como variavel String nos pontos declarados
  u8g.setPrintPos(55, 45); //Define os pontos do LCD onde terá a seguinte impressão
  u8g.print(sensor_bmp.readPressure(), 1);  //Mostra a pressao (em hPa) 
  u8g.drawStr(10, 59, "Alt :       m"); //Desenha esse texto como variavel String nos pontos declarados
  u8g.setPrintPos(55, 59); //Define os pontos do LCD onde terá a seguinte impressão
  u8g.print(sensor_bmp.readAltitude(1013.25));//Mostra a altitude
}

void setup() //Função de Configuração Inicial
{
  Serial.begin(9600); //Monitor Serial definido em bytes por segundo
  Serial.println("Teste modulo BMP280"); //Comando de exibição no LCD

  
  if (!sensor_bmp.begin())//Verifica a conexão do sensor BMP280 com estrutura de condição
  {
    Serial.println("Sensor não encontrado. Verifique as conexoes!"); //Exibe a seguinte mensagem
    while (1); //Estrutura de Repetição enquanto "l" for verdadeiro, isto é, o sensor não é encontrado
  }

  //Display Oled em Estruturas de IF e ELSE IF
  if ( u8g.getMode() == U8G_MODE_R3G3B2 ) { //Inicia testes RGB e
    u8g.setColorIndex(255);// Inicia com a cor 255 do RGB (Branco)
  }
  else if ( u8g.getMode() == U8G_MODE_GRAY2BIT ) { //Inicia a escala de escala cinzenta
    u8g.setColorIndex(3); //Define como máxima intensidade
  }
  else if ( u8g.getMode() == U8G_MODE_BW ) {
    u8g.setColorIndex(1); //Habilita os pixels de indice
  }
  else if ( u8g.getMode() == U8G_MODE_HICOLOR ) { 
    u8g.setHiColorByRGB(255, 255, 255); //Habilita cores 255 255 255 do RGB (Branco)
  }
}

void loop() //Função de Execução Infinita
{
  
  u8g.firstPage(); //Chama a rotina de desenho na tela
  do //Faça
  {
    draw(); //Desenho a função DRAW
  }
  while ( u8g.nextPage() ); /Desenhe enquanto e proxima pagina / draw
  delay(10000); //Espere 10 segundos
}
