/*
 * delay.h
 *
 * Description:
 * This header file defines macros and function prototypes for delay routines using Timer0
 * on the PIC16F877A microcontroller. It includes direct memory access definitions for
 * the OPTION_REG, TMR0 (Timer0), and INTCON (interrupt control register) registers.
 * These definitions allow fine control over Timer0 for precise delay generation.
 *
 * Function Prototypes:
 * - Timer0_Init(): Initializes Timer0 with required settings (internal clock, 1:256 prescaler).
 * - delay_us(): Creates a delay in microseconds using Timer0.
 * - delay_ms(): Creates a delay in milliseconds using the microsecond delay function.
 */

#ifndef delay_H
#define delay_H

// Define direct memory access for special function registers

#define OPT_REG  (*(volatile unsigned char *)0x81)  // OPTION_REG: Controls Timer0 prescaler and clock source
#define TIMER0   (*(volatile unsigned char *)0x01)  // TMR0: 8-bit Timer0 register
#define TIME_INT (*(volatile unsigned char *)0x0B)  // INTCON: Interrupt control register (T0IF is bit 2)

// Function to initialize Timer0 with internal clock and 1:256 prescaler
void Timer0_Init();

// Function to generate a delay in microseconds (recommended > 50µs)
void delay_us(unsigned int microseconds);

// Function to generate a delay in milliseconds using delay_us()
void delay_ms(unsigned int milliseconds);

#endif
