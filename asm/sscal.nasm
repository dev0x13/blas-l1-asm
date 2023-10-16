section .text

; void cblas_sscal(const int N, const float alpha, float *X, const int incX)
global cblas_sscal
cblas_sscal:
    push rbp
    mov rbp, rsp

    ; edi - N
    ; xmm0 - alpha
    ; rsi - *X
    ; edx - incX

    cmp edx, 0        ; if (incX <= 0)
    jle .end          ;   return;
         
    mov eax, 4        ; compute *X offset
    mul edx           ;
     
    xor ecx, ecx      ; i = 0
     
    jmp .cond         ; for loop

.loop:     
    movss xmm1, [rsi] ; X[ix] *= alpha;
    mulss xmm1, xmm0  ;
    movss [rsi], xmm1 ;
    
    add rsi, rax      ; ix += incX;
    inc ecx           ; i++

.cond:
    cmp ecx, edi      ; if (i == N)
    jne .loop         ;   return

.end:
    mov rsp, rbp
    pop rbp
    ret
   