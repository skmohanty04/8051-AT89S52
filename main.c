
#include <reg51.h>   // Only include this once


void main() {
	
    TMOD = 0x01;   // Timer0 Mode1 (16-bit)
    TH0 = 0x3C;
    TL0 = 0xB0;
    TR0 = 1;       // Start timer

    while (1) {
        if (TF0) {
            TF0 = 0;       // Clear overflow flag
            P2 ^= 0x01;    // Toggle P1.0
            TH0 = 0x3C;
            TL0 = 0xB0;
        }
    }
}