[bits 16]
dobrar_bits:
	cli
	lgdt [gdt_descritor]
	mov eax, cr0
	or eax, 0x1
	mov cr0, eax
	jmp CODE_SEG:init_32bit
	
[bits 32]
init_32bit:
	mov ax, DATA_SEG
	mov ds, ax
	mov ss, ax
	mov es, ax
	mov fs, ax
	mov gs, ax
	
	mov ebp, 0x90000
	mov esp, ebp
	
	call comecar_trintadois
