.model small
.stack 100h
.data
        arr     db      10 dup(?)
        num     db      ?
        msg1    db      13,10,'Enter the total number of numbers:',13,10,'$'
        msg2    db      13,10,'Enter number:',13,10,'$'
        msg3    db      13,10,'The sum is:',13,10,'$'
        line    db      13,10,'$'

.code
        mov ax,@data
        mov ds,ax

        mov ah,09h
        mov dx,offset msg1
        int 21h

        mov ah,01h
        int 21h
        sub al,30h
        mov num,al

        mov cl,num

        L1:
                mov ah,09h
                mov dx,offset msg2
                int 21h

                mov ah,01h
                int 21h
                mov [si],al

                inc si
                dec cl
                jnz L1

        mov ah,09h
        mov dx,offset msg3
        int 21h

        mov cl,num
        mov si,0

        L2:
                mov dl,[si]
                mov ah,02h
                int 21h

                mov ah,09h
                mov dx,offset line
                int 21h

                inc si
                dec cl
                jnz L2

        mov ah,4ch
        int 21h
end
