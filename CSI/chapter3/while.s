	.file	"while.c"
	.text
	.globl	_do
	.type	_do, @function
_do:
.LFB0:
	.cfi_startproc
	movl	$4294967295, %eax
.L2:
	imulq	%rdi, %rax
	subq	$1, %rdi
	cmpq	$1, %rdi
	jg	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	_do, .-_do
	.globl	_while
	.type	_while, @function
_while:
.LFB1:
	.cfi_startproc
	movabsq	$4294967296, %rax
	jmp	.L4
.L5:
	imulq	%rdi, %rax
	subq	$1, %rdi
.L4:
	cmpq	$1, %rdi
	jg	.L5
	ret
	.cfi_endproc
.LFE1:
	.size	_while, .-_while
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
