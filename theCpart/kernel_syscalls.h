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

void ch_charset437() {
	__asm("nop");//                              Asm segfaults need to figure out
}

#endif
