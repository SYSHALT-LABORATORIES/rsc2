
ch_charset437:

	mov $0x0003, %ax				; 80x25 vga color mode
	int $0x10
	
	mov 0x114, %ax

	xor %bx, %bx
	xor %dx, %dx

	int $0x10

	mov $0x6601, %ax 				; Codepage...
	mov $0x1b5, %bx                          ; (...) + 437
	int $0x21

