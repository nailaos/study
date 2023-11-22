	.file	"switch.c"
	.text
	.globl	switch_eg
	.type	switch_eg, @function
switch_eg:
.LFB0:
	.cfi_startproc
	movq	%rdx, %rcx
	cmpq	$6, %rdi
	ja	.L9
	leaq	.L4(%rip), %rdx
	movslq	(%rdx,%rdi,4), %rax
	addq	%rdx, %rax
	jmp	*%rax
	.section	.rodata
	.align 4
	.align 4
.L4:
	.long	.L9-.L4
	.long	.L8-.L4
	.long	.L7-.L4
	.long	.L10-.L4
	.long	.L5-.L4
	.long	.L3-.L4
	.long	.L3-.L4
	.text
.L8:
	movq	%rcx, %rax
	imulq	%rsi, %rax
	ret
.L7:
	movq	%rsi, %rax
	cqto
	idivq	%rcx
.L6:
	addq	%rcx, %rax
	ret
.L10:
	movl	$1, %eax
	jmp	.L6
.L5:
	movl	$1, %eax
	subq	%rsi, %rax
	ret
.L3:
	movl	$1, %eax
	subq	%rcx, %rax
	ret
.L9:
	movl	$2, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	switch_eg, .-switch_eg
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
