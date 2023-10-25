	.file	"for.c"
	.text
	.globl	foo
	.type	foo, @function
foo:
.LFB0:
	.cfi_startproc
	leal	-1(%rsi), %eax
	jmp	.L2
.L4:
	subl	$1, %eax
.L2:
	testl	%eax, %eax
	js	.L1
	movslq	%eax, %rcx
	cmpl	%edx, (%rdi,%rcx,4)
	jne	.L4
.L1:
	ret
	.cfi_endproc
.LFE0:
	.size	foo, .-foo
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
