
// PIC18F45K22 Configuration Bit Settings

// 'C' source line config statements

// CONFIG1H
#pragma config FOSC = INTIO67   // Oscillator Selection bits (EC oscillator (medium power, 500 kHz-16 MHz))
#pragma config PLLCFG = OFF     // 4X PLL Enable (Oscillator used directly)
#pragma config PRICLKEN = ON    // Primary clock enable bit (Primary clock is always enabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enable bit (Fail-Safe Clock Monitor disabled)
#pragma config IESO = OFF       // Internal/External Oscillator Switchover bit (Oscillator Switchover mode disabled)

// CONFIG2L
#pragma config PWRTEN = OFF     // Power-up Timer Enable bit (Power up timer disabled)
#pragma config BOREN = SBORDIS  // Brown-out Reset Enable bits (Brown-out Reset enabled in hardware only (SBOREN is disabled))
#pragma config BORV = 190       // Brown Out Reset Voltage bits (VBOR set to 1.90 V nominal)

// CONFIG2H
#pragma config WDTEN = ON       // Watchdog Timer Enable bits (WDT is always enabled. SWDTEN bit has no effect)
#pragma config WDTPS = 32768    // Watchdog Timer Postscale Select bits (1:32768)

// CONFIG3H
#pragma config CCP2MX = PORTC1  // CCP2 MUX bit (CCP2 input/output is multiplexed with RC1)
#pragma config PBADEN = ON      // PORTB A/D Enable bit (PORTB<5:0> pins are configured as analog input channels on Reset)
#pragma config CCP3MX = PORTB5  // P3A/CCP3 Mux bit (P3A/CCP3 input/output is multiplexed with RB5)
#pragma config HFOFST = ON      // HFINTOSC Fast Start-up (HFINTOSC output and ready status are not delayed by the oscillator stable status)
#pragma config T3CMX = PORTC0   // Timer3 Clock input mux bit (T3CKI is on RC0)
#pragma config P2BMX = PORTD2   // ECCP2 B output mux bit (P2B is on RD2)
#pragma config MCLRE = EXTMCLR  // MCLR Pin Enable bit (MCLR pin enabled, RE3 input pin disabled)

// CONFIG4L
#pragma config STVREN = ON      // Stack Full/Underflow Reset Enable bit (Stack full/underflow will cause Reset)
#pragma config LVP = ON         // Single-Supply ICSP Enable bit (Single-Supply ICSP enabled if MCLRE is also 1)
#pragma config XINST = OFF      // Extended Instruction Set Enable bit (Instruction set extension and Indexed Addressing mode disabled (Legacy mode))

// CONFIG5L
#pragma config CP0 = OFF        // Code Protection Block 0 (Block 0 (000800-001FFFh) not code-protected)
#pragma config CP1 = OFF        // Code Protection Block 1 (Block 1 (002000-003FFFh) not code-protected)
#pragma config CP2 = OFF        // Code Protection Block 2 (Block 2 (004000-005FFFh) not code-protected)
#pragma config CP3 = OFF        // Code Protection Block 3 (Block 3 (006000-007FFFh) not code-protected)

// CONFIG5H
#pragma config CPB = OFF        // Boot Block Code Protection bit (Boot block (000000-0007FFh) not code-protected)
#pragma config CPD = OFF        // Data EEPROM Code Protection bit (Data EEPROM not code-protected)

// CONFIG6L
#pragma config WRT0 = OFF       // Write Protection Block 0 (Block 0 (000800-001FFFh) not write-protected)
#pragma config WRT1 = OFF       // Write Protection Block 1 (Block 1 (002000-003FFFh) not write-protected)
#pragma config WRT2 = OFF       // Write Protection Block 2 (Block 2 (004000-005FFFh) not write-protected)
#pragma config WRT3 = OFF       // Write Protection Block 3 (Block 3 (006000-007FFFh) not write-protected)

// CONFIG6H
#pragma config WRTC = OFF       // Configuration Register Write Protection bit (Configuration registers (300000-3000FFh) not write-protected)
#pragma config WRTB = OFF       // Boot Block Write Protection bit (Boot Block (000000-0007FFh) not write-protected)
#pragma config WRTD = OFF       // Data EEPROM Write Protection bit (Data EEPROM not write-protected)

// CONFIG7L
#pragma config EBTR0 = OFF      // Table Read Protection Block 0 (Block 0 (000800-001FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR1 = OFF      // Table Read Protection Block 1 (Block 1 (002000-003FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR2 = OFF      // Table Read Protection Block 2 (Block 2 (004000-005FFFh) not protected from table reads executed in other blocks)
#pragma config EBTR3 = OFF      // Table Read Protection Block 3 (Block 3 (006000-007FFFh) not protected from table reads executed in other blocks)

// CONFIG7H
#pragma config EBTRB = OFF      // Boot Block Table Read Protection bit (Boot Block (000000-0007FFh) not protected from table reads executed in other blocks)

// #pragma config statements should precede project file includes.
// Use project enums instead of #define for ON and OFF.

#include <xc.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <pic18f45k22.h>
#define _XTAL_FREQ 8000000

unsigned short current_digit;
int  count = 0;
int intCounter = 0;

  unsigned short i = 50;
  unsigned short seconds = 40;
  unsigned short minute = 59;
  unsigned short hour = 12;
unsigned int seg[]={0x02, //Hex value to display the number 0
                    0x9E, //Hex value to display the number 1
                    0x24, //Hex value to display the number 2
                    0x0C, //Hex value to display the number 3
                    0x98, //Hex value to display the number 4
                    0x48, //Hex value to display the number 5
                    0x40, //Hex value to display the number 6
                    0x1E, //Hex value to display the number 7
                    0x00, //Hex value to display the number 8
                    0x08  //Hex value to display the number 9
                   }; //End of Array for displaying numbers from 0 to 9
void disp(unsigned short second)
{

    unsigned short min1 = minute % 10; //minute % 10;
    unsigned short min2 = minute / 10; //minute / 10;
    unsigned short hour1 = (hour) % 10; //hour % 10;
    unsigned short hour2 = (hour) / 10; //hour / 10;
    
    //------- HOURS --------
    PORTB = 0x02;
    PORTD = seg[hour2] + 1;
    if(i == 0)
    {
        PORTD = seg[hour2] + 1;
        
    }
    else
    {
        PORTD = seg[hour2];
    }
    __delay_ms(5);
    PORTB = 0x04;
    if(i == 1)
    {
        PORTD = seg[hour1] + 1;
        
    }
    else
    {
        PORTD = seg[hour1];
    }
    __delay_ms(5);
    
    //------- MINUTES ------
    PORTB = 0x08;
    if(i == 2)
    {
        PORTD = seg[min2] + 1;
        
    }
    else
    {
        PORTD = seg[min2];
    }
    __delay_ms(5);
    PORTB = 0x10;   
    if(i == 3)
    {
        PORTD = seg[min1] + 1;
        
    }
    else
    {
        PORTD = seg[min1];
    }
    
}

void main()
{
  OSCCON = 0x60;   // set internal oscillator to 8MHz
  ANSELB = 0;      // configure all PORTB pins as digital
  PORTB  = 0;
  TRISD = 0; 
  TRISB  = 0x1;    // configure RB0, RB1, RB2 & RB3 as output
  INTCONbits.GIE = 0;
  INTCON2 = 0x00;
  INTCON2bits.INTEDG0 = 0; //Interrupt on falling edge
  INTCON2bits.RBPU = 0;
  INTCONbits.INT0F = 0;
  INTCONbits.INT0IE = 1;
  
  
  
  INTCONbits.PEIE=1;        //peripharel interrupt enable
  INTCONbits.TMR0IF = 0x0;  //Clear timer0 overflow interrupt flag
  INTCONbits.TMR0IE = 1;    //enable the timer0 by setting TRM0IE flag
 
  T0CONbits.T08BIT = 0;     // 16 Bit timer
  T0CONbits.T0CS = 0;       // Internal clock
  T0CONbits.PSA = 0;  // Set scaler to 1:4 (CHANGED from 1 to 0 to prescaler get assigned)
  T0CONbits.T0PS0 = 0;
  T0CONbits.T0PS1 = 1;
  T0CONbits.T0PS2 = 0;
  TMR0H = 0x0;  //TMR0H = 0xFF;         // Initial count of 0xF830 (chaneged to 0x3D09)
  TMR0L = 0xFA; //TMR0L = 0xFC;
  T0CONbits.TMR0ON = 1;     // Turn Timer0 
  INTCONbits.GIE = 1;
  
  while(1)
  {
        if(intCounter == 3)
        {   
            (i > 3)? i = 0 : i++;
            intCounter = 0;
            seconds++;   
            if(seconds == 60)
            {
                seconds = 0;
                minute = minute + 1;
                if(minute >= 60)
                {
                    minute = 0;
                    hour++;
                }
                if(hour == 24)hour = 0;
            }
        }
       /* while(count)
        {
            disp(seconds);
            __delay_ms(10);
        }
        */
        disp(seconds);
        __delay_ms(10);
    }
}
 

void __interrupt()  myIsr()
{
    if(TMR0IF == 1)
    {
        TMR0IF = 0;
        intCounter++;
    }
    else if(INT0IF == 1)
    {
        INT0IF = 0;
        minute++;
    }
}
 