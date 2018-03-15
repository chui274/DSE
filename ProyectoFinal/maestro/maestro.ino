#include <SoftwareSerial.h> //Librería que permite establecer comunicación serie en otros pins
#include <Wire.h>
#include <VirtualWire.h>

//Creamos un mensaje
//La constante VW_MAX_MESSAGE_LEN viene definida en la libreria
byte message[VW_MAX_MESSAGE_LEN];
byte messageLength = VW_MAX_MESSAGE_LEN;

char opcionB;

//Aquí conectamos los pins RXD,TDX del módulo Bluetooth.
SoftwareSerial BT(6, 5  ); //TX,RX.

void setup()
{
  Wire.begin(); // join i2c bus (address optional for master)
  BT.begin(9600); //Velocidad del puerto del módulo Bluetooth
  Serial.begin(9600); //Abrimos la comunicación serie con el PC y establecemos velocidad
  //Serial.println("Configuración establecida para arduino comunicador");
  vw_setup(2000);
  vw_rx_start();
  Serial.println("\nArduino maestro configurado guay");
}

void loop()
{

  //vemos si tenemos algo por bluetooth y actuamos en consecuencia
  // Serial.println("hola1");
  if (BT.available())
  {
    Serial.println("\nLectura bluetooth");
    opcionB = BT.read();
    //Serial.write(opcionB);
    Serial.println("");


    if (opcionB == 'e') {
      //transmitimos el dato por I2C
      Serial.write(opcionB);
      Wire.beginTransmission(8); // transmit to device #8
      Wire.write(opcionB);              // sends one byte
      Wire.endTransmission();    // stop transmitting
    }
    //entra aquí si empieza por un número (le pasan la fecha y hora)
    else if (opcionB == 'h') {
      byte sinc[13];
      sinc[0] = opcionB;
      //se transmite por I2C
      byte indice = 1;
      Serial.println("\nSe va a sincronizar una fecha y hora: ");
      //Serial.write(opcionB);
      delay(50);
      while (BT.available()) {
        opcionB = BT.read();
        Serial.write(opcionB);
        sinc[indice] = opcionB;
        indice++;
        //delay(50);
      }
      Serial.println("");
      Wire.beginTransmission(8); // transmit to device #8
      Wire.write(sinc, 13); // YYYYMMDDHHMM
      Wire.endTransmission();    // stop transmitting


    }
    //aquí se pasa el número de fotos que se hará por llamada
    else if (opcionB == 'q') {
      //Serial.println("entro en q");
      byte fotos[2];
      fotos[0] = opcionB;
      if (BT.available()) {
        opcionB = BT.read();
        fotos[1] = opcionB;
        Wire.beginTransmission(8);
        Wire.write(fotos, 2);
        Wire.endTransmission();
      }
    }
  }
  //  Serial.println("hola2");
  if (vw_get_message(message, &messageLength))
  {
    Serial.println("\nLectura radio");
    Serial.println("Recibe Mensaje");
    if (comparar("e") != 1) {
      Serial.println("Hola guapos!");
      opcionB = 'e';
      Wire.beginTransmission(8); // transmit to device #8
      Wire.write(opcionB);              // sends one byte
      Wire.endTransmission();    // stop transmittin
    }
  }

}
char comparar(char* cadena) {
  //Esta funcion compara el string cadena con el mensaje recibido.
  //Si son iguales, devuelve 1. Si no, devuelve 0.

  for (int i = 0; i < messageLength; i++)
  {
    if (message[i] != cadena[i])
    {
      return 1;
    }
  }

  return 0;
}

