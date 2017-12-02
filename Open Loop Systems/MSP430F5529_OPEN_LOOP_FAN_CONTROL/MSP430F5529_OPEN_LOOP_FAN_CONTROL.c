#include <msp430.h> 

int temp = 0;                                 // initialize desired temperature to zero
int main(void)
{
	WDTCTL = WDTPW | WDTHOLD;	              // stop watchdog timer
	P2DIR |= BIT0;                            // P2.0 set as an output
	int temp = 39;                            // Acceptable range 39-89
	
	TA0CTL |= TAIE;                           // Timer A interrupt enabled
	TA0CCR0 = 25000;                          // PWM Period
	TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
	TA0CCTL1 = CCIE;                          // CCR1 interrupt enabled
	TA0CCR1 = ((((-2)*temp)+178)*25000)/100;  // CCR1 PWM duty cycle
	TA0CTL = TASSEL_2 + MC_1 + TACLR;         // SMCLK, up mode, clear TAR
	__bis_SR_register(LPM0_bits + GIE);       // Enter LPM0 with interrupt
}

// Timer A0 Interrupt Service Routine
#pragma vector = TIMER0_A0_VECTOR
    __interrupt void TimerA (void)
    {
        P2OUT |= BIT0;                        // Turn on LED on P2.0
    }
// Timer A1 Interrupt Service Routine
#pragma vector = TIMER0_A1_VECTOR
    __interrupt void TimerA1 (void)
    {
        switch(TA0IV)
        {
        case 2:
            P2OUT &= ~BIT0;                   // Turn off LED on P2.0
        }

    }
