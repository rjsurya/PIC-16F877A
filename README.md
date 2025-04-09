# PIC 16F877A LED Blinker

A simple project demonstrating how to blink an LED using the PIC16F877A microcontroller with custom delay functions based on Timer0. This project uses C language with custom header files to manage I/O and timing operations.

## Overview

This project blinks an LED connected to the RC2 pin of the PIC16F877A microcontroller. The LED is toggled on and off at 500ms intervals using delay functions implemented via Timer0. The code is split into several components:

- **delay.c / delay.h:** Implements and declares delay functions (`delay_us` and `delay_ms`) using Timer0.
- **blink.c:** Contains the main function that initializes the I/O and continuously toggles the LED.
- **io.h:** Defines macros for setting up and controlling I/O ports and pins.

## Features

- **Custom Delay Functions:**  
  Accurate delay functions for microseconds (≥ 50µs) and milliseconds using Timer0 with a 1:256 prescaler.
  
- **Modular Design:**  
  Separation of hardware abstraction (`io.h`) and timing functions (`delay.h`/`delay.c`) for clarity and reusability.
  
- **Simple LED Blinking:**  
  Demonstrates fundamental microcontroller operations like timer initialization, pin configuration, and delay-based execution.

## Hardware Requirements

- **Microcontroller:** PIC16F877A
- **Clock:** 20MHz crystal oscillator
- **LED:** Connected to RC2 (with appropriate current-limiting resistor)
- **Programmer/Debugger:** PICkit or similar tool

## Software Requirements

- **Compiler:** XC8 Compiler or equivalent
- **IDE:** MPLAB X IDE (recommended) or any compatible development environment

##Delay Calculation

-**Example Calculation (100μs delay):**

-**cycles** = 100 × 5 = 500

-**reload_value** = 256 - (500/256) ≈ 256 - 1.95 ≈ 254 (0xFE)

-**Timer counts**: 254 → 255 → overflow (2 counts)

-**Actual delay:** 2 × 51.2μs = 102.4μs (close to requested 100μs)
  

## Project Structure

<br> delay.c // Implementation of delay functions using Timer0 
<br> delay.h // Header file declaring delay functions and Timer0 register definitions 
<br> blink.c // Main application that toggles the LED on RC2 
<br> io.h // I/O definitions and macros for pin manipulation 
