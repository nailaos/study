	.file	"sum.c"
	.text
	.globl	sumstore
	.type	sumstore, @function
sumstore:
.LFB0:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	movq	%rdx, %rbx
	call	plus
	movq	%rax, (%rbx)
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE0:
	.size	sumstore, .-sumstore
	.globl	swap
	.type	swap, @function
swap:
.LFB1:
	.cfi_startproc
	movl	(%rdi), %eax
	movl	(%rsi), %edx
	movl	%edx, (%rdi)
	movl	%eax, (%rsi)
	ret
	.cfi_endproc
.LFE1:
	.size	swap, .-swap
	.globl	swap1
	.type	swap1, @function
swap1:
.LFB2:
	.cfi_startproc
	movzwl	(%rdi), %eax
	movzwl	(%rsi), %edx
	movw	%dx, (%rdi)
	movw	%ax, (%rsi)
	ret
	.cfi_endproc
.LFE2:
	.size	swap1, .-swap1
	.globl	swap2
	.type	swap2, @function
swap2:
.LFB3:
	.cfi_startproc
	movq	(%rdi), %rax
	movq	(%rsi), %rdx
	movq	%rdx, (%rdi)
	movq	%rax, (%rsi)
	ret
	.cfi_endproc
.LFE3:
	.size	swap2, .-swap2
	.ident	"GCC: (Debian 12.2.0-14) 12.2.0"
	.section	.note.GNU-stack,"",@progbits
