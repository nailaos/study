	.file	"overflow.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%x"
	.text
	.globl	overflow
	.type	overflow, @function
overflow:
.LFB11:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	jmp	.L2
.L3:
	movslq	%ebx, %rax
	movl	8(%rsp), %edx
	movb	%dl, 12(%rsp,%rax)
	leal	1(%rbx), %ebx
.L2:
	leaq	8(%rsp), %rsi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	cmpl	$-1, %eax
	jne	.L3
	movl	$15213, %eax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE11:
	.size	overflow, .-overflow
	.section	.rodata.str1.1
.LC1:
	.string	"Boom!"
.LC2:
	.string	"????"
	.text
	.globl	main
	.type	main, @function
main:
.LFB12:
	.cfi_startproc
	subq	$8, %rsp
	.cfi_def_cfa_offset 16
	call	overflow
	addl	one(%rip), %eax
	cmpl	$15213, %eax
	je	.L6
	leaq	.LC1(%rip), %rdi
	call	puts@PLT
.L7:
	movl	$0, %eax
	addq	$8, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	leaq	.LC2(%rip), %rdi
	call	puts@PLT
	jmp	.L7
	.cfi_endproc
.LFE12:
	.size	main, .-main
	.globl	one
	.data
	.align 4
	.type	one, @object
	.size	one, 4
one:
	.long	1
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
