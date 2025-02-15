/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Generating 1 second time delay
 *
 * Created on February 15, 2025, 10:32 AM
 */


#include <xc.h>
#include"config.h"
#include<pic16f877a.h>

#define _XTAL_FREQ 4000000
#define LED RC0

 // Global count variable to count no. of timer overflow interrupts
uint8_t count = 0;  
    

void main(void) {
    
    // GPIO configuration
    
    TRISC0 = 0;  // set the RC0 pin to be output
    LED = 0;
    
     // ---[Configure  TIMER1 TO OPERATE IN TIMER MODE]----
        
     // clear the TMR1 to start counting from 0
     TMR1 = 0;
        
     // choose the local clock source
     TMR1CS = 0;
        
     // pre-scaler ratio 1:1
     T1CKPS0 = 0;
     T1CKPS1 = 0;
        
     // Event1 set the LED ON
     LED = 1;
        
     // switch on TIMER1 module
     TMR1ON = 1;
     
     //---[TIMER1 interrupt configuration]
     TMR1IE = 1;    // TIMER1 enable bit
     TMR1IF = 0;    // clear the interrupt flag bit
     PEIE = 1;      // peripherals enable bit
     GIE = 1;       // global interrupt enable bit
   
    while(1) {
        
      // Stay idle, TIMER1 interrupt will handle everything      
    }
    
    return;
}

// Interrupt Service Routine -ISR

void __interrupt() ISR(void) {
    
    // check the flag bit
    
    if(TMR1IF==1) {
        
        count++;
        
        if(count==15){
            
            // Event2 = toggle the LED
            LED = ~LED;
            // clear the Global count variable
            count = 0;
        }
        // clear the flag bit
        TMR1IF = 0;
        
    }
}
