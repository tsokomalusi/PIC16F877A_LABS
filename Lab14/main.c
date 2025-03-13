/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: PWM - LED Dimmer
 *
 * Created on March 13, 2025, 9:26 PM
 */

#define _XTAL_FREQ 4000000

#include <xc.h>
#include <stdint.h>
#include"config.h"
#include <pic16f877a.h>

void PWM1_Set_Duty(uint16_t);

void main(void) {
    
    //------------[Configure The CCP1 Module For PWM mode]------------------
    CCP1M3 = 1;
    CCP1M2 = 1;
    
    //-----[Configure The CCP1 Pin (RC2) To Be An Output Pin]--------------
    TRISC2 = 0;    // RC2/CCP1(PWM) Output pin
    
    // Set the PWM frequency
    PR2 = 124;
    
    // Set Timer2 Pre-scaler To Match (1:4)
    T2CKPS0 = 1;
    T2CKPS1 = 0;
    
    // Turn on Timer2 To Start CCP1 PWM
    TMR2ON = 1;
    
    uint16_t DC = 0;
   
    // System's Main Routine
    while(1) {
        
        DC  = 0;   // Start with 0% DutyCycle
        
        // Gradually increase the LED brightness
        while(DC<500) {
            PWM1_Set_Duty(DC);
            DC++;
            __delay_ms(2);
        }
        __delay_ms(100);
        
        // Gradually decrease the LED brightness
        while(DC>0) {
            
            PWM1_Set_Duty(DC);
            DC--;
            __delay_ms(2);
        }
        __delay_ms(100);
    }
    return;
}

// Check The DC Value To Make Sure It's within 10-Bit range
void PWM1_Set_Duty(uint16_t DC) {
    
    if(DC<1024){
        
        CCP1Y = DC & 1;
        CCP1X = DC & 2;
        CCPR1L = DC >> 2;
    }
}
