
#ifndef delay_H
#define delay_H
#define OPT_REG (*(volatile unsigned char *)0x81)  // OPTION_REG
#define TIMER0 (*(volatile unsigned char *)0x01)  // TMR0
#define TIME_INT (*(volatile unsigned char *)0x0B)  // INTCON
void Timer0_Init();
void delay_us(unsigned int microseconds);
void delay_ms(unsigned int milliseconds);
#endif