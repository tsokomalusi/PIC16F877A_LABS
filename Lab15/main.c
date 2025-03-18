/*
 * File:   main.c
 * Author: Malusi Tsoko
 * Lab name: Internal EEPROM
 *
 * Created on March 18, 2025, 6:40 PM
 */

#include <xc.h>
#include<stdint.h>
#include "config.h"
#include<pic16f877a.h>
#define _XTAL_FREQ 4000000

//------------------[Pin Definitions]------------------------------------------
#define read RB0            // Read EEPROM Memory locations
#define W_3  RB1            // Write 0x03
#define W_5  RB2            // Write 0x05
#define W_7  RB3            // Write 0x07

//---------     [Function Declarations]-----------------------------------------
void eeprom_write(uint8_t, uint8_t);
uint8_t eeprom_read(uint8_t);


void main(void) {
    
    //------------[I/O pins configuration]-------------------------------------
    TRISB = 0xFF;            // Push-Buttons(inputs)
    TRISD = 0X00;            // LEDs (outputs)
    PORTD = 0X00;            // Initially OFF
    
    uint8_t address;
    
    while(1) {
        
        /* Write 0x03 in the current EEPROM memory location and increment the 
         address pointer*/
        if(W_3) {
            eeprom_write(address++, 3);
            __delay_ms(500);
        }
        
        /* Write 0x05 in the current EEPROM memory location and increment the
         address pointer*/
        if(W_5) {
            eeprom_write(address++, 5);
            __delay_ms(500);   
        }
        
        /* Write 0x07 in the current EEPROM memory location and increment the
         address pointer*/
        if(W_7) {
            eeprom_write(address++, 7);
            __delay_ms(500);   
        }
        
        // read must read the first 3-bytes (memory locations) of EEPROM
        // and write them out to PORTD
        if(address == 3) 
            address = 0;
        
        if(read == 1) {
            
            for(uint8_t i = 0; i < 3; i++) {
                
                PORTD = eeprom_read(i);
                __delay_ms(1000);
            }
        }
               
    }
    return;
}

void eeprom_write(uint8_t address, uint8_t data){
    
    while(EECON1bits.WR);    // Waits until Last Attempt To Write Is Finished
    EEADR = address;        // Writes the address to which we'll write our data
    EEDATA = data;         // Writes the data to be saved
    EECON1bits.EEPGD = 0;  // Clear the EEPGD to point to EEPROM Data memory
    EECON1bits.WREN = 1;   // Initiates the write cycle
    INTCONbits.GIE = 0;    // Disable all interrupts until Writing is Done
    EECON2 = 0x55;         // Part of writing mechanism
    EECON2 = 0xAA;         // Part of writing mechanism
    EECON1bits.WR = 1;      // Part of writing mechanism
    INTCONbits.GIE = 1;    // Re-enable all interrupts
    EECON1bits.WREN = 0;   // Disable the write operation
    EECON1bits.WR = 0;     // Ready for the next write cycle
      
}

uint8_t eeprom_read(uint8_t address){
    
    uint8_t data;
    EEADR = address;   // Write the address from which we'll retrieve data
    EECON1bits.EEPGD = 0; // Cleared to point to EEPROM Data Memory not Prog. M
    EECON1bits.RD = 1;    // Read from EEPROM memory
    data = EEDATA;        // read the data
    return data;
      
}
