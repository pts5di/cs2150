	;; parameter 1(in rdi) is the first number
	;; parameter 2(in rsi) is the number to mult by
	global _product

	section .text

_product:
	xor 	rax, rax
start:
	cmp 	r10, rsi
	je	done
	add	rax, rdi
	inc	r10
	jmp	start
done:
	ret
