#include <SoftwareSerial.h>   // Incluimos la librería  SoftwareSerial  
SoftwareSerial BT1(2,3);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth
SoftwareSerial BT2(8,9);    // Definimos los pines RX y TX del Arduino conectados al Bluetooth

 
void setup()
{
  BT1.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  BT2.begin(9600);       // Inicializamos el puerto serie BT (Para Modo AT 2)
  
  Serial.begin(9600);   // Inicializamos  el puerto serie  
}
 
void loop()
{
  if(BT2.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    Serial.write(BT2.read());
  }
  if(BT1.available())    // Si llega un dato por el puerto BT se envía al monitor serial
  {
    BT2.write(BT1.read());
  }
 
  if(Serial.available())  // Si llega un dato por el monitor serial se envía al puerto BT
  {
     BT1.write(Serial.read());
  }
}
