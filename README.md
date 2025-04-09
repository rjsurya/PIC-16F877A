# PIC16F877A Bare Metal Programming

A complete demonstration of bare-metal programming for the PIC16F877A microcontroller without using any pre-built libraries. This project showcases direct register manipulation and hardware-level control.

## Project Overview

This implementation provides:
- Custom hardware abstraction layer (io.h)
- Precise timing using Timer0
- Complete register-level control
- Modular architecture for easy expansion

## Key Features

✅ **True Bare Metal Implementation**  
   - No external libraries used
   - Direct register access
   - Full hardware control

✅ **Custom Hardware Abstraction**  
   - Complete I/O port control
   - Bit manipulation macros
   - Pin direction configuration

✅ **Precise Timing**  
   - Timer0-based delays
   - Microsecond and millisecond precision
   - Configurable prescaler settings

## Hardware Requirements

- PIC16F877A microcontroller
- 20MHz crystal oscillator
- Minimal circuitry (reset, power)
- Optional LED for demonstration

## Timer Calculation
cycles = (desired_time) × (clock_frequency / 4)
Where:
- desired_time in microseconds (μs)
- _XTAL_FREQ in Hz (e.g., 20MHz = 20000000UL)
- Division by 4 converts Fosc to instruction cycle

reload_value = 256 - (total_cycles / timer_steps)
Where:
- 256 = 8-bit timer maximum count (0-255)
- timer_steps = 256 (for 1:256 prescaler)
