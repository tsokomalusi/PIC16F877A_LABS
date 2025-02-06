/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Driving Stepper Motor
 *
 * Created on January 29, 2025, 9:12 PM
 */

#include "config.h"
#include <xc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000

void main(void) {
    
    TRISB = 0X00;   // set all PORT B I/O pins to outputs
    PORTB = 0X00;   // initially set all the PORTB pins OFF
    
    unsigned char i = 0;  // Bit-shifting variable
    
    while(1) {
    
    // Rotate clockwise (CW)
        
        for (int j=0; j<48; j++) {
            
            PORTB = (1<<i);
            i++;
            __delay_ms(25);
            
            if (i==4)
                i=0;
        }
        
        // Wait for a second
        __delay_ms(1000);
        
        //Rotate Counter-Clockwise  (CCW)
        
        for(int j=0; j<48; j++){
            
            PORTB = (8>>i);
            i++;
            __delay_ms(25);
            
            if (i==4)
                i=0;
        }
        
   
    }
        
        
    return;
}
