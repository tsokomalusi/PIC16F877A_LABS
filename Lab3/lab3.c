/*
 * File:   lab3.c
 * Author: Malusi Tsoko
 * Lab name: Counting with 7 Segment Display
 *
 * Created on January 21, 2025, 6:57 PM
 */

#include "config.h"
#include <xc.h>
#include <pic16f877a.h>

#define _XTAL_FREQ 4000000

void main(void) {
    
    unsigned char segments_code[10] = {0xFC,0x60,0xDA,0xF2,0x66,0xB6,0xBE,0xE0,
    0xFE,0xF6};
    
    unsigned char count = 0;
    
    TRISB = 0x00;  // set all portB pins to outputs
    PORTB = 0x00;  // initially  clear all pins of PORTB
    
    while(1) {
        
        PORTB = segments_code[count];
        __delay_ms(500);
        count++;
        if(count==10)
            count = 0;    
    }
      
    return;
}
