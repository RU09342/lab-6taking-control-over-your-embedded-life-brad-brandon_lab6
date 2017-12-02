#include <msp430.h>
/*
Code Taken Directly from TI via
Resource Explorer in Code Composer Studio
*/

int main(void) {

   WDTCTL = WDTPW | WDTHOLD;     // stop watchdog timer
   P1DIR = 0x01;                 // set up bit 0 of P1 as output
   P1OUT = 0x00;                 // intialize bit 0 of P1 to 0

   while(1)
   {
       P1OUT ^= BIT0;
       __delay_cycles(400000);   // Delay to slow switching speed to manageable level
   }

 }
