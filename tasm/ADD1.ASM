.model small
.stack 100h
.data
	rem	db	?
.code
	mov ax,@data
	mov ds,ax
	
	mov ax,25
	mov bx,25
	add ax,bx
	
	mov bl,10
	div bl
	
	;add dl,30h
	mov rem,dl
	
	;add al,30h
	mov dl,al
	mov ah,02h
	int 21h
	
	mov dl,rem
	mov ah,02h
	int 21h
	
	mov ah,4ch
	int 21h
end
