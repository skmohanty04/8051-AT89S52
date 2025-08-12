#include <reg51.h>
#include "sevensegment.h"

unsigned int number = 0;
unsigned char currentDigit = 0;

void config(void) {
    TMOD = 0x01;     // Timer0 Mode 1: 16-bit
    TH0 = 0xFC;      // ~1 ms reload
    TL0 = 0x66;
    TR0 = 1;         // Start Timer0
    P0 = 0x00;
}

void main(void) {
    unsigned int msCount = 0;
    config();

    while (1) {
        if (TF0) {
            TF0 = 0;
            TH0 = 0xFC;
            TL0 = 0x66;

            // Alternate digits every 1 ms for time division multiplexing .
            if (currentDigit == 0) {
                displayDigit(number / 10, 2); // Tens
                currentDigit = 1;
            } else {
                displayDigit(number % 10, 1); // Units
                currentDigit = 0;
            }

            // Count milliseconds
            msCount++;
            if (msCount >= 1000) { // 1 second
                msCount = 0;
                number++;
                if (number >= 100) number = 0;
            }
        }
    }
}