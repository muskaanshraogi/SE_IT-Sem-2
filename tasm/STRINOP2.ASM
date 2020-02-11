.model small
.stack 100h
.data
	enter_str1    	db      13,10,'Enter a string : ',13,10,'$'
	enter_str2    	db      13,10,'Enter another string : ',13,10,'$'
	equal		db	13,10,'The two strings are equal.',13,10,'$'
       	not_equal		db	13,10,'The two strings are not equal.',13,10,'$'
	cat		db	13,10,'The concatenated string is : ',13,10,'$'
	subs		db	13,10,'Enter a character to check its occurences : ',13,10,'$'
	occur		db	13,10,'The number of occurrences are : ',13,10,'$'
	str1		db	20 dup(?)
	str2		db	20 dup(?)
	len1		dw	0
	len2		dw	0
	occ		dw	0
	char		db	?

.code
	mov ax, @data
	mov ds, ax
	
	public getstring, strcmp, strcat, strsub
	
;	------GET STRING------
	proc getstring
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
		ret
	endp
	
;	------LOOPCMP------
	proc strcmp
		mov cx, len1
		lea si, str1
		lea di, str2
		
		mov ax, len1
		mov bx, len2
		cmp ax, bx
		jne noequ
		
		loopcomp:
		mov al, [si]
		mov bl, [di]
		cmp al, bl
		jne noequ
		inc si
		inc di
		dec cx
		jnz loopcomp
		
		mov ah, 09h
		mov dx, offset equal
		int 21h
		ret
		
		noequ:
		mov ah, 09h
		mov dx, offset not_equal
		int 21h
		ret
	endp
	
;	------LOOPCAT------
	proc strcat
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
		
		mov ax, len2
		add len1, ax
		
		mov ah, 09h
		mov dx, offset cat
		int 21h
		
		mov ah, 09h
		mov dx, offset str1
		int 21h
		ret
	endp
	
;	------SUBLOOP------
	proc strsub
		mov ah, 09h
		mov dx, offset subs
		int 21h
		
		mov ah, 01h
		int 21h
		mov char, al
		
		loopstart:
		mov al, [si]
		mov bl, char
		inc si
		dec cx
		jz  substring
		cmp al, bl
		jne loopstart
		inc occ
		jmp loopstart
		
		substring:
		mov ah, 09h
		mov dx, offset occur
		int 21h
		
		add occ, 30h
		mov dx, occ
		mov ah, 02h
		int 21h
		ret
	endp
end
