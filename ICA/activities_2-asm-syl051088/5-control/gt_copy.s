	.file	"gt.c"
	.text
	.globl	gt
	.type	gt, @function
gt:                             # x in %rdi, y in %rsi
.LFB0:
	.cfi_startproc
	cmpq	%rsi, %rdi          # compare x : y
	setg	%al                 # Set low-order byte of %eax to 1 when >, 0 otherwise
	movzbl	%al, %eax           # Clear rest of %eax (and rest of %rax)
	ret
	.cfi_endproc
.LFE0:
	.size	gt, .-gt
	.globl	zero
	.type	zero, @function
zero:                           # x in % rdi
.LFB1:
	.cfi_startproc
	testq	%rdi, %rdi          # test x&x
	sete	%al                 # Set low-order byte of %eax to 1 when = 0, 0 otherwise
	movzbl	%al, %eax           # Clear rest of %eax (and rest of %rax)
	ret
	.cfi_endproc
.LFE1:
	.size	zero, .-zero
	.ident	"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
