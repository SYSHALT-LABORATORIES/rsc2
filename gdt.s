gdt_comeco:
	dq 0x00

codigo_gdt:
	dw 0xffff
	dw 0x00
	db 0x00
	db 1011010b
	db 11001111b
	db 0x00

gdt_dados:
	dw 0xffff
	dw 0x00
	db 0x00
	db 10010010b
	db 11001111b
	db 0x00

gdt_fim:
	
gdt_descritor:
	dw gdt_fim - gdt_comeco -1 
	dd gdt_comeco


CODE_SEG equ codigo_gdt - gdt_comeco
DATA_SEG equ gdt_dados - gdt_comeco
