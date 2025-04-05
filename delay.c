/*
 * Description:
 * This file implements delay functions for the PIC16F877A microcontroller using Timer0.
 * The delays are based on a 20MHz system clock. Timer0 is configured with a 1:256 prescaler
 * to generate accurate time delays in microseconds and milliseconds.
 *
 * Function Overview:
 * - Timer0_Init(): Initializes Timer0 with internal clock and 1:256 prescaler.
 * - delay_us(): Generates a delay in microseconds using Timer0 (recommended for delays > 50µs).
 * - delay_ms(): Generates a delay in milliseconds by calling delay_us(1000) in a loop.
 */

#include "delay.h"
#define _XTAL_FREQ 20000000UL  // Define the system clock frequency as 20MHz

// Timer0 initialization
void Timer0_Init() {
    OPT_REG = 0b10000111;   // Configure Timer0: internal clock source, 1:256 prescaler
    TIMER0 = 0;             // Clear Timer0 register (reset counter)
    TIME_INT &= ~(1 << 2);  // Clear Timer0 overflow interrupt flag (T0IF - bit 2 of INTCON)
}

// Microsecond delay function
// Accurate for delays greater than approximately 50µs
void delay_us(unsigned int microseconds) {
    // Calculate the number of clock cycles needed for the specified delay
    unsigned int cycles = (microseconds * (_XTAL_FREQ / 4000000UL));
    
    // Calculate the Timer0 reload value based on prescaler and cycles
    unsigned char reload_value = 256 - (cycles / 256);  // 256-step timer, prescaled
    
    TIMER0 = reload_value;       // Load Timer0 with initial value for the delay
    TIME_INT &= ~(1 << 2);       // Clear Timer0 interrupt flag (T0IF)
    
    // Wait until Timer0 overflows and T0IF is set
    while (!(TIME_INT & (1 << 2)));
    
    TIME_INT &= ~(1 << 2);       // Clear T0IF again for the next use
}

// Millisecond delay function
// Loops to create a delay of 1ms x 'milliseconds'
void delay_ms(unsigned int milliseconds) {
    while (milliseconds--) {
        delay_us(1000);  // Call delay_us for 1000µs = 1ms
    }
}
