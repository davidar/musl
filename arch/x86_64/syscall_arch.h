#define __SYSCALL_LL_E(x) (x)
#define __SYSCALL_LL_O(x) (x)

static __inline long __syscall0(long n)
#ifdef __TINYC__
;
asm (
	".type __syscall0, @function;"
	"__syscall0:;"
	"movq %rdi, %rax;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n) : "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall1(long n, long a1)
#ifdef __TINYC__
;
asm (
	".type __syscall1, @function;"
	"__syscall1:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1) : "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall2(long n, long a1, long a2)
#ifdef __TINYC__
;
asm (
	".type __syscall2, @function;"
	"__syscall2:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"movq %rdx, %rsi;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2)
						  : "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall3(long n, long a1, long a2, long a3)
#ifdef __TINYC__
;
asm (
	".type __syscall3, @function;"
	"__syscall3:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"movq %rdx, %rsi;"
	"movq %rcx, %rdx;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
						  "d"(a3) : "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall4(long n, long a1, long a2, long a3, long a4)
#ifdef __TINYC__
;
asm (
	".type __syscall4, @function;"
	"__syscall4:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"movq %rdx, %rsi;"
	"movq %rcx, %rdx;"
	"movq %r8, %r10;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10): "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall5(long n, long a1, long a2, long a3, long a4, long a5)
#ifdef __TINYC__
;
asm (
	".type __syscall5, @function;"
	"__syscall5:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"movq %rdx, %rsi;"
	"movq %rcx, %rdx;"
	"movq %r8, %r10;"
	"movq %r9, %r8;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8) : "rcx", "r11", "memory");
	return ret;
}
#endif

static __inline long __syscall6(long n, long a1, long a2, long a3, long a4, long a5, long a6)
#ifdef __TINYC__
;
asm (
	".type __syscall6, @function;"
	"__syscall6:;"
	"movq %rdi, %rax;"
	"movq %rsi, %rdi;"
	"movq %rdx, %rsi;"
	"movq %rcx, %rdx;"
	"movq %r8, %r10;"
	"movq %r9, %r8;"
	"movq 8(%rsp), %r9;"
	"syscall;"
	"ret"
);
#else
{
	unsigned long ret;
	register long r10 __asm__("r10") = a4;
	register long r8 __asm__("r8") = a5;
	register long r9 __asm__("r9") = a6;
	__asm__ __volatile__ ("syscall" : "=a"(ret) : "a"(n), "D"(a1), "S"(a2),
						  "d"(a3), "r"(r10), "r"(r8), "r"(r9) : "rcx", "r11", "memory");
	return ret;
}
#endif

#define VDSO_USEFUL
#define VDSO_CGT_SYM "__vdso_clock_gettime"
#define VDSO_CGT_VER "LINUX_2.6"
#define VDSO_GETCPU_SYM "__vdso_getcpu"
#define VDSO_GETCPU_VER "LINUX_2.6"

#define IPC_64 0
