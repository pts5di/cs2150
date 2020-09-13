
	;; the first parameter(rdi) is a pointer to an array
	;; the second parameter(rsi) is the beginning of the array
	;; the third parameter(rdx) is the end of the array
	;; the fourth parameter(rcx) is the target value
	;; r8 will act as the "midpoint" value
	global _binarySearch

	section	.text

_binarySearch:
loop:
	push 	rsi
	push 	rdx
	add	rsi, rdx	;add start/end array indices
	shr	rsi, 1		;divide by 2
	mov 	r8, rsi		;store midpoint in r8
	pop	rdx
	pop	rsi
	push	r8
	imul	r8, 4		;multiply midpoint by 4(size of int)
	push	rdi
	add	rdi, r8		;add midpoint to array pointer
	mov	r9, rdi
	pop 	rdi
	pop 	r8
	cmp 	[r9], ecx	;compare midpoint of array to value
	je	exit
	jg	greater		;jump to (greater than) logic
	jl	lesser		;jump to (lesser than) logic
greater:
	cmp	rdx, rsi
	je	badexit
	mov	rdx, r8		;moves end index to midpoint to "halve" array
	jmp	loop
lesser:
	cmp	rdx, rsi
	je	badexit
	mov	rsi, r8		;moves start index to midpoint to "halve" array
	jmp 	loop
exit:
	mov	rax, r8		;moves midpoint index to rax for return
	ret
badexit:
	mov	rax, -1
	ret
