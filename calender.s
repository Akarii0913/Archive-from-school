    .text
    .global calender
    .type calender, %function
calender:
@ r0 = year
    push    {lr}
    mov     r1, #35
    push    {r1}

num_to_char:
@ in r0 = dividend, r1 = divisor
@ r2 = mod, r3 = quot
    mov     r1, #10
    push    {r0}
    bl      div10
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

loop:
    pop     {r2}
    cmp     r2, #35
    beq     end
    ldr     r0, =buf
    add     r1, r2, #48
    strb    r1, [r0], #1
    b       loop

end:
    pop     {lr}
    bx      lr

div10:  
    push    {r0, r1, r2}
@ r0 = dividend, r1 = divisor, r2 = quot
    mov     r2, #0
loop_div:
    cmp     r0, r1
    blo     loopout_div
    add     r2, r2, #1
    sub     r0, r0, r1
    b       loop_div
loopout_div:
    mov     r0, r2
    bx      lr
@ out r0 = quot

    .section    .data
buf:
    .asciz "XYZ"