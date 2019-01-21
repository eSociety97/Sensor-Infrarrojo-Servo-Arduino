/*************************************************Capitulo 7 - Sensor Infrarrojo********************************************************
*                                                                                                                                 *
*     En este septimo capitulo aprenderemos a utilizar el sensor Infrarrojo. Este es un dispositivo electronico optoelectrico     *                                                                      *
*  capaz de medir la radiacion electromagnetica infrarroja ya que todos los cuerpos emiten cierta cantidad de radiacion la cual   *
*  resulta ser invisible para nuestros ojos pero no para este sensor. El sensor esta compuesto por un Fototransistor que es el    *
*  encargado de recibir la luz infrarroja que rebota hacia abajo cuando encuentra un objeto, esta luz es emitida por un Diodo     *
*  LED Infrarrojo. A este conjunto se le llama optoacopladores.                                                                   *
*                                                                                                                                 *
*  Para lograr esto necesitaremos:                                                                                                *
*                                                                                                                                 *
*  -Placa arduino Uno                                                                                                             *
*  -1 Sensor Infrarrojo.                                                                                                          *
*  -1 Servomotor                                                                                                                  *
*  -Protoboard                                                                                                                    *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                                                 *
*                                                                                                              Facebook: ESociety *
*                                                                                                              GitHub: eSociety97 *
*                                                                                                                                 *
*                                                         #NuncaDejenDeCrear                                                      *
***********************************************************************************************************************************/ 



#include <Servo.h> //Importamos la libreria de Servo
int sensorIR = 12; //Declaramos la variable que usaremos para la entrada digital de nuestro sensor IR
Servo servo1; //Declaramos nuestro objeto servo

void setup(){ 
servo1.attach(6); // Declaramos el pin 6 como salida al servo
pinMode(12,INPUT); // Declaramos el pin 12 como entrada del sensor IR
servo1.write(0); //Posicionamos el servo en la posicion 0
}
void loop(){
int valor = digitalRead(12); //Declaramos la variable valor y le asignamos la lectura digital del sensor IR

if(valor == HIGH){ //Comparamos si el valor es un estado alto  
  while(valor == HIGH){ // Antirebote
  valor = digitalRead(12); 
  }
servo1.write(90);//Posicionamos el servo en la posicion de 90 grados
delay(3000); //Pausamos el programa por 3 segundos 
servo1.write(0); //Posicionamos el servo en la posicion de 0 grados 
}
  while(valor == LOW){ //Si no detecta nada solo leera el valor del sensor IR
  valor = digitalRead(12);
  }
}
