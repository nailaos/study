	.file	"fix_set_diag_opt.c"
	.text
	.globl	fix_set_diag_opt
	.type	fix_set_diag_opt, @function
fix_set_diag_opt:
.LFB0:
	.cfi_startproc
	movq	%rdi, %rax
	leaq	2176(%rdi), %rdx
	movslq	%esi, %rsi
.L2:
	movq	%rsi, (%rax)
	addq	$136, %rax
	cmpq	%rax, %rdx
	jne	.L2
	ret
	.cfi_endproc
.LFE0:
	.size	fix_set_diag_opt, .-fix_set_diag_opt
	.globl	fix_set_diag
	.type	fix_set_diag, @function
fix_set_diag:
.LFB1:
	.cfi_startproc
	movq	%rdi, %rax
	leaq	2176(%rdi), %rdx
	movslq	%esi, %rsi
.L5:
	movq	%rsi, (%rax)
	addq	$136, %rax
	cmpq	%rdx, %rax
	jne	.L5
	ret
	.cfi_endproc
.LFE1:
	.size	fix_set_diag, .-fix_set_diag
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
