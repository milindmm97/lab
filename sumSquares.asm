NAME main
PUBLIC __iar_program_start
SECTION datas:CONST(2)
num
dc32 0x0A
sum
ds32 1
SECTION .intvec:CODE:NOROOT (2)
__iar_program_start
main
ldr r6,num
ldr r0,=thumbcode
mov lr,pc
bx r0
str r1,sum
stop b stop
code16
thumbcode
mov r4,r6
mov r1,#0x00
loop mul r6,r4
add r1,r1,r6
sub r4,#1
mov r6,r4
bne loop
here bx lr
end
