	.file	"switch.c"
	.text
	.globl	switcg_eg
	.type	switcg_eg, @function
switcg_eg:
.LFB0:
	.cfi_startproc
	movq	%rdx, %rcx
	cmpq	$3, %rdi
	je	.L8
	jg	.L3
	cmpq	$1, %rdi
	je	.L4
	cmpq	$2, %rdi
	jne	.L11
	movq	%rsi, %rax
	cqto
	idivq	%rcx
.L2:
	addq	%rcx, %rax
	ret
.L11:
	movl	$2, %eax
	ret
.L3:
	subq	$5, %rdi
	cmpq	$1, %rdi
	ja	.L12
	movl	$1, %eax
	subq	%rdx, %rax
	ret
.L4:
	movq	%rdx, %rax
	imulq	%rsi, %rax
	ret
.L8:
	movl	$1, %eax
	jmp	.L2
.L12:
	movl	$2, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switcg_eg, .-switcg_eg
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
