/*
 * io.h
 *
 * Description:
 * This header file provides custom macros for controlling I/O direction and logic states
 * on the PIC16F877A microcontroller. It defines direct memory access to TRISx (direction)
 * and PORTx (data) registers, allowing easy manipulation of individual pins using simple macros.
 * 
 * Features:
 * - Macros to access TRIS and PORT registers by alias names (targeta, setporta, etc.).
 * - Pin direction constants: INPUT and OUTPUT.
 * - Macros to set a pin high or low.
 * - Macro to configure a pin as input or output using TRIS registers.
 *
 * Usage:
 * - Use SET_PIN_MODE(tris, pin, direction) to set pin mode (input/output).
 * - Use PIN_HIGH(port, pin) and PIN_LOW(port, pin) to write logic levels to pins.
 */

#ifndef io_H
#define io_H

// TRIS (direction) register aliases
#define targeta (*(volatile unsigned char *)0x85)  // TRISA
#define targetb (*(volatile unsigned char *)0x86)  // TRISB
#define targetc (*(volatile unsigned char *)0x87)  // TRISC
#define targetd (*(volatile unsigned char *)0x88)  // TRISD
#define targete (*(volatile unsigned char *)0x89)  // TRISE

// PORT (data) register aliases
#define setporta (*(volatile unsigned char *)0x05)  // PORTA
#define setportb (*(volatile unsigned char *)0x06)  // PORTB
#define setportc (*(volatile unsigned char *)0x07)  // PORTC
#define setportd (*(volatile unsigned char *)0x08)  // PORTD
#define setporte (*(volatile unsigned char *)0x09)  // PORTE

// Constants for pin direction
#define INPUT  1   // Configure pin as input
#define OUTPUT 0   // Configure pin as output

// Macro to set a specific pin low (logic 0)
#define PIN_LOW(port, pin)   (port &= ~(1 << (pin)))

// Macro to set a specific pin high (logic 1)
#define PIN_HIGH(port, pin)  (port |= (1 << (pin)))

// Macro to configure a pin's direction (input or output)
#define SET_PIN_MODE(tris, pin, direction) (direction) ? tris |= (1 << (pin)) : tris &= ~(1 << (pin))


#endif
