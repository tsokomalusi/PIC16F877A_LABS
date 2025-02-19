/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Generating 1sec delay with Timer Preloading
 *
 * Created on February 19, 2025, 8:04 PM
 */

#include <xc.h>
#include "config.h"
#include <pic16f877a.h>
#include <stdint.h>

#define LED RC0

// Global count variable for counting no. of timer overflow interrupts
uint8_t count = 0;

void main(void) {
    
    // -----------[[I/O Configuration]]----------------------
    
    TRISC0 = 0;   // set RC0 pin to be output
    LED = 0;     //  set the LED to be OFF initially
    
    //-------- [ [Configure Timer1 to operate in timer mode]]-----------
    // Pre-load the calculated value to the TMR1 16-Bit register
    TMR1 = 15535;
    
    // Choose the local clock source (timer mode)
    TMR1CS = 0;
    
    // Desired pre-scaler ratio (1:1)
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    
    // Event1 LED = ON
    LED = 1;
    
    // switch on TMR1 module
    TMR1ON = 1;
    
    //-------[[Interrupts Configuration]]---------------------------
    TMR1IE = 1;    // set TMR1 Interrupt Enable Bit
    TMR1IF = 0;    // clear TMR1 Interrupt Flag Bit
    PEIE = 1;      // set Peripheral Interrupts Enable Bit
    GIE = 1;       // set Global Interrupts Enable Bit
    
    while(1) {
        
        // Stay idle, Timer interrupt will handle everything
    }
      
    return;
}

// Interrupt Service Routine  - ISR
void __interrupt() ISR(void){
    
    // poll the TMR1IF flag bit
    if(TMR1IF){
        
        count++;
        if(count==20){
            
            // Event2 = Toggle LED
            LED = ~LED;
            
            // clear the global count
            count  = 0;
        }
        
        // Pre-load the value to TMR1 register at every overflow interrupt
        TMR1 =15535;
        TMR1IF = 0;
        
    }
}
