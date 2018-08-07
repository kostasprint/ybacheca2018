#include <SoftwareSerial.h>
#include <Keyboard.h>
#include <ADCTouch.h>

#define TRESHOLD 600

char receivedChar;
boolean newData = false;
const byte rxPin = 8;
const byte txPin = 9;
unsigned long lastPressTime;
bool onStartPage = false;

struct signal {
  int state;
  int prevState;
  int ref;
  int value;
  char message;
};

signal signals[6];

byte pins[6] = {A0, A1, A2, A3, A4, A5};

SoftwareSerial mySerial(rxPin, txPin);

void setup() {

  signal s0;
  signal s1;
  signal s2;
  signal s3;
  signal s4;
  signal s5;
  
  signals[0] = s0;
  signals[1] = s1;
  signals[2] = s2;
  signals[3] = s3;
  signals[4] = s4;
  signals[5] = s5;

  pinMode(13, OUTPUT);
  // define pin modes for tx, rx:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);

//  //initialize references
//  for (int i = 0; i<6; i++){
//    signals[i].ref = ADCTouch.read(pins[i], 500);
//  }

  //initialize states and prevstates
  for (int i = 0; i<6; i++){
    signals[i].state = LOW;
    signals[i].prevState = LOW;
  }
  
  // set the data rate for the SoftwareSerial port
  Serial.begin(9600);
  mySerial.begin(9600);
  //Serial.begin(9600);
  //Serial.println("<Arduino is ready>");
  
  Keyboard.begin();
}

void loop() {

  //read all pins values
  for (int i = 0; i<6; i++) {
    signals[i].value = analogRead(pins[i]);
  }
 
//  //read all pins' values
//  for (int i = 0; i<6; i++){
//    signals[i].value = ADCTouch.read(pins[i]);
//  }
//

    //calibration
    for (int i = 0; i<6; i++){
    signals[i].value == map(signals[i].value, 0, 1023, 0, 255);
    }
       
//  //remove all offsets
//  for (int i = 0; i<6; i++){
//    signals[i].value -= signals[i].ref;
//  }

  //TEST
    for (int i = 0; i<2; i++){
      Serial.print(signals[i].value);
      Serial.print('\t');
    }
    Serial.print('\n');

  for(int i = 0; i<6; i++){
    if (signals[i].value < TRESHOLD)
    {
      //if (value0 > 40)
      signals[i].state = HIGH;
    }
  
    else
    { signals[i].state = LOW;  
    }
  }

  //for each button,
  for(int i = 0; i<6; i++){
    //  if the button state has changed..
    if ((signals[i].state != signals[i].prevState)
        // ..and it's currently pressed:
        && (signals[i].state == HIGH)) {
          switch (i){

            //ATTENZIONE: GLI URL VENGONO SCRITTI CORRETTAMENTE SOLO SE LA TASTIERA IMPOSTATA SULLA RASPBERRY E' QUELLA INGLESE
            
            case 0: 
            Keyboard.press(128);
            Keyboard.press(108);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.press(215);
            Keyboard.print("&c=1");
            Keyboard.press(176);
            Keyboard.releaseAll();
            delay(100);
            Keyboard.press(107);
            Keyboard.releaseAll();

            
            lastPressTime = millis();
            onStartPage = false;
            break;
            
            case 1: 
            Keyboard.press(128);
            Keyboard.press(108);
            delay(100);
            Keyboard.releaseAll();
            Keyboard.print("ff3300.com/demo_ode/bacheca/?s=hackerspace");
            Keyboard.press(176);
            Keyboard.releaseAll();
            delay(100);
            Keyboard.press(107);
            Keyboard.releaseAll();
            
            lastPressTime = millis();
            onStartPage = false;
            break;
//            
//            case 2:
//            Keyboard.press(128);
//            Keyboard.press(108);
//            delay(100);
//            Keyboard.releaseAll();
//            Keyboard.print("localhost>8080&BACHECA_S)PALCO");
//            Keyboard.press(176);
//            Keyboard.releaseAll();
//            break;
//            
//            case 3: 
//            Keyboard.press(128);
//            Keyboard.press(108);
//            delay(100);
//            Keyboard.releaseAll();
//            Keyboard.print("localhost>8080&BACHECA_S)BOE>/BAR/DELL/OFFICINA/DEGLI/ESORDI");
//            Keyboard.press(176);
//            Keyboard.releaseAll();
//            break;
//            
//            case 4: 
//            Keyboard.press(128);
//            Keyboard.press(108);
//            delay(100);
//            Keyboard.releaseAll();
//            Keyboard.print("localhost>8080&BACHECA_S)SALA/WORKSHOP");
//            Keyboard.press(176);
//            Keyboard.releaseAll();
//            break;
//            
//            case 5:  
//            Keyboard.press(128);
//            Keyboard.press(108);
//            delay(100);
//            Keyboard.releaseAll();
//            Keyboard.print("localhost>8080&BACHECA_S)SALA/WORKSHOP");
//            Keyboard.press(176);
//            Keyboard.releaseAll();
//            break;
          }
        }
  }

  for(int i = 0; i<6; i++){
  signals[i].prevState = signals[i].state;
  }

  
  recvOneChar();
  
  if (showNewData() == 1) {
  lastPressTime = millis();
  onStartPage = false;
  }
  
  if (((millis() - lastPressTime) > 15000) && !onStartPage){
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("ff3300.com/demo_ode/bacheca");
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

int showNewData() {
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
      
      case 'v': break;
      case 'w':   
      Keyboard.press(128);
      Keyboard.press(108);
      delay(100);
      Keyboard.releaseAll();
      Keyboard.print("localhost>8080&BACHECA_S)hackerspace");
      Keyboard.press(176);
      Keyboard.releaseAll();
      break;
      case 'x': break;
      case 'y': break;
      
      case 'z':
      break;
      
      case '.': break;
      case ',': break;
    }
    newData = false;
    return 1;
  }
  return 0;
}
