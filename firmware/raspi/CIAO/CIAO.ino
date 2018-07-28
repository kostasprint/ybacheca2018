#include <ADCTouch.h>

int ref0, ref1;     //reference values to remove offset


void setup() 
{

     pinMode(LED_BUILTIN, OUTPUT);
    // No pins to setup, pins can still be used regularly, although it will affect readings

    Serial.begin(9600);

    ref0 = ADCTouch.read(A0, 500);    //create reference values to 
    ref1 = ADCTouch.read(A1, 500);    //account for the capacitance of the pad
} 

void loop() 
{
    int value0 = ADCTouch.read(A0);   //no second parameter
    int value1 = ADCTouch.read(A1);   //   --> 100 samples

    value0 -= ref0;       //remove offset
    value1 -= ref1;

   // Serial.print(value0);             //send actual reading
   // Serial.print("\t");
	
    delay(100);

    if(value0 > 100){
      Serial.write(1);
      Serial.print(1);
      digitalWrite(LED_BUILTIN, HIGH);

    
      
    }else{
      Serial.write(0);
      Serial.print(0);
      digitalWrite(LED_BUILTIN, LOW);
    }


    
}
