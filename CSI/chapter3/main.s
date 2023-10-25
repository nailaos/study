	.file	"main.cpp"
	.text
	.globl	_Z3addv
	.type	_Z3addv, @function
_Z3addv:
.LFB0:
	.cfi_startproc
	movl	y(%rip), %eax
	addl	x(%rip), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	_Z3addv, .-_Z3addv
	.globl	y
	.bss
	.align 4
	.type	y, @object
	.size	y, 4
y:
	.zero	4
	.globl	x
	.data
	.align 4
	.type	x, @object
	.size	x, 4
x:
	.long	1
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
