/*
 * File:   lab6.c
 * Author: Malusi Tsoko
 * Lab name: Stepper Motor Speed Control
 *
 * Created on February 6, 2025, 8:38 PM
 */


#include "config.h"
#include <xc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000
// #define x 10      //Test values: 100, 50, 10

void main(void) {
    
    TRISB = 0X00;    // SET ALL I/O PINS OF PORTB to be outputs
    PORTB = 0X00;    // SET ALL PORTB PINS TO BE OFF Initially
    
    unsigned char i = 0;   //Bit-shifting variable
    
    // Create System's main routine
    while(1) {
        
        // Turn one side
        
        for(int j=0; j<48; j++) {
            
            PORTB = (1<<i);
            i++;
            __delay_ms(25);  //Step delay
            if(i==4)
                i=0;
        }
        
        // Wait for 1 second
        
        for(int j=0; j<48; j++) {
            
            PORTB = (8>>i);
            i++;
            __delay_ms(25);
            if(i==4)
                i=0;
                    
        }
    }
    
    return;
}
