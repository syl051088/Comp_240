	.file	"matrix.c"
	.text
	.globl	populate
	.type	populate, @function
populate:
.LFB3:
	.cfi_startproc
	movl	$0, %ecx
	jmp	.L2
.L7:
	addl	$1, %ecx
.L2:
	cmpl	$255, %ecx
	jg	.L6
	movl	$0, %eax
.L4:
	cmpl	$215, %eax
	jg	.L7
	movl	%ecx, %edx
	imull	%eax, %edx
	movl	%edx, (%rdi)
	addq	$4, %rdi
	addl	$1, %eax
	jmp	.L4
.L6:
	ret
	.cfi_endproc
.LFE3:
	.size	populate, .-populate
	.globl	get_elem
	.type	get_elem, @function
get_elem:
.LFB4:							# Assume the input matrix at address A. From the assmbly below we know that %eax is A + 4(216r + c). Thus, N = 216.
	.cfi_startproc
	movslq	%esi, %rsi          # extend r to 64 bits to use in next leaq
	leaq	(%rsi,%rsi,2), %rax # %rax: r + 2r = 3r
	leaq	(%rax,%rax,8), %rcx # %rcx: 3r + 24r = 27r
	movq	%rcx, %rax          # %rax: 27r
	salq	$5, %rax            # %rax: 27r * 32 = 864r
	addq	%rax, %rdi          # %rdi: address of first element in the matrix + 864r
	movslq	%edx, %rdx          # extend c to 64 bits to use in next movq
	movl	(%rdi,%rdx,4), %eax # %eax: %rdi + 4c
	ret
	.cfi_endproc
.LFE4:
	.size	get_elem, .-get_elem
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"result is: %d\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB5:
	.cfi_startproc
	subq	$221192, %rsp
	.cfi_def_cfa_offset 221200
	movq	%rsp, %rdi
	call	populate
	movl	$8, %edx
	movl	$8, %esi
	movq	%rsp, %rdi
	call	get_elem
	movl	%eax, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$221192, %rsp
	.cfi_def_cfa_offset 8
	ret
	.cfi_endproc
.LFE5:
	.size	main, .-main
	.ident	"GCC: (GNU) 8.3.1 20190311 (Red Hat 8.3.1-3)"
	.section	.note.GNU-stack,"",@progbits
