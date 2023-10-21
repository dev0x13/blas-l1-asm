section .text

; float cblas_sasum(const int N, const float *X, const int incX)
global cblas_sasum
cblas_sasum:
    push rbp
    mov rbp, rsp

    ; edi - N
    ; rsi - *X
    ; edx - incX

    cmp edx, 0        ; if (incX <= 0)
    jle .end          ;   return
         
    mov eax, 4        ; compute *X offset
    mul edx           ;
     
    xor ecx, ecx      ; i = 0
    pxor xmm0, xmm0   ; r = 0.0
     
    jmp .cond         ; for loop

.loop:
    movss   xmm2, [rsi] ; abs_x = fabs(X[ix])
    pcmpeqd xmm1, xmm1  ; fill xmm1 with ones
    psrld   xmm1, 1     ; zero out the first bit of xmm1
    andps   xmm1, xmm2  ; mask off sign bit of xmm2

    addss xmm0, xmm1    ; r += abs_x

    add rsi, rax      ; ix += incX
    inc ecx           ; i++

.cond:
    cmp ecx, edi      ; if (i == N)
    jne .loop         ;   return

.end:
    mov rsp, rbp
    pop rbp
    ret
   