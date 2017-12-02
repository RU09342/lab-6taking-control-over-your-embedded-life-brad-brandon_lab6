#include <msp430.h>

int i = 0;

int main(void)
{
      WDTCTL = WDTPW | WDTHOLD;                                        // Stop Watchdog Timer

    P3SEL |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;    // Set all 8 P3 pins as outputs
    P3DIR |= BIT0 + BIT1 + BIT2 + BIT3 + BIT4 + BIT5 + BIT6 + BIT7;    // Set direction for all 8 P3 pins

    while(1)                                                           // Infinite loop
    {
        for (i = 0; i < 255; i ++)                                     // Increases value, positive slope of triangle
        {
            P3OUT = i;
            __delay_cycles(100000);                                    // Delay to make waveform visible on scope
        }
        for (i = 255; i > 0 ; i --)                                    // Decreases value, negative slope of triangle wave
        {
            P3OUT = i;
            __delay_cycles(100000);                                    // Delay to make waveform visible on scope
        }
    }
}
