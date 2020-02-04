.model small
.stack 100h
.data
	sum	db	13,10,'***ADDITION***',13,10,'1)Hexadecimal value',13,10,'2)Decimal value',13,10,'3)Exit',13,10,'$'
	hexa	db	13,10,'The sum in hexadecimal is : ',13,10,'$'
	deci	db	13,10,'The sum in decimal is : ',13,10,'$'
	num	dw	?
	units	dw	?
	tens	dw	?
	hund	dw	?
	choice	dw	?
	
.code
	mov ax,@data
	mov ds,ax
	
	mov ax,215
	mov bx,125
	add ax,bx
	mov num,ax
	
;	----------------MENU------------------
	loopmenu:
	mov ah, 09h
	mov dx, offset sum
	int 21h
	
	mov ah, 01h
	int 21h
	cmp al, 31h
	je loophex
	cmp al, 32h
	je loopdec
	cmp al, 33h
	je tramp
	
	
;	-------------Decimal-----------------
	loopdec:
	
	mov ah, 09h
	mov dx, offset deci
	int 21h
	
	mov ax, num
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
	jmp loopmenu
	
	tramp:
	jmp loopexit
	
;	-------------Hexadecimal--------------
	loophex:
	
	mov ah, 09h
	mov dx, offset hexa
	int 21h
	
	mov ax, num
	mov bx,16
	
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
	jmp loopmenu
	
	loopexit:
	mov ah,4ch
	int 21h
end
	
