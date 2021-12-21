#include &lt;Wire.h&gt; // Incluindo a biblioteca para realizar a comunicação I2C
bool LED_estado;       // Variável  do tipo boleana que aramazena o estado no LED que o mestre irá enviar
 
void setup() {       //Função de Configuração Inicial
  Wire.begin();      // Inicia a comunicação I2C
}

void loop() { //Função de Repetição Infinita
  Wire.beginTransmission(0x08);   // Estamos iniciando a comunicação com o escravo no endereço 0x08
  Wire.write(LED_estado);         // Estamos enviando para o escravo o estado do LED que queremos
  Wire.endTransmission();         // Encerrando a comunicação com o escravo
  LED_estado = !LED_estado;       // Alteramos o estado do LED para o próximo envio de dados.
  delay(800);                     // Atraso de 800 milisegundos
}
