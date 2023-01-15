    .text
    .global div
    .type div, %function

div:
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