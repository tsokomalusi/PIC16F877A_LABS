/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Polling vs Interrupt-driven
 *
 * Created on February 12, 2025, 5:52 PM
 */

#include <xc.h>
#include "config.h"
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000

#define BUTTON1 RB0
#define BUTTON2 RB1
#define RED RC0
#define BLUE RC1


void main(void) {
    
    // I/O configuration
    
    // RB0 and RB1 are configured to be inputs
    TRISB0 = 1;
    TRISB1 = 1;
    
    // RC0 and RC1 are configured to be outputs
    TRISC0 = 0;
    TRISC1 = 0;
    
    /*
    while(1) {
        
        RED = 1;
        __delay_ms(1000);
        RED = 0;
        __delay_ms(1000);
        
        // Polling the button input pin
        if(BUTTON2 == 1){
            
            BLUE = 1;
            __delay_ms(100);
            BLUE = 0;
        }
           
    }*/
     
    while(1) {
        
         RED = 1;
        __delay_ms(1000);
        RED = 0;
        __delay_ms(1000);
        
    }
        
        
    return;
}

void __interrupt() ISR(void) {
    
    if(BUTTON1 == 1) {
        
        BLUE = 1;
        __delay_ms(1000);
        BLUE = 0;
        
    }
    
}
