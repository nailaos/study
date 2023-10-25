show:
.LFB0:
	.cfi_startproc
	cmpl	%esi, %edi
	jle	.L2
	addl	$1, a(%rip)
	ret
.L2:
	addl	$1, b(%rip)
	ret
	.cfi_endproc
.LFE0:
	.size	show, .-show
	.globl	b
	.bss
	.align 4
	.type	b, @object
	.size	b, 4
b:
	.zero	4
	.globl	a
	.align 4
	.type	a, @object
	.size	a, 4
a:
	.zero	4
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
