zinrc:
.LFB0:
	movl	$0, %eax
	jmp	.L2
.L3:
	movslq	%eax, %rdx
	leaq	(%rdi,%rdx,4), %rcx
	movl	(%rcx), %esi
	leal	1(%rsi), %edx
	movl	%edx, (%rcx)
	addl	$1, %eax
.L2:
	cmpl	$4, %eax
	jle	.L3
	ret
.LFE0:
