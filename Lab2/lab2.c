/*
 * File:   lab2.c
 * Author: Malusi Tsoko
 * Lab name: Reading digital Inputs (Digital Inputs)
 *
 * Created on January 19, 2025, 8:27 PM
 */

#include "config.h"
#include <pic16f877a.h>
#include <xc.h>

#define _XTAL_FREQ 4000000
#define LED RB1


void main(void) {
    
    // I/O configuration
    TRISB0 = 1;
    TRISB1 = 0;
    
    //default state of the LED
    LED = 0;
    
    //flash the LED twice per second on button press event
    while(1) {
        
        if(RB0 == 1) {
            
            LED = 1;
            __delay_ms(250);
            LED = 0;
            __delay_ms(250);
            
        
        }
                        
    }
    return;
}
