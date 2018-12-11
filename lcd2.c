//Connections:
//P00 to CNLCDDD1
//P08 to CNLCDC1


#include "lpc214x.h"
#include "stdint.h"

unsigned int cmd8_one[] = {0x38,0x0E,0x02,0x01,0x00};
unsigned int cmd8_two[]	= {0X38,0x0E,0x02,0xC0,0x00};

unsigned int msg_one[] = {'H','e','l','l','o',0x20,'R','I','T',0x20,0x00};
unsigned int msg_two[] = {'L','i','n','e',0x20,'T','W','O',0x20,0x00};

unsigned int lcdval,index,delay_ms;

void InitLPC(void)

{
PINSEL0 = 0x00L;
IO0DIR = 0XFFFFFFFF;
}

void Delay(unsigned int dms)

{
delay_ms = dms;
while(delay_ms >0)
{
delay_ms--;
}
}

void InitLCD_one()

{

index=0;

lcdval=cmd8_one[index];

while(lcdval !=0x0)

{

IO0SET = lcdval;
lcdval |= 0x400;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=cmd8_one[index];
}
}

void InitLCD_two()

{

index=0;

lcdval=cmd8_two[index];

while(lcdval !=0x0)

{

IO0SET = lcdval;
lcdval |= 0x400;
IO0SET = lcdval;
Delay(500);
IO0CLR=0xFFFF;
index++;
lcdval=cmd8_two[index];
}
}

void ShowMsg_one()

{

index=0;

lcdval=msg_one[index];

while(lcdval !=0x0)

{

IO0SET = lcdval;

//Toggle E pin

lcdval |= 0x500;

IO0SET = lcdval;

Delay(500);

IO0CLR=0xFFFF;

index++;

lcdval=msg_one[index];
}
}

void ShowMsg_two()

{

index=0;

lcdval=msg_two[index];

while(lcdval !=0x0)

{

IO0SET = lcdval;

//Toggle E pin

lcdval |= 0x500;

IO0SET = lcdval;

Delay(500);

IO0CLR=0xFFFF;

index++;

lcdval=msg_two[index];
}
}

void main(void)

{

InitLPC();
index=0;
InitLCD_one();
ShowMsg_one();
InitLCD_two();
ShowMsg_two();
while(1)
{;}

}
