    .text
    .global calender
    .type calender, %function
calender:
@ r0 = &cal(saved), r1 = year
    push    {lr}
    mov     r2, #35
    push    {r2}

num_to_char:
@ in r0 = dividend, r1 = divisor
@ r2 = mod, r3 = quot
    mov     r0, r1
    mov     r1, #10
    push    {r0}
    bl      div
    mov     r3, r0
    pop     {r0}
    mov     r1, #10
    mul     r2, r3, r1
    sub     r2, r0, r2
    push    {r2}
    mov     r1, r3
    cmp     r1, #0
    ble     out
    b       num_to_char
out:
    pop     {r0}
loop:
    pop     {r2}
    cmp     r2, #35
    beq     end
    add     r1, r2, #48
    strb    r1, [r0], #1
    b       loop

end:
    pop     {lr}
    bx      lr

