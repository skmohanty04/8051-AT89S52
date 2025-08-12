#include<reg51.h>



void config()
{
	  TMOD = 0x01;   // Timer0 Mode1 (16-bit)
    TH0 = 0x3C;
    TL0 = 0xB0;
    TR0 = 1;       // Start timer
}


void main() 
{
	unsigned int program_count = 0;
	int duty_cycle = 1;
	config();
	

    while (1) 
			{
        if (TF0) 
					{
            TF0 = 0;      // Clear overflow flag
						
						
						
						for(program_count = 0; program_count < duty_cycle; program_count++)
						{
							P2 = 0xFF;    // Toggle P1.0
						}
						for(program_count = 0; program_count < (100 - duty_cycle); program_count++)
						{
							P2 = 0x00;
						}
						
						TH0 = 0x3C;
						TL0 = 0xB0;
					}
			}
}