section .text

; void cblas_scopy(const int N, const float *X, const int incX, float *Y,
;                  const int incY)
global cblas_scopy
cblas_scopy:
    push rbp
    mov rbp, rsp

    ; edi - N
    ; rsi - *X
    ; edx - incX
    ; rcx - *Y
    ; r8d - incY

    xor rax, rax      ; ix = (incX > 0 ? 0 : (N - 1) * -incX)
    cmp edx, 0
    jg .incyset

    mov ebx, edi
    sub ebx, 1
    imul ebx, edx
    sub eax, ebx
    imul eax, 4

    add rsi, rax      ; X += ix

.incyset:
    cmp r8d, 0        ; iy = (incY > 0 ? 0 : (N - 1) * -incY)
    jg .compinc

    xor eax, eax
    mov ebx, edi
    sub ebx, 1
    imul ebx, r8d
    sub eax, ebx
    imul eax, 4

    add rcx, rax      ; Y += iy

.compinc:
    xor eax, eax
    mov eax, 4        ; compute *X offset
    mul edx           ;

    xor rbx, rbx
    mov ebx, 4        ; compute *Y offset
    imul ebx, r8d

    xor r9d, r9d      ; i = 0

.cond:
    cmp r9d, edi      ; if (i == N)
    je .end           ;   return

    movss xmm1, [rsi] ; Y[i] = X[i]
    movss [rcx], xmm1

    add rsi, rax      ; ix += incX
    add rcx, rbx      ; iy += incY
    inc r9d           ; i++
    jmp .cond

.end:
    mov rsp, rbp
    pop rbp
    ret
   