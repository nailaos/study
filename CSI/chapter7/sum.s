	.file	"sum.c"
	.text
	.globl	sum
	.type	sum, @function
sum:
.LFB0:
	.cfi_startproc
	movl	$0, %eax
	movl	$0, %edx
	jmp	.L2
.L3:
	movslq	%eax, %rcx
	addl	(%rdi,%rcx,4), %edx
	addl	$1, %eax
.L2:
	cmpl	%esi, %eax
	jl	.L3
	movl	%edx, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	sum, .-sum
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
