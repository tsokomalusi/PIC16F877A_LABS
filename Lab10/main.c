/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: IRQ(Interrupt Request Pins) or External Interrupts
 *
 * Created on February 20, 2025, 5:52 PM
 */


#include <xc.h>
#include "config.h"
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000

void main(void) {
    
    //---[Configure the I/O pins]-----------------------
    TRISC1 = 0;
    TRISC2 = 0;
    
    //---[Configure the RB0 IRQ Interrupt]--------------
    INTEDG = 1;
    INTE = 1;
    GIE = 1;
    
    // create the main loop
    
    while(1) {
        
        // Green LED blinking routine
        RC2 = 1;
        __delay_ms(1000);
        RC2 = 0;
        __delay_ms(1000);
    }
    
    return;
}

void __interrupt() ISR(void){
    
    // check the flag bit
    if(INTF == 1){
        
        // Toggle the Yellow LED
        RC1 = ~RC1;    
        INTF = 0; // clear the flag bit
    }
    
}
