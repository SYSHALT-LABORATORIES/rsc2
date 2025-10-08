carregar_disco:
	pusha
	push dx
	mov ah, 0x02	 ; modo ler
	mov al, dh	 ; ler numero dh
	mov cl, 0x02 	 ; começar de setor 2
	
	mov ch, 0x00	 ; C Num 0
	mov dh, 0x00	 ; H num 0

	; dl = numero de disco definido como entrada para carregar_disco
	; es:bx = ponteiro de buffer é entrada tbm

	int 0x13 ; interromper bios, disquete
	jc erro_disco

	pop dx
	cmp al, dh

	jne erro_setor
	popa
	ret

erro_disco:
	jmp loop_disco

erro_setor:
	jmp loop_disco
loop_disco:
	jmp $
