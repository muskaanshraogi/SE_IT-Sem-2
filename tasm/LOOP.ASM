.model small
.stack 100h
.data
        msg     db      'The numbers are',13,10,'$'
      

.code
        mov ax,@data
        mov ds,ax

        lea dx,msg
        mov ah,09h
        int 21h

        mov cx,10

        mov ah,02h
        mov dl,48

loop:   int 21h
        inc dl
        dec cx
        jnz loop

        mov ah,4ch
        int 21h
end

