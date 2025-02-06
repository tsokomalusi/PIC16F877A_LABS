/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Stepper Motor Controlled Motion
 *
 * Created on January 30, 2025, 7:26 PM
 */

#define _XTAL_FREQ 4000000
#define BUTTON1 RC0
#define BUTTON2 RC1

#include <xc.h>
#include"config.h"
#include <pic16f877a.h>

void main(void) {
    
    // Bit shifting variable 
    unsigned char i=0;
    
    // Set PortB i/o pin to be all outputs
    TRISB = 0X00;
    
    //Set all PORTB pins to be OFF initially
    PORTB = 0X00;
    
    //Set RC0 and RC1 to be input pins
    TRISC0 = 1;
    TRISC1 = 1;
   
    // system main routine
    while(1) {
        
        // while button 1 is pressed, rotate CW
        while(BUTTON1){
            
            PORTB = (1<<i);
            i++;
            __delay_ms(100);
            if (i==4)
                i=0;
        }
        
        // while BUTTON2 is pressed rotate CCW
        
        while(BUTTON2) {
            
            PORTB = (8>>i);
            i++;
            __delay_ms(100);
            if(i==4)
                i=0;
        }
    }
    return;
}
