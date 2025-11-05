/* SYSHALT LABORATORIES
   1996-2025 (c)
   SYSCALLS FOR RSC2 */

#ifndef _WIN32
#define _RSC2PURE
#endif

#ifdef _RSC2PURE
/* typedefs */

typedef uint8_t                                           u8;
typedef uint64_t                                          u64;
typedef uint32_t                                          u32;
typedef signed           char                             i8;
typedef unsigned         int                              u16;
typedef signed           int                              i16;
typedef signed long long int                              i64;
typedef                  int                              i128;
typedef                  char*                            string;

/* syscalls */

void ch_charset437(void) {
	_asm("mov ax, 0x0003 ; vid mode 3 (80x25 color text)\n\t
		"int 0x10\n\t"
		"mov ax, 0x1104\n\t"
		"xor bx, bx     ; set to zero\n\t"
		"xor dx, dx     ; set to zero, also.\n\t"
		"int 0x10\n\t"
		"mov ax, 0x6601\n\t"
		"mov bx, 0x1b5\n\t"
		"int 0x21\n\t"");

}
#endif
