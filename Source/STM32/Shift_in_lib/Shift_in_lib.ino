/*{{{
 * SN74HC165N_shift_reg
 *
 * Program to shift in the bit values from a SN74HC165N 8-bit
 * parallel-in/serial-out shift register.
 *
 * This sketch demonstrates reading in 16 digital states from a
 * pair of daisy-chained SN74HC165N shift registers while using
 * only 4 digital pins on the Arduino.
 *
 * You can daisy-chain these chips by connecting the serial-out
 * (Q7 pin) on one shift register to the serial-in (Ds pin) of
 * the other.
 * 
 * Of course you can daisy chain as many as you like while still
 * using only 4 Arduino pins (though you would have to process
 * them 4 at a time into separate unsigned long variables).
 * 
*//*}}}*/
#include "pinsRedefine.h"
#include "ShiftIn.h"

//define block{{{
/*}}}*/

ShiftIn sinput;

void setup()/*{{{*/ {
   Serial.begin(9600);
   /* Initialize our digital pins...  */
	sinput.initpins();
	/*
   pinMode(SHIFTIN_PLOADPIN, OUTPUT);
   pinMode(SHIFTIN_CLOCKENABLEPIN, OUTPUT);
   pinMode(SHIFTIN_CLOCKPIN, OUTPUT);
   pinMode(SHIFTIN_DATAPIN, INPUT);
   digitalWrite(SHIFTIN_CLOCKPIN, LOW);
   digitalWrite(SHIFTIN_PLOADPIN, HIGH);
	*/
   /* Read in and display the pin states at startup.  */
	sinput.runtime();
   Serial.print("End Setup");
	}/*}}}*/

void loop()/*{{{*/ {
    /* Read the state of all zones.  */
    sinput.runtime();
    /* If there was a chage in state, display which ones changed.  */
    if(sinput.isChenged()) {/*{{{*/
       Serial.print("*Pin value change detected*\r\n");
       sinput.display_pin_values();
		 }/*}}}*/
}/*}}}*/
