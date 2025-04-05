#include <xc.h>
#include"io.h"
#include"delay.h"

void main(void) {
    // Set RC2 as output
    SET_PIN_MODE(targeta, 2, OUTPUT);
    Timer0_Init();
    
    while (1) {
        PIN_HIGH(setporta, 2);   // Set RC2 high
        delay_ms(500);           // Delay 500ms
        PIN_LOW(setporta, 2);    // Set RC2 low
        delay_ms(500);           // Delay 500ms
    }
}