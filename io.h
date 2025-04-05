#ifndef io_H
#define io_H
#define targeta (*(volatile unsigned char *)0x85)
#define targetb (*(volatile unsigned char *)0x86)
#define targetc (*(volatile unsigned char *)0x87)
#define targetd (*(volatile unsigned char *)0x88)
#define targete (*(volatile unsigned char *)0x89)

// PORT registers (data I/O)
#define setporta (*(volatile unsigned char *)0x05)
#define setportb (*(volatile unsigned char *)0x06)
#define setportc (*(volatile unsigned char *)0x07)
#define setportd (*(volatile unsigned char *)0x08)
#define setporte (*(volatile unsigned char *)0x09)

// Direction constants
#define INPUT  1
#define OUTPUT 0

// Pin state macros
#define PIN_LOW(port, pin)   (port &= ~(1 << (pin)))
#define PIN_HIGH(port, pin)  (port |= (1 << (pin)))

// Set pin direction macro
#define SET_PIN_MODE(tris, pin, direction) \
    do { \
        if (direction) tris |= (1 << (pin)); \
        else tris &= ~(1 << (pin)); \
    } while(0)

#endif