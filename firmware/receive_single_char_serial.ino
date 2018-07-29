#include <SoftwareSerial.h>

char receivedChar;
boolean newData = false;
const byte rxPin = 8;
const byte txPin = 9;

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
}

void loop() {
  recvOneChar();
  showNewData();
}

void recvOneChar() {
  if (mySerial.available() > 0) {
    receivedChar = mySerial.read();
    newData = true;
  }
}

void showNewData() {
  if (newData == true) {
    Serial.print("This just in ... ");
    Serial.write(receivedChar);
    Serial.println("");
    newData = false;
  }
}
