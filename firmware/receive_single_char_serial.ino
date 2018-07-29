#include <SoftwareSerial.h>
#include <Keyboard.h>


char receivedChar;
boolean newData = false;
const byte rxPin = 8;
const byte txPin = 9;
unsigned long lastPressTime;
bool onStartPage = false;

SoftwareSerial mySerial(rxPin, txPin);

void setup() {

  pinMode(13, OUTPUT);
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

  // set the data rate for the SoftwareSerial port
  Serial.begin(9600);
  mySerial.begin(9600);
  //Serial.begin(9600);
  //Serial.println("<Arduino is ready>");

  Keyboard.begin();
}

void loop() {
  recvOneChar();
  
  showNewData();
  if (newData) {
  lastPressTime = millis();
  onStartPage=false;
  }
  if (((millis() - lastPressTime) > 10000) && !onStartPage){
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA");
      Keyboard.press(176);
      Keyboard.releaseAll();
      onStartPage = true;
  }
}

void recvOneChar() {
  if (mySerial.available() > 0) {
    receivedChar = mySerial.read();
    newData = true;
  }
}

void showNewData() {
  if (newData == true) {
//    Serial.print("This just in ... ");
//    Serial.write(receivedChar);
//    Serial.println("");

    switch(receivedChar){
      case 'a': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SPINE/BOOKSTORE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;

      case 'b': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)OPEN/SPACE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'c': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)PALCO");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'd': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)BOE>/BAR/DELL/OFFICINA/DEGLI/ESORDI");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'e': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/WORKSHOP");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'f':  
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/WORKSHOP");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'g':  
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/PROVE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'h': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)PUGLIA/WORKING");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'i': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/PROVE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'j': ;
      case 'k': ;
      case 'l': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)DINAMO/FILM");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'm': ;
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)BASS/CULTURE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'n': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/PROVE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'o': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/PROVE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'p': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)SALA/PROVE");
      Keyboard.press(176);
      Keyboard.releaseAll(); 
      break;
      
      case 'q': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)QUELLI/DEI/VOLANTINI");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'r': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)HACKERSPACE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 's': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)LA/SCUOLA/OPEN/SOURCE");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 't': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)TERRAZZA");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'u': 
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.press(215);
      Keyboard.print("^C)1");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case 'v': ;
      case 'w': ;
      case 'x': ;
      case 'y': ;
      
      case 'z':  
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)CICLOFFICINA");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      
      case '.': ;
      case ',': ;
    }
    newData = false;

  }
}
