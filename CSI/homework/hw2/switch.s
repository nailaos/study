switch_eg:
.LFB0:
	.cfi_startproc
	movq	%rdx, %rcx
	cmpq	$2, %rdi
	je	.L2
	cmpq	$3, %rdi
	je	.L3
	cmpq	$1, %rdi
	je	.L4
	movl	$2, %eax
	ret
.L3:
	leaq	1(%rdx), %rax
	ret
.L4:
	movq	%rdx, %rax
	imulq	%rsi, %rax
	ret
.L2:
	movq	%rsi, %rax
	cqto
	idivq	%rcx
	addq	%rcx, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
