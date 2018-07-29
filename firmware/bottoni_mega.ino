#include <ADCTouch.h>
#include "mpr121.h"
#include <Wire.h>

//int ref0, ref1;     //reference values to remove offset

//int buttonState;
//int previousButtonState;

int irqpin = 2;  // Digital 2
boolean touchStates[12]; //to keep track of the previous touch states

byte pins[16] = {A0, A1, A2, A3, A4, A5, A6, A7, A8, A9, A10, A11, A12, A13, A14, A15};

struct signal {
  int state;
  int prevState;
  int ref;
  int value;
  char message;
};

signal signals[16];

void setup()
{

  pinMode(irqpin, INPUT);
  digitalWrite(irqpin, HIGH); //enable pullup resistor

  Wire.begin();
  mpr121_setup();
  
  // No pins to setup, pins can still be used regularly, although it will affect readings
  Serial.begin(9600);
  Serial1.begin(9600);

  signal s0;
  signal s1;
  signal s2;
  signal s3;
  signal s4;
  signal s5;
  signal s6;
  signal s7;
  signal s8;
  signal s9;
  signal s10;
  signal s11;
  signal s12;
  signal s13;
  signal s14;
  signal s15;

  signals[0] = s0;
  signals[1] = s1;
  signals[2] = s2;
  signals[3] = s3;
  signals[4] = s4;
  signals[5] = s5;
  signals[6] = s6;
  signals[7] = s7;
  signals[8] = s8;
  signals[9] = s9;
  signals[10] = s10;
  signals[11] = s11;
  signals[12] = s12;
  signals[13] = s13;
  signals[14] = s14;
  signals[15] = s15;

  //initialize references
  for (int i = 0; i<16; i++){
    signals[i].ref = ADCTouch.read(pins[i], 500);
  }
  
  //ref0 = ADCTouch.read(A0, 500);   //create reference values to
  //ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad

  // make the pushButton pin an input:
  //pinMode(buttonPin, INPUT);
}

void loop()
{

  //read all pins' values
  for (int i = 0; i<16; i++){
    signals[i].value = ADCTouch.read(pins[i]);
  }
  
  //int value0 = ADCTouch.read(A0);   //no second parameter
  //int value1 = ADCTouch.read(A1);   //   --> 100 samples

  //remove all offsets
  for (int i = 0; i<16; i++){
    signals[i].value -= signals[i].ref;
  }
  
  //value0 -= ref0;       //remove offset
  //value1 -= ref1;

  //set all states
  for(int i = 0; i<16; i++){
    if (signals[i].value > 100)
    {
      //if (value0 > 40)
      signals[i].state = HIGH;
    }
  
    else
    { signals[i].state = LOW;  
    }
  }

  //for each button,
  for(int i = 0; i<16; i++){
    //  if the button state has changed..
    if ((signals[i].state != signals[i].prevState)
        // ..and it's currently pressed:
        && (signals[i].state == HIGH)) {
          switch (i){
            case 0: Serial1.write('a'); break;
            case 1: Serial1.write('b'); break;
            case 2: Serial1.write('c'); break;
            case 3: Serial1.write('d'); break;
            case 4: Serial1.write('e'); break;
            case 5: Serial1.write('f'); break;
            case 6: Serial1.write('g'); break;
            case 7: Serial1.write('h'); break;
            case 8: Serial1.write('i'); break;
            case 9: Serial1.write('j'); break;
            case 10: Serial1.write('k'); break;
            case 11: Serial1.write('l'); break;
            case 12: Serial1.write('m'); break;
            case 13: Serial1.write('n'); break;
            case 14: Serial1.write('o'); break;
            case 15: Serial1.write('p'); break;
          }
    }
  }
  
  // save the current button state for comparison next time:
  
  for(int i = 0; i<16; i++){
  signals[i].prevState = signals[i].state;
  }

  readTouchInputs();
  
  delay(100);
}

void readTouchInputs(){
  if(!checkInterrupt()){
    
    //read the touch state from the MPR121
    Wire.requestFrom(0x5A, 2); 
    
    byte LSB = Wire.read();
    byte MSB = Wire.read();
    
    uint16_t touched = ((MSB << 8) | LSB); //16bits that make up the touch states
    
    for (int i=0; i < 12; i++){  // Check what electrodes were pressed
      if(touched & (1<<i)){
      
        if(touchStates[i] == 0){
          //pin i was just touched
          Serial.print("pin ");
          Serial.print(i);
          Serial.println(" was just touched");

          switch (i){
            case 0:

              Serial1.write('q');
//              Keyboard.press(128);
//              Keyboard.press(108);
//              delay(100);
//              Keyboard.releaseAll();
//              
//              Keyboard.print("wemake.cc");
//              Keyboard.press(176);
//               Keyboard.releaseAll();
               break;
              
             case 1:
             Serial1.write('r');
              break;

              case 2:
             Serial1.write('s');
              break;

              case 3:
             Serial1.write('t');
              break;


              case 4:
              Serial1.write('u');
              break;


              case 5:
             Serial1.write('v');
              break;

              case 6:
              Serial1.write('w');
              break;

              case 7:
             
              Serial1.write('x');
              break;

              case 8:
             
              Serial1.write('y');
              break;

              case 9:
             
              Serial1.write('z');
              break;

              case 10:
             
              Serial1.write('.');
              break;

              case 11:
             
              Serial1.write(',');
              break;
          }

        }else if(touchStates[i] == 1){
          //pin i is still being touched
        }  
      
        touchStates[i] = 1;      
      }else{
        if(touchStates[i] == 1){
          Serial.print("pin ");
          Serial.print(i);
          Serial.println(" is no longer being touched");
          
          //pin i is no longer being touched
       }
        
        touchStates[i] = 0;
      }
    
    }
  }
}

void mpr121_setup(void){


  //SETUP OF FIRST BOARD
  set_register(0x5A, ELE_CFG, 0x00); 
  
  // Section A - Controls filtering when data is > baseline.
  set_register(0x5A, MHD_R, 0x01);
  set_register(0x5A, NHD_R, 0x01);
  set_register(0x5A, NCL_R, 0x00);
  set_register(0x5A, FDL_R, 0x00);

  // Section B - Controls filtering when data is < baseline.
  set_register(0x5A, MHD_F, 0x01);
  set_register(0x5A, NHD_F, 0x01);
  set_register(0x5A, NCL_F, 0xFF);
  set_register(0x5A, FDL_F, 0x02);
  
  // Section C - Sets touch and release thresholds for each electrode
  set_register(0x5A, ELE0_T, TOU_THRESH);
  set_register(0x5A, ELE0_R, REL_THRESH);
 
  set_register(0x5A, ELE1_T, TOU_THRESH);
  set_register(0x5A, ELE1_R, REL_THRESH);
  
  set_register(0x5A, ELE2_T, TOU_THRESH);
  set_register(0x5A, ELE2_R, REL_THRESH);
  
  set_register(0x5A, ELE3_T, TOU_THRESH);
  set_register(0x5A, ELE3_R, REL_THRESH);
  
  set_register(0x5A, ELE4_T, TOU_THRESH);
  set_register(0x5A, ELE4_R, REL_THRESH);
  
  set_register(0x5A, ELE5_T, TOU_THRESH);
  set_register(0x5A, ELE5_R, REL_THRESH);
  
  set_register(0x5A, ELE6_T, TOU_THRESH);
  set_register(0x5A, ELE6_R, REL_THRESH);
  
  set_register(0x5A, ELE7_T, TOU_THRESH);
  set_register(0x5A, ELE7_R, REL_THRESH);
  
  set_register(0x5A, ELE8_T, TOU_THRESH);
  set_register(0x5A, ELE8_R, REL_THRESH);
  
  set_register(0x5A, ELE9_T, TOU_THRESH);
  set_register(0x5A, ELE9_R, REL_THRESH);
  
  set_register(0x5A, ELE10_T, TOU_THRESH);
  set_register(0x5A, ELE10_R, REL_THRESH);
  
  set_register(0x5A, ELE11_T, TOU_THRESH);
  set_register(0x5A, ELE11_R, REL_THRESH);
  
  // Section D
  // Set the Filter Configuration
  // Set ESI2
  set_register(0x5A, FIL_CFG, 0x04);
  
  // Section E
  // Electrode Configuration
  // Set ELE_CFG to 0x00 to return to standby mode
  set_register(0x5A, ELE_CFG, 0x0C);  // Enables all 12 Electrodes
  
  
  // Section F
  // Enable Auto Config and auto Reconfig
  /*set_register(0x5A, ATO_CFG0, 0x0B);
  set_register(0x5A, ATO_CFGU, 0xC9);  // USL = (Vdd-0.7)/vdd*256 = 0xC9 @3.3V   set_register(0x5A, ATO_CFGL, 0x82);  // LSL = 0.65*USL = 0x82 @3.3V
  set_register(0x5A, ATO_CFGT, 0xB5);*/  // Target = 0.9*USL = 0xB5 @3.3V
  
  set_register(0x5A, ELE_CFG, 0x0C);

}

boolean checkInterrupt(void){
  return digitalRead(irqpin);
}


void set_register(int address, unsigned char r, unsigned char v){
    Wire.beginTransmission(address);
    Wire.write(r);
    Wire.write(v);
    Wire.endTransmission();
}
