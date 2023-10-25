	.file	"main.c"
	.text
	.type	intra_sum, @function
intra_sum:
.LFB0:
	.cfi_startproc
	movslq	%esi, %rsi
	movl	-4(%rdi,%rsi,4), %eax
	ret
	.cfi_endproc
.LFE0:
	.size	intra_sum, .-intra_sum
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movl	$3, %esi
	leaq	array(%rip), %rdi
	call	intra_sum
	movl	%eax, %ebx
	movl	$3, %esi
	leaq	barray(%rip), %rdi
	call	intra_sum
	addl	%ebx, %eax
	js	.L6
.L2:
	popq	%rbx
	.cfi_remember_state
	.cfi_def_cfa_offset 8
	ret
.L6:
	.cfi_restore_state
	movl	$-1, %eax
	jmp	.L2
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.data
	.align 16
	.type	barray, @object
	.size	barray, 16
barray:
	.long	1
	.long	2
	.long	3
	.long	4
	.globl	array
	.align 16
	.type	array, @object
	.size	array, 16
array:
	.long	1
	.long	2
	.long	3
	.long	4
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
