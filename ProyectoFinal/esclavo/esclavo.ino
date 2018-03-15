/*
  Colores del led:
  - Led rojo-> Ha fallado la SD al inicio
  - Led azul -> Ha fallado la cámara al inicio
  - Led verde -> se está cargando la imagen en la SD
*/

#include <SdFat.h>
SdFat SD;
#include <Time.h> //para poner títulos a las fotos según la fecha y hora
#include <Wire.h>
#include <Adafruit_VC0706.h>
#include <SoftwareSerial.h>

// for SD
#define chipSelect 10
#if ARDUINO >= 100
SoftwareSerial cameraconnection = SoftwareSerial(2, 3);
#else
NewSoftSerial cameraconnection = NewSoftSerial(2, 3);
#endif
Adafruit_VC0706 cam = Adafruit_VC0706(&cameraconnection);

void setup() {
#if !defined(SOFTWARE_SPI)
#if defined(__AVR_ATmega1280__) || defined(__AVR_ATmega2560__)
  if (chipSelect != 53) pinMode(53, OUTPUT); // CS on Mega
#else
  if (chipSelect != 10) pinMode(10, OUTPUT); // CS on Uno, etc.
#endif
#endif

  Serial.begin(9600);
  Wire.begin();

  if (!SD.begin(chipSelect)) {
    // Serial.println("No se reconoce modulo SD o la tarjeta. Abortamos programa.");
    EstablecerColor(255, 0, 0);
    return;
  }
  //else
  //Serial.println("[OK] SD");

  if (!cam.begin()) {
    EstablecerColor(0, 0, 255);

    // Serial.println("No se reconoce la camara. Abortamos programa.");
    return;
  }
  // else
  // Serial.println("[OK] CAMARA");

  seleccionaTamFoto(0);

  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(eventito); // register event

  setTime(19, 58, 00, 6, 11, 2014);
  //Serial.print("Fecha y hora del sistema configurada por defecto");
  //dameHora();


  Serial.println("Arduino esclavo configurado correctamente");
}
byte foto = 0;
byte fotosPorLlamada = 1;
void loop() {
  if (Serial.available()) {
    char opcion = Serial.read();
    if (opcion == '1')
      seleccionaTamFoto(0);
    else if (opcion == '2')
      seleccionaTamFoto(1);
    else if (opcion == '3')
      seleccionaTamFoto(2);
  }

  if (foto > 0) {
    foto--;
    tomarFoto();
  }

  delay(100);
}

void eventito(int howMany) {
  dameHora();
  byte opsion[howMany];
  byte indice = 1;
  opsion[0] = Wire.read();
  Serial.write(opsion[0]);
  while (Wire.available()) {
    opsion[indice] = Wire.read() - 48;
    //Serial.write(opsion[indice]);
    indice++;
  }

  switch (opsion[0]) {

    //tomar foto
    case 'e':
      Serial.println("\nEntro en e");
      foto = foto + fotosPorLlamada;

      break;
    //sincroniza la fecha
    case 'h':
      setTime(opsion[9] * 10 + opsion[10], opsion[11] * 10 + opsion[12], 00, opsion[7] * 10 + opsion[8], opsion[5] * 10 + opsion[6], opsion[1] * 1000 + opsion[2] * 100 + opsion[3] * 10 + opsion[4]);
      Serial.println("\nEntro en h");
      dameHora();
      break;
    //establece el núnmero de fotos que se hará por llamada a la cámara
    case 'q':
      fotosPorLlamada = opsion[1];
      break;

  }

}

void dameHora() {
  time_t t = now();
  Serial.print("\nFecha y hora del sistema actual: ");
  Serial.print(day(t));
  Serial.print(+ "/") ;
  Serial.print(month(t));
  Serial.print(+ "/") ;
  Serial.print(year(t));
  Serial.print( " ") ;
  Serial.print(hour(t));
  Serial.print(+ ":") ;
  Serial.print(minute(t));
  Serial.print(":") ;
  Serial.println(second(t));
}

void seleccionaTamFoto(byte i) {
  if (i == 2) {
    Serial.println("\nTam de foto grande seleccionado");
    if (cam.setImageSize(VC0706_640x480))       // Grande
      Serial.println("bien");
  }
  else if (i == 1) {
    Serial.println("\nTam de foto mediano seleccionado");
    if (cam.setImageSize(VC0706_320x240))       // Mediano
      Serial.println("bien");
  }
  else {
    Serial.println("\nTam de foto peque seleccionado");
    if (cam.setImageSize(VC0706_160x120))        // Pequeño
      Serial.println("bien");
  }

}

void tomarFoto() {

  if (! cam.takePicture()) {
    Serial.println("No se ha podido tomar la foto.");
  }
  else {
    Serial.println("Foto tomada!");

    char filename[19];
    time_t t = now();
    //año
    int aux = year(t);
    filename[0] = aux / 1000 + 48;
    filename[1] = (aux % 1000);
    filename[2] = filename[1] % 100;
    filename[3] = filename[2] % 10 + 48;
    filename[2] = filename[2] / 10 + 48;
    filename[1] = filename[1] / 100 + 48;
    //mes
    aux = month(t);
    filename[4] = aux / 10 + 48;
    filename[5] = aux % 10 + 48;
    //dia
    aux = day(t);
    filename[6] = aux / 10 + 48;
    filename[7] = aux % 10 + 48;
    //hora
    aux = hour(t);
    filename[8] = aux / 10 + 48;
    filename[9] = aux % 10 + 48;
    //minuto
    aux = minute(t);
    filename[10] = aux / 10 + 48;
    filename[11] = aux % 10 + 48;
    //segundo
    aux = second(t);
    filename[12] = aux / 10 + 48;
    filename[13] = aux % 10 + 48;
    //extension
    filename[14] = '.'; filename[15] = 'J'; filename[16] = 'P'; filename[17] = 'G'; filename[18] = '\0';

    File imgFile = SD.open(filename, FILE_WRITE);

    // Tamaño de las imagenes(frame) tomadas
    uint16_t jpglen = cam.frameLength();
    //Serial.print("Cargando ");
    //Serial.print(jpglen, DEC);
    //Serial.print(" byte imagen.");
    EstablecerColor(0, 255, 0);
    //int32_t time = millis();
    pinMode(8, OUTPUT);
    // Lectura de todos los datos
    byte wCount = 0; // Para contar el numero de escrituras
    while (jpglen > 0) {
      // Lectura de  32 bytes en un pulso;
      uint8_t *buffer;
      uint8_t bytesToRead = min(32, jpglen); // Cambia 32 a 64
      buffer = cam.readPicture(bytesToRead);
      imgFile.write(buffer, bytesToRead);
      if (++wCount >= 64) {
        //Serial.print('.');
        wCount = 0;
      }
      jpglen -= bytesToRead;
    }
    imgFile.close();
    //time = millis() - time;
    EstablecerColor(0, 0, 0);


    Serial.println("Hecho!");
    Serial.print("Imagen ");
    Serial.print(filename);
    Serial.println(" creada ");
    //Serial.print(time);
    //Serial.println(" ms");
  }
  //Necesita para crear nueva imagen
  cam.resumeVideo();
}

void EstablecerColor(int R, int G, int B) {
  analogWrite(7, 255 - R);
  analogWrite(6, 255 - G);
  analogWrite(5, 255 - B);

}


