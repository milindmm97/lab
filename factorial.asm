NAME main
PUBLIC __iar_program_start
SECTION datas:CONST(2)
num
dc32 0x05
fact
ds32 1
SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
ldr r6,num
ldr r0,=thumbcode
blx r0
str r6,fact
stop b stop
code16
thumbcode
mov r4,r6
loop sub r4,#1
beq here
mul r6,r4
b loop
here
bx lr
END
