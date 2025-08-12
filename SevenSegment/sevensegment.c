
#include<reg51.h>

#include <reg51.h>

// Common cathode 7-seg patterns for 0–9
// Adjust these values to match your wiring
unsigned char segPatterns[10] = {
    0x40, // 0
    0x79, // 1
    0x24, // 2
    0x30, // 3
    0x19, // 4
    0x12, // 5
    0x02, // 6
    0x78, // 7
    0x00, // 8
    0x10  // 9
};

// Generic function: digitNum = 1 or 2
void displayDigit(unsigned char value, unsigned char digitNum) {
    if (value > 9) return; // Invalid

    P1 = segPatterns[value];    // Segment pattern
    if (digitNum == 1)
        P0 = 0x02; // Enable first digit
    else
        P0 = 0x01; // Enable second digit
}
