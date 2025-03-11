/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: CCP1 Compare Mode
 *
 * Created on March 11, 2025, 6:12 PM
 */


#include <xc.h>
#include "config.h"
#include <pic16f877a.h>
#include <stdint.h>

uint8_t X=0;   // Counter for Compare Match events

void main(void) {
    
    //---[Configure the I/O ports]------------------
    // Set the output pin for the LED
    TRISC4=0;
    RC4 = 0;    // Initially OFF
    
    //---[Configure the Timer1 module to operate in timer mode]-------
    // Clear the Timer1 register to start counting from 0.
    TMR1 = 0;
    
    // Choose the local clock source(timer mode)
    TMR1CS = 0;
    
    // Choose the desired prescaler ratio (1:1)
    T1CKPS0 = 0;
    T1CKPS1 = 0;
   
    // Turn on timer1
    TMR1ON = 1;
    
    //--[Configure the CCP1 module to operate in Compare mode]--------
    // Pre-load the CCPR1 register
    CCPR1 = 50000;
    
    // CCP1 in Compare Mode, CCP1 pin is unchanged and trigger special event
    CCP1M0 = 1;
    CCP1M1 = 1;
    CCP1M2 = 0;
    CCP1M3 = 1;
    
    // Enable CCP1 interrupt
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;
    
    // main loop of the system
    
    while(1) {
        
        // In idle state, ISR will handle everything
    }
    
    return;
}

void __interrupt() ISR(void){
    
    if(CCP1IF) {
        
        X++;
        if(X==10){
            
            // Toggle lED
            RC4 = ~RC4;
            X = 0;
        }
        
        // Clear the interrupt flag bit
    CCP1IF = 0;
    }
    
    
}
