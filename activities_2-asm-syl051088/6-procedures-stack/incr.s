	.file	"incr.c"
	.text
	.globl	incr
	.type	incr, @function
incr:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rax
	addq	%rax, %rsi
	movq	%rsi, (%rdi)
	ret
	.cfi_endproc
.LFE0:
	.size	incr, .-incr
	.globl	call_incr
	.type	call_incr, @function
call_incr:
.LFB1:
	.cfi_startproc
	subq	$16, %rsp
	.cfi_def_cfa_offset 24
	movq	$15213, 8(%rsp)
	movl	$3000, %esi
	leaq	8(%rsp), %rdi
	call	incr
	addq	8(%rsp), %rax
	addq	$16, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE1:
	.size	call_incr, .-call_incr
	.globl	call_incr2
	.type	call_incr2, @function
call_incr2:
.LFB2:
	.cfi_startproc
	pushq	%rbx
	.cfi_def_cfa_offset 16
	.cfi_offset 3, -16
	subq	$16, %rsp
	.cfi_def_cfa_offset 32
	movq	%rdi, %rbx
	movq	$15213, 8(%rsp)
	movl	$3000, %esi
	leaq	8(%rsp), %rdi
	call	incr
	addq	%rbx, %rax
	addq	$16, %rsp
	.cfi_def_cfa_offset 16
	popq	%rbx
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE2:
	.size	call_incr2, .-call_incr2
	.ident	"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
