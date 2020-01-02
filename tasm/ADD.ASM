.model small
.data
        x   db   03h
        y   db   02h

.code
        mov ax,@data
        mov ds,ax

        mov al,x            ;move x to a reg
        mov bl,y            ;move y to b reg
        add al,bl           ;add contents of reg
        add al,30h          ;30h is hex value of 0

        mov dl,al

        mov ah,2h
        int 21h

        mov ah,4ch
        int 21h
end


