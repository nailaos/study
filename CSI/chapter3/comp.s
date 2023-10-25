	.file	"comp.c"
	.text
	.globl	comp
	.type	comp, @function
comp:
.LFB0:
	.cfi_startproc
	cmpq	%rdi, %rsi
	setne	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	comp, .-comp
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
