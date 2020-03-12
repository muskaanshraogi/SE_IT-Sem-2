
org 0000
ljmp start

start:
mov r1, #40h
clr a

addloop:
add a, @r1
inc r1
djnz 30h, addloop

mov r6, a
mov r7, a

here: sjmp here

end