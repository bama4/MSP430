#include <msp430g2553.h>

#define LED0 BIT0
#define LED1 BIT1
#define LED2 BIT2
#define LED3 BIT3

void simple_on_off_prog(){
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    P1DIR = BIT3; //Set pin P1.3 to be an output pin
    P1OUT = BIT3; //Set state first as on state
    unsigned int ctr = 0;
    while(1){

        //Delay
        for(ctr = 0; ctr < 10000; ctr++){

        }

        //printf("Flipping pin\n");
        P1OUT ^= BIT3;//Flip pin to opposite P1OUT = P1OUT ^ BIT3
    }
}

void delay(unsigned int time){
    int ctr = 0;
    for(ctr = 0; ctr < time; ctr++){
        //delay
    }
}

/*Given the number of leds, creates a small program that
 *lights up each one at a time then flashes twice and repeats this
 *infinitely.
 *
 *
 */
void led_pattern(){
    P1DIR = LED0 + LED1 + LED2 + LED3; //Initialize P1DIR to designate output pins
    P1OUT = 0;//Set pins as all off

    while(1){

        delay(100000);
        unsigned char bit = LED0;
        // Turn on LED
        for(bit = LED0; bit <= LED3; bit=bit<<1){
            P1OUT ^= bit;
            delay(100000);
        }
        delay(100000);
        bit = LED0;
        //Flash twice all leds
        for(bit = LED0; bit <= LED3; bit=bit<<1){
            P1OUT ^= bit;
            delay(300000);
            P1OUT ^= bit;
            delay(300000);
            //P1OUT ^= bit;
        }

    }


}
/**
 * main.c
 */
int main(void)
{
    WDTCTL = WDTPW | WDTHOLD;   // stop watchdog timer
    led_pattern(); //Run led pattern program with 4 leds
    return 0;
}
