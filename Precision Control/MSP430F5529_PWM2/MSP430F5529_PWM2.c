#include <msp430.h>

int temp = 0;
unsigned int i = 0;// Variable to step through array
int main(void)
{
            WDTCTL = WDTPW + WDTHOLD;                 // Stop WDT
            P2DIR |= BIT0;                            // P1.0 set as an output
            temp = 50;

            TA0CTL |= TAIE;                           // Timer A interrupt enabled
            TA0CCR0 = 24999-1;                          // PWM Period
            TA0CCTL0 = CCIE;                          // CCR0 interrupt enabled
            TA0CCTL1 = CCIE;                          // CCR1 interrupt enabled
            //TA0CCR1 = ((((-2)*temp)+178)*25000)/100;
            TA0CTL = TASSEL_2 + MC_1 + TACLR;         // SMCLK, up mode, clear TAR

            //UART Initialization
             P3SEL = BIT3+BIT4;                        // P3.3, P3.4 transmit/receive
             UCA0CTL1 |= UCSWRST;                      // Put state machine in reset
             UCA0CTL1 |= UCSSEL_2;                     // SMCLK
             UCA0BR0 = 6;                              // 1MHz 9600 baud
             UCA0BR1 = 0;                              // 1MHz 9600
             UCA0MCTL = UCBRS_0 + UCBRF_13 + UCOS16;   // Sets m control register
             UCA0CTL1 &= ~UCSWRST;                     // Sets control register
             UCA0IE |= UCRXIE;                         // Enable UART interrupt


__bis_SR_register(LPM0_bits + GIE);                   // Enter LPM0 with interrupt

}

// Echo back RXed character, confirm TX buffer is ready first
#if defined(__TI_COMPILER_VERSION__) || defined(__IAR_SYSTEMS_ICC__)
#pragma vector=USCI_A0_VECTOR
__interrupt void USCI_A0_ISR(void)
#elif defined(__GNUC__)
void __attribute__ ((interrupt(USCI_A0_VECTOR))) USCI_A0_ISR (void)
#else
#error Compiler not supported!
#endif
{
  switch(__even_in_range(UCA0IV,4))
  {
  case 0:break;                             // Vector 0 - no interrupt
  case 2:                                   // Vector 2 - RXIFG
    while (!(UCA0IFG&UCTXIFG));             // USCI_A0 TX buffer ready?
    switch(UCA0RXBUF)
    {
       case 'A':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 0;
           break;
       case 'B':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 51;
           break;
       case 'C':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 102;
           break;
       case 'D':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 154;
           break;
       case 'E':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 205;
           break;
       case 'F':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 256;
           break;
       case 'G':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 307;
           break;
       case 'H':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 358;
           break;
       case 'I':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 410;
           break;
       case 'J':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 461;
           break;
       case 'K':
           UCA0TXBUF = UCA0RXBUF;
           TA0CCR1 = 512;
           break;
    }

    break;
  case 4:break;                             // Vector 4 - TXIFG
  default: break;
  }
}

// Timer A0 Interrupt Service Routine
#pragma vector = TIMER0_A0_VECTOR
    __interrupt void TimerA (void)
    {
        P2OUT |= BIT0;                                // Turn on LED on P1.0
    }
// Timer A1 Interrupt Service Routine
#pragma vector = TIMER0_A1_VECTOR
    __interrupt void TimerA1 (void)
    {
        switch(TA0IV)
        {
        case 2:
            P2OUT &= ~BIT0;                          // Turn off LED on P1.0
        }

    }
