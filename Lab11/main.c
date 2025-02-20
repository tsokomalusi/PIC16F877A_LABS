/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Interrupt Driven vs Polling
 *
 * Created on February 20, 2025, 7:26 PM
 */


#include <xc.h>
#include "config.h"
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000

void main(void) {
    
    //-----[Configure I/O pins]-------
    TRISC1 = 0;
    TRISC2 = 0;
    
    // Set the LEDS to be initially off
    RC1 = 0;
    RC2 = 0;
    
    // Set the GPIO pin RB1 to be input pin
    TRISB1 = 1;
    
    //-----[Configure the RB0 IRQ interrupt]------
    INTEDG = 0;
    INTE = 1;
    GIE = 1;
    
    // create the main loop
    while(1) {
        
        // Green LED blinking routine
        RC2 = 1;
        __delay_ms(1000);
        RC2 = 0;
        __delay_ms(1000);
        
        // Check for the RB1 button (Polling)
        if(RB1) {
            
            // Toggle the Yellow LED
            RC1 = ~RC1;
        }
    }
 
    return;
}

// ISR handler

void __interrupt() ISR(void) {
    
    if(INTF == 1) {
        
        // Toggle the Yellow LED
        RC1 = ~RC1;
        INTF = 0;
    }
}
