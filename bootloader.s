[bits 16]
[org 0x7c00]

mov si, 0

KERNEL_OFFSET equ 0x1000 ; onde vamos carregar o kernel
mov dl, [BOOT_DRIVE]

; iniciar pilha
mov bp, 0x9000
mov sp, bp

call carregar_kernel
call dobrar_bits

jmp $

%include "disco.s"
%include "gdt.s"
%include "bits2vezes.s"

carregar_kernel:
	mov bx, KERNEL_OFFSET 		; bx -> Destino
	mov dh, 2 			        ; dh -> Numero setores
	mov dl, [BOOT_DRIVE]		; dl -> Disco
	call carregar_disco
	ret
imprima:
	mov ah, 0x0e
	mov al, [texto + si]
	int 0x10
	add si, 1
	cmp byte [texto + si], 0
	jne imprima

jmp $

texto:
	db "Koading kernel...", 0

comecar_trintadois:
	call KERNEL_OFFSET		; dar controle ao kernel
	jmp $				    ; voltar aqui em caso o kernel morra

; variavel hd boot
BOOT_DRIVE db 0

; fechar o padding com 0
times 510 - ($ - $$) db 0
dw 0xAA55
