	.file	"matrix.c"
	.text
	.globl	return_entry
	.type	return_entry, @function
return_entry:
.LFB0:
	.cfi_startproc
	movslq	%esi, %rsi
	movslq	%edi, %rdi
	leaq	(%rsi,%rsi,2), %rdx
	leaq	(%rdi,%rdi,4), %rax
	leaq	(%rdi,%rax,4), %rax
	salq	$3, %rax
	leaq	(%rax,%rdx,8), %rax
	leaq	matrix(%rip), %rdx
	movswl	16(%rdx,%rax), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	return_entry, .-return_entry
	.globl	matrix
	.bss
	.align 32
	.type	matrix, @object
	.size	matrix, 840
matrix:
	.zero	840
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
