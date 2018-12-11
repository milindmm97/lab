/// Initial C Source File
#include "xstdsys.h"
// Connect From P0.0 ,P0.8 ,P0.16 ,P0.24 to Led
// Define all your variables here
unsigned int led_val,delay_ms;
unsigned int mvright[]={0x80808080,0x40404040,0x20202020,0x10101010,0x08080808,0x04040404,0x02020202,0x01010101,0x00};
unsigned char index;
void InitLPC(void)
{
PINSEL0 = 0x00L;
g_pGPIO0->IODIR = 0XFFFFFFFF;
}
void Delay(unsigned int dms)
{
delay_ms = dms;
while(delay_ms > 0)
delay_ms--;
}
main()
{
index=0;
InitLPC();
while(1)
{
index &= 0x7;
led_val = mvright[index++];
g_pGPIO0->IOSET =led_val;
Delay(20000);
g_pGPIO0->IOCLR=0xFFFFFFFF;
}
}
