NAME main
PUBLIC __iar_program_start
SECTION .data:CONST:NOROOT (2)
num
dc32 0x03,0x01,0x09,0x04,0x08,0x0a
numend
dc32 0x00
len
dc32 (numend-num)/4
SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
code32
ldr r1,=num
ldr r2,len
sub r2,r2,#1
ldr r3,num ; smallest
ldr r4,num;largest
ldr r0,=thumbcode
mov lr,pc
bx r0
stop b stop
code16
thumbcode
loop add r1,#4
ldr r5,[r1,#0]
cmp r5,r3
bpl subss
mov r3,r5
;b l1
subss cmp r5,r4
bmi l1
mov r4,r5
l1 sub r2,#1
cmp r2,#0
bne loop
bx lr
END
