
org 0000
ljmp start

start:
mov r1, #10h
mov dptr, #40h

moveloop:
mov a, @r1
movx @dptr, a
inc r1
inc dptr
djnz 30h, moveloop

here: sjmp here

end