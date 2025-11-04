global ch_charset437

section .text
ch_charset437:

mov ax, 0x0003 ; vid mode 3 (80x25 color text)
int 0x10

mov ax, 0x1104
xor bx, bx     ; set to zero
xor dx, dx     ; set to zero, also.

int 0x10

mov ax, 0x6601
mov bx, 0x1b5
int 0x21

