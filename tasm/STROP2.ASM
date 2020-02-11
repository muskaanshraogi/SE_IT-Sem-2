.model small
.stack 100h
.data

	menu		db	13,10,'***STRING MENU***',13,10,'1) Compare strings',13,10,'2) Concatenate strings',13,10,'3) Check Substring',13,10,'4)Exit',13,10,'$'
	
.code
	extrn getstring : far
	extrn strcmp : far
	extrn strcat : far
	extrn strsub : far
	
	mov ax, @data
	mov ds, ax
	
	call getstring
	
;	------MENU------		
	loopmenu:
	mov ah, 09h
	mov dx, offset menu
	int 21h
	mov ah, 01h
	int 21h
	
	cmp al, 31h
	je  A
	cmp al, 32h
	je  B
	cmp al, 33h
	je  C
	cmp al, 34h
	je loopend
	
	
A:
call strcmp
jmp loopmenu
	
B:
call strcat
jmp loopmenu

C:
call strsub
jmp loopmenu
	
;	------END------
	loopend:
	mov ah, 4ch
	int 21h
end	
