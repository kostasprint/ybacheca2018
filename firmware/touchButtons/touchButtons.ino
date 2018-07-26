#include <ADCTouch.h>
#include <Keyboard.h>

int ref0, ref1;     //reference values to remove offset

int buttonState;
int previousButtonState;
int counter;
char ctrlKey = KEY_LEFT_CTRL;


void setup()
{
  // No pins to setup, pins can still be used regularly, although it will affect readings

  Serial.begin(9600);
  ref0 = analogRead(A6);
  //ref0 = ADCTouch.read(A6, 500);    //create reference values to
  ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad

  // make the pushButton pin an input:
  //pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop()
{
  int value0 = analogRead(A6);   //no second parameter
  //int value0 = ADCTouch.read(A0);   //no second parameter
  int value1 = ADCTouch.read(A1);   //   --> 100 samples

  value0 -= ref0;       //remove offset
  value1 -= ref1;

  if (value0 < 120)
  {
    //if (value0 > 40)
    buttonState = HIGH;
  }

  else
  { buttonState = LOW;
  }

  //buttonState = Serial.print(value0 > 40);  //send (boolean) pressed or not pressed
  //  //Serial.print("\t");           //use if(value > threshold) to get the state of a button
  //
  //
  //  Serial.print(value1 > 40);
  //  Serial.print("\t\t");
  //
  //Serial.println(value0);             //send actual reading

  // if the button state has changed,
  if ((buttonState != previousButtonState)
      // and it's currently pressed:
      && (buttonState == HIGH)) {
    // increment the button counter
    counter++;
    // type out a message
    Keyboard.press(131);
    Keyboard.press(108);
    delay(100);
    Keyboard.releaseAll();
    Keyboard.print("wemake.cc");
    //Keyboard.print(".");
    //Keyboard.releaseAll();
    //Keyboard.print("cc");
    Keyboard.press(176);
    Keyboard.releaseAll();
  }
  // save the current button state for comparison next time:
  previousButtonState = buttonState;

  Serial.println(value0);
  delay(100);
}


