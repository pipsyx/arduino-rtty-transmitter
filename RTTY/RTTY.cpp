#include "baudot.h"
#include "RTTY.h"

#define BAUD_RATE 22 // 45.45 baud
#define MARK 2125
#define SPACE 1955

RTTY5::RTTY5()
{
}

void RTTY5::attach(byte pin)
{
    rtty_pin = pin;
    pinMode(rtty_pin, OUTPUT);
    tone(rtty_pin, MARK);
}


void RTTY5::tx(char* string)
{
    char c = *string++;
    byte index = 0, pos = 0;
    byte shift = 0;
    
    while (c != '\0')
    {
        char* index = strchr(BAUDOT_FIGS, c);
        if(index != NULL) {
            pos = index - BAUDOT_FIGS;
            if(pos > 2 && shift != 1) {
                shift = 1;
                rtty_txbyte(BAUDOT_SHIFT_FIGS);
            }
            rtty_txbyte (baudot[pos]);
        } else {
            c = toupper(c);
            index = strchr(BAUDOT_LTRS, c);
            pos = index - BAUDOT_LTRS;
            if(pos > 2 && shift != 2) {
                shift = 2;
                rtty_txbyte(31);
            }
            rtty_txbyte (baudot[pos]);
        }
        c = *string++;
    }
}


void RTTY5::rtty_txbyte (byte c)
{
    
    
    rtty_txbit (0); // Start bit
    // Send bits for for char MSB first
    for (byte i = 5; i > 0; --i)
    {
        if ((c & (1 << (i-1))) != 0)
            rtty_txbit(1);
        else
            rtty_txbit(0);
    }
    rtty_txbit (1); // Stop bits
    rtty_txbit (1);
}

void RTTY5::rtty_txbit (bool bit)
{
    if (bit)
    {
        // MARK
        tone(rtty_pin, MARK);
    }
    else
    {
        // SPACE
        tone(rtty_pin, SPACE);
    }
    
    delay(BAUD_RATE);
}

// Set the default object
RTTY5 RTTY = RTTY5();
