	.file	"swap.c"
	.text
	.globl	swap
	.type	swap, @function
swap:
.LFB0:
	.cfi_startproc
	movq	(%rdi), %rax    # copy the value stored in xp to %rax
	movq	(%rsi), %rdx    # copy the value stored in yp to %rdx
	movq	%rdx, (%rdi)    # store %rdx to pointer xp
	movq	%rax, (%rsi)    # store %rax to pointer yp
	ret
	.cfi_endproc
.LFE0:
	.size	swap, .-swap
	.ident	"GCC: (Ubuntu 4.8.4-2ubuntu1~14.04.3) 4.8.4"
	.section	.note.GNU-stack,"",@progbits
