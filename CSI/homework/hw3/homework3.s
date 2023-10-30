	.file	"homework3.c"
	.text
	.globl	eat_peaches
	.type	eat_peaches, @function
eat_peaches:
.LFB0:
	.cfi_startproc
	cmpl	$10, %edi
	jne	.L8
	movl	$1, %eax
	ret
.L8:
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	addl	$1, %edi
	call	eat_peaches
	leal	2(%rax,%rax), %eax
	addq	$8, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	eat_peaches, .-eat_peaches
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
