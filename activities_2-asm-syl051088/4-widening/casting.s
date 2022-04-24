	.file	"casting.c"
	.text
	.globl	addMult
	.type	addMult, @function
addMult:
.LFB0:
	.cfi_startproc
	addq	%rsi, %rdi
	movslq	%edx, %rax
	imulq	%rdi, %rax
	ret
	.cfi_endproc
.LFE0:
	.size	addMult, .-addMult
	.globl	addMult1
	.type	addMult1, @function
addMult1:
.LFB1:
	.cfi_startproc
	addq	%rsi, %rdi
	movsbq	%dl, %rax
	imulq	%rdi, %rax
	ret
	.cfi_endproc
.LFE1:
	.size	addMult1, .-addMult1
	.globl	unsignedAddMult1
	.type	unsignedAddMult1, @function
unsignedAddMult1:
.LFB2:
	.cfi_startproc
	addq	%rsi, %rdi
	movzbl	%dl, %eax
	imulq	%rdi, %rax
	ret
	.cfi_endproc
.LFE2:
	.size	unsignedAddMult1, .-unsignedAddMult1
	.globl	arith_u
	.type	arith_u, @function
arith_u:
.LFB3:
	.cfi_startproc
	movzbl	%dil, %edi
	salq	$6, %rdi
	movzwl	%si, %esi
	leaq	42(%rsi,%rdi), %rax
	ret
	.cfi_endproc
.LFE3:
	.size	arith_u, .-arith_u
	.globl	arith_u1
	.type	arith_u1, @function
arith_u1:
.LFB4:
	.cfi_startproc
	movzbl	%dil, %edi
	salq	$6, %rdi
	movl	%esi, %esi
	leaq	42(%rsi,%rdi), %rax
	ret
	.cfi_endproc
.LFE4:
	.size	arith_u1, .-arith_u1
	.ident	"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
