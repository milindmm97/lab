#include "xstdsys.h"
 
// Connect From P0.0 ,P0.8 ,P0.16 ,P0.24 to Led
void Delay(unsigned int dms);
void InitLPC(void);


unsigned int delay_ms,led_val;
unsigned char index;




void InitLPC(void)
{

        	// use the Wizards (see Wizards menu) to configure the on-chip peripherals
	PINSEL0 = 0x00L;
	g_pGPIO0->IODIR = 0XFFFFFFFF;
}




void Delay(unsigned int dms)
{
	// the timer has to work for this loop to function
	delay_ms = dms;
	while(delay_ms > 0)
	{
	 	delay_ms--;
	}
}


main()
{
        // use the Wizards (see Wizards menu) to configure the on-chip peripherals
        index=0;
        InitLPC();
       	while(1)
	{
		//Get Flash Data
                index &= 0xffffffff;
                //change the array from mvleft to mvright
                led_val = index;

                //Start moving LED
                 g_pGPIO0->IOSET =led_val;
		//Software Delay from 1 to 50,000
		Delay(200000);
		//Turn LED's OFF
                g_pGPIO0->IOCLR=0xFFFFFFFF;
		index++;
	}     

}
