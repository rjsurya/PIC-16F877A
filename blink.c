/*
 * Description:
 * This code is designed for the PIC16F877A microcontroller to blink an LED connected to the RC2 pin.
 * It configures RC2 as an output, initializes Timer0 for precise delay generation, and then
 * continuously toggles the LED state (on and off) with a delay of 500 milliseconds between each state.
 *
 * Function Overview:
 * - main(): Sets up the microcontroller by configuring the RC2 pin as an output and initializing Timer0.
 *           It then enters an infinite loop where the LED is turned on and off with 500ms delays.
 */

#include <xc.h>
#include <io.h>
#include <delay.h>

void main(void) {
    // Set RC2 as output using custom I/O macro.
    SET_PIN_MODE(targetc,2, OUTPUT);
    
    // Initialize Timer0 for generating accurate delays.
    Timer0_Init();
    
    // Infinite loop: Toggle LED state every 500ms.
    while (1) {
        // Turn on the LED: Set RC2 high.
        PIN_HIGH(setportc, 2);
        // Delay for 500 milliseconds.
        delay_ms(500);
        
        // Turn off the LED: Set RC2 low.
        PIN_LOW(setportc, 2);
        // Delay for 500 milliseconds.
        delay_ms(500);
    }
}
