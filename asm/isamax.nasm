section .text

; int cblas_isamax(const int N, const float *X, const int incX)
global cblas_isamax
cblas_isamax:
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
    xor ebx, ebx      ; result = 0
    pxor xmm0, xmm0   ; max = 0.0
     
    jmp .cond         ; for loop

.loop:
    movss   xmm2, [rsi] ; abs_x = fabs(X[ix])
    pcmpeqd xmm1, xmm1  ; fill xmm1 with ones
    psrld   xmm1, 1     ; zero out the first bit of xmm1
    andps   xmm1, xmm2  ; mask off sign bit of xmm2

    comiss  xmm1, xmm0  ; if (abs_x > max)
    ja      .updmax

.inccnt
    add rsi, rax      ; ix += incX
    inc ecx           ; i++
    jmp .cond

.updmax:
    movss xmm0, xmm1  ; max = fabs(X[ix])
    mov   ebx, ecx    ; result = i
    jmp   .inccnt  

.cond:
    cmp ecx, edi      ; if (i == N)
    jne .loop         ;   return

    mov eax, ebx

.end:
    mov rsp, rbp
    pop rbp
    ret
   