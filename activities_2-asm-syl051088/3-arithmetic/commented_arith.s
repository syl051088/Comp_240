	.file	"arith.c"
	.text
	.globl	plus
	.type	plus, @function
plus:							# x in %rdi, y in %rsi
.LFB0:
	.cfi_startproc
	leaq	(%rdi,%rsi), %rax	# x + y						%rax: x + y
	ret							# return x + y
	.cfi_endproc
.LFE0:
	.size	plus, .-plus
	.globl	arith
	.type	arith, @function
arith:								# x in %rdi, y in %rsi, z in %rdx
.LFB1:
	.cfi_startproc
	leaq	(%rdi,%rsi), %rax		# t1 = x + y			%rax: t1
	addq	%rdx, %rax				# t2 = z + t1 			%rax: t2
	leaq	(%rsi,%rsi,2), %rcx		# y + 2 * y				%rcx: 3y
	salq	$4, %rcx				# t4 = 16 * (y + 2 * y)	%rcx: t4
	leaq	4(%rdi,%rcx), %rcx		# t5 = t4 + x + 4		%rcx: t5
	imulq	%rcx, %rax				# rval = t2 * t5		%rax: rval
	ret								# return rval
	.cfi_endproc
.LFE1:
	.size	arith, .-arith
	.globl	m12
	.type	m12, @function
m12:								# x in %rdi
.LFB2:
	.cfi_startproc
	leaq	(%rdi,%rdi,2), %rax		# x + 2 * x				%rax: 3x
	salq	$2, %rax				# 4 * (x + 2 * x)		%rax: 12x
	ret								# return 4 * (x + 2 * x)
	.cfi_endproc
.LFE2:
	.size	m12, .-m12
	.globl	scale
	.type	scale, @function
scale:								# x in %rdi, y in %rsi, z in %rdx
.LFB3:
	.cfi_startproc
	leaq	4(%rdi,%rsi,8), %rax	# 4 + x + 8 * y			%rax: x + 8y + 4
	ret								# return 4 + x + 8 * y
	.cfi_endproc
.LFE3:
	.size	scale, .-scale
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
