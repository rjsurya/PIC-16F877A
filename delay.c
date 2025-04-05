#include "delay.h"
#define _XTAL_FREQ 20000000UL  // 20MHz clock

// Timer0 initialization
void Timer0_Init() {
    OPT_REG = 0b10000111;  // Timer0, 1:256 prescaler, internal clock
    TIMER0 = 0;           // Reset Timer0 counter
    TIME_INT &= ~(1 << 2); // Clear T0IF (Timer0 overflow flag)
}

// Microsecond delay (accurate for delays > ~50µs)
void delay_us(unsigned int microseconds) {
    // Calculate required timer counts
    unsigned int cycles = (microseconds * (_XTAL_FREQ / 4000000UL));  // Convert µs to cycles
    unsigned char reload_value = 256 - (cycles / 256);  // Adjust for prescaler

    TIMER0 = reload_value;      // Load initial value
    TIME_INT &= ~(1 << 2);     // Clear T0IF (bit 2 of TIME_INT)
    while (!(TIME_INT & (1 << 2))); // Wait until T0IF is set
    TIME_INT &= ~(1 << 2);     // Clear flag for next use
}

// Millisecond delay (accurate)
void delay_ms(unsigned int milliseconds) {
    while (milliseconds--) {
        delay_us(1000);  // Delay 1ms (1000µs)
    }
}