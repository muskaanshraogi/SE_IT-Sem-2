.model small
.stack 100h
.data
	enter_str1    	db      13,10,'Enter a string : ',13,10,'$'
	enter_str2    	db      13,10,'Enter another string : ',13,10,'$'
	cat		db	13,10,'The concatenated string is : ',13,10,'$'
       	str1		db	20 dup(?)
       	str2		db	20 dup(?)
       	len1		dw	0
       	len2		dw	0
       	
.code
	mov ax, @data
	mov ds, ax
	
	mov ah, 09h
	mov dx, offset enter_str1
	int 21h
	
	lea si, str1

	loop1:
	mov ah, 01h
	int 21h
	mov [si], al
	inc si
	inc len1
	cmp al, 13
	jne loop1
	
	sub len1, 1
;	add len1, 30h
	
	mov ah, 09h
	mov dx, offset enter_str2
	int 21h
	
	lea si, str2
	
	loop2:
	mov ah, 01h
	int 21h
	mov [si], al
	inc si
	inc len2
	cmp al, 13
	jne loop2
	
	sub len2, 1
;	add len2, 30h

	lea si, str1
	add si, len1
	lea di, str2
	mov cx, len2
	
	loopcat:
	mov al, [di]
	mov [si], al
	inc si
	inc di
	dec cx
	jnz loopcat
	
	mov al, '$'
	mov [si], al
	
	mov ah, 09h
	mov dx, offset cat
	int 21h
	
	mov ah, 09h
	mov dx, offset str1
	int 21h
	
	mov ah, 04ch
	int 21h
end
