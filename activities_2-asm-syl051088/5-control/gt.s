	.file	"gt.c"
	.text
	.globl	gt
	.type	gt, @function
gt:
.LFB0:
	.cfi_startproc
	cmpq	%rsi, %rdi
	setg	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE0:
	.size	gt, .-gt
	.globl	zero
	.type	zero, @function
zero:
.LFB1:
	.cfi_startproc
	testq	%rdi, %rdi
	sete	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE1:
	.size	zero, .-zero
	.globl	gt1
	.type	gt1, @function
gt1:
.LFB2:
	.cfi_startproc
	cmpq	%rsi, %rdi
	setge	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE2:
	.size	gt1, .-gt1
	.globl	gt2
	.type	gt2, @function
gt2:
.LFB3:
	.cfi_startproc
	cmpq	%rsi, %rdi
	setl	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE3:
	.size	gt2, .-gt2
	.globl	gt3
	.type	gt3, @function
gt3:
.LFB4:
	.cfi_startproc
	cmpq	%rsi, %rdi
	setle	%al
	movzbl	%al, %eax
	ret
	.cfi_endproc
.LFE4:
	.size	gt3, .-gt3
	.ident	"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
