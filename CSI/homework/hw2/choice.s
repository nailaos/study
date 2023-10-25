	.file	"choice.c"
	.text
	.globl	choice1
	.type	choice1, @function
choice1:
.LFB0:
	.cfi_startproc
	movl	%edi, %eax
	shrl	$31, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	choice1, .-choice1
	.globl	choice2
	.type	choice2, @function
choice2:
.LFB1:
	.cfi_startproc
	movl	$0, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	choice2, .-choice2
	.globl	choice3
	.type	choice3, @function
choice3:
.LFB2:
	.cfi_startproc
	movl	%edi, %eax
	sall	$4, %eax
	subl	%edi, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	choice3, .-choice3
	.globl	choice4
	.type	choice4, @function
choice4:
.LFB3:
	.cfi_startproc
	leal	18(%rdi), %eax
	addl	$15, %edi
	cmovns	%edi, %eax
	sarl	$2, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	choice4, .-choice4
	.globl	choice5
	.type	choice5, @function
choice5:
.LFB4:
	.cfi_startproc
	leal	15(%rdi), %eax
	testl	%edi, %edi
	cmovns	%edi, %eax
	sarl	$4, %eax
	ret
	.cfi_endproc
.LFE4:
	.size	choice5, .-choice5
	.globl	choice6
	.type	choice6, @function
choice6:
.LFB5:
	.cfi_startproc
	movl	%edi, %eax
	sarl	$31, %eax
	ret
	.cfi_endproc
.LFE5:
	.size	choice6, .-choice6
	.globl	div
	.type	div, @function
div:
.LFB6:
	.cfi_startproc
	movl	%edi, %eax
	sarl	$4, %eax
	ret
div2:
.LFB7:
	.cfi_startproc
	leal	15(%rdi), %eax
	testl	%edi, %edi
	cmovns	%edi, %eax
	sarl	$4, %eax
	ret
