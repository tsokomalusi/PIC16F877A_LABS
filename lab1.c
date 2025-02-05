/*
 * File:   lab1.c
 * Lab name: Flashing LEDS
 * Author: Malusi Tsoko
 *
 * Created on January 19, 2025, 4:42 PM
 */

#include "config.h"
#include <xc.h>

#define _XTAL_FREQ  4000000

void main(void) {
    
    // I/O configuration
    TRISB0 = 0;
    TRISB1 = 0;
    TRISB2 = 0;
    
    // LEDS default state
    RB0 = 0;
    RB1 = 0;
    RB2 = 0;
    
    while(1) {
        
        // Flashing LED1
        RB0 = 1;
        __delay_ms(200);
        RB0 = 0;
        __delay_ms (200);
        
        // Flashing LED2
        RB1 = 1;
        __delay_ms (200);
        RB1 = 0;
        __delay_ms (200);
        
        // Flashing LED3
        RB2 = 1;
        __delay_ms (200);
        RB2 = 0;
        __delay_ms (200);
            
    }
    return;
}
