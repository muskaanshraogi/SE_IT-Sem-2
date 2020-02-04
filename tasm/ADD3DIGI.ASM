.model small
.stack 100h
.data
	units	dw	?
	tens	dw	?
	hund	dw	?
	
.code
	mov ax,@data
	mov ds,ax
	
	mov ax,215
	mov bx,125
	add ax,bx
	
	mov bx,10
	
	xor dx,dx
	div bx
	mov units,dx
	add units,30h
	
	xor dx,dx
	div bx
	mov tens,dx
	add tens,30h

	xor dx,dx
	div bx
	mov hund,dx
	add hund,30h
	
	mov dx,hund
	mov ah,02h
	int 21h
	
	mov dx,tens
	mov ah,02h
	int 21h
	
	mov dx,units
	mov ah,02h
	int 21h
	
	mov ah,4ch
	int 21h
end
	
