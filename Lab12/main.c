/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: CCP Capture Mode
 *
 *
 * Created on March 10, 2025, 4:55 PM
 */

#include <xc.h>
#include "config.h"
#include <pic16f877a.h>

void main(void) {
    
    //---[Configure I/O Ports]----------------------------------------------
    TRISB = 0X00;
    PORTB = 0X00;         // Initial state of PORTB
    
    // Set the I/O Port for the TIMER1 register value
    TRISD = 0X00;
    PORTD = 0X00;        // Initial state of PORD  
    
    
    //--[Configure the Timer1 module to operate in synchronous counter mode]--
    //  Clear the Timer1 module to start counting from 0
    TMR1 = 0;
    // Choose the desired pre-scaler ratio (1:1)
    T1CKPS0 = 0;
    T1CKPS1 = 0;
    // Choose external clock source (counter mode)
    TMR1CS = 1;
    T1OSCEN = 1;
    // Synchronize external clock input for counter-mode
    T1SYNC = 0;
    TMR1ON = 1;
    
    //------[Configure the CCP module to operate in Capture mode]-------------
    CCP1M0 = 1;
    CCP1M1 = 0;
    CCP1M2 = 1;
    CCP1M3 = 0;
    
    // Enable CCP1 interrupt
    CCP1IE = 1;
    PEIE = 1;
    GIE = 1;
    
    // main loop of the system
    while(1) {
    
       // Read and print out the TMR1 values
        PORTD = TMR1;
    
    }
    return;
}

// ISR handler

void __interrupt() ISR(void) {
    
    if(CCP1IF){
        
        // If capture event occurs, write the CCPR1 register's value to PORTB
        PORTB = CCPR1;
        CCP1IF = 0;
    }

}