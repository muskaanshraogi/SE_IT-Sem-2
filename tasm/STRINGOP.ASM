.model small
.stack 100h
.data
        enter_str    	db      13,10,'Enter a string : ',13,10,'$'
        print_len	db	13,10,'The length of the string is : ',13,10,'$'
        rev		db	13,10,'The reversed string is : ',13,10,'$'
        pal		db	13,10,'The given string is a palindrome.',13,10,'$'
	notpal		db	13,10,'The given string is not a palindrome.',13,10,'$'
	menu		db	13,10,'***STRING MENU***',13,10,'1) String Length',13,10,'2) Reverse String',13,10,'3) Check Palindrome',13,10,'4)Exit',13,10,'$'
	str1		db	20 dup(?)
	str2		db	20 dup(?)
	len		dw	0
	len1		dw	0
	
.code

	mov ax, @data
	mov ds, ax
	
	mov ah, 09h
	mov dx, offset enter_str
	int 21h
	
	lea si, str1

;	------GET STRING------	
	loop1:
	mov ah, 01h
	int 21h
	mov [si], al
	inc si
	inc len
	cmp al, 13
	jne loop1
	
	mov ax, len
	mov len1, ax
	sub len, 1
	add len, 30h
	

;	------MENU------		
	loopmenu:
	mov ah, 09h
	mov dx, offset menu
	int 21h
	mov ah, 01h
	int 21h
	cmp al, 31h
	je  looplen
	cmp al, 32h
	je  looprev
	cmp al, 33h
	je  looppal
	cmp al, 34h
	je  loopend
	
;	------STRING LENGTH------
	looplen:
	
	
	mov ah,09h
	mov dx, offset print_len
	int 21h
	
	mov dx, len
	mov ah, 02h
	int 21h
	jmp loopmenu
	
;	------STRING REVERSE------
	looprev:
	lea si, str1
	add si, len1
	lea di, str2
	
	loop2:
	mov bl, [si]
	mov [di], bl
	dec si
	inc di
	cmp di, len
	jne loop2
	
	mov al, '$'
	mov [di], al
	
	mov ah, 09h
	mov dx, offset rev
	int 21h
	
	mov ah, 09h
	mov dx, offset str2
	int 21h
	jmp loopmenu
	
;	------PALINDROME------
	looppal:
	sub len1, 1
	
	lea si, str1
	lea di, str1
	add di, len1
	sub di, 1
	mov cx, len1
	
	loop3:
	mov al, [si]
	mov bl, [di]
	cmp al, bl
	jne nopal
	inc si
	dec di
	dec cx
	jnz loop3
	
	mov ah, 09h
	mov dx, offset pal
	int 21h
	jmp loopmenu
	
	
	nopal:
	mov ah, 09h
	mov dx, offset notpal
	int 21h
	jmp loopmenu
	
	
;	------END------
	loopend:
	mov ah, 4ch
	int 21h
end	
