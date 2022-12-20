    .text
    .global num_to_char
    .type num_to_char, %function
num_to_char:
@ in r0 = dividend, r1 = divisor
@ r2 = mod, r3 = quot
    push    {r0, r1, r2, r3, lr}
    bl      div
    mov     r3, r0
    pop     {r0, r1}
    mul     r2, r3, r1
    sub     r2, r0, r2
    push    {r2}
    cmp     r3, #0
    ble     out
out:
    pop     {}

    