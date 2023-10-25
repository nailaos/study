	.file	"test.c"
	.text
	.globl	test
	.type	test, @function
test:
.LFB0:
	.cfi_startproc
	leaq	0(,%rdi,8), %rax
	testq	%rsi, %rsi
	jle	.L2
	cmpq	%rsi, %rdi
	jge	.L3
	movq	%rsi, %rax
	subq	%rdi, %rax
	ret
.L3:
	movq	%rdi, %rax
	andq	%rsi, %rax
	ret
.L2:
	cmpq	$-1, %rsi
	jl	.L5
.L1:
	ret
.L5:
	leaq	(%rdi,%rsi), %rax
	jmp	.L1
	.cfi_endproc
.LFE0:
	.size	test, .-test
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
