    .text
    .global cal
    .type cal, %function
cal:
@cal(&buf, year)
    push    {r0, r1, r2, r3,lr}
    mov     r3, #35
    push    {r3}
    mov     r0, r1
    bl      set_num
    pop     {r0}

cal_loop:
    pop     {r3}
    cmp     r3, #35
    beq     cal_out
    add     r3, r3, #48
    strb    r3, [r0], #1
    b       cal_loop

cal_out:
    mov     r3, #0
    strb    r3, [r0]
    pop     {r1, r2, r3, lr}
    bx      lr

set_num:
    push    {lr}

set_num_loop:
    push    {r0}
    mov     r1, #10
    bl      div10
    mov     r2, r0
    pop     {r0}
    mov     r3, #10
    mul     r1, r2, r3
    sub     r3, r0, r1
    push    {r3}
    cmp     r2, #0
    ble     set_num_out
    mov     r0, r2
    b       set_num_loop

set_num_out:
    pop     {lr}
    bx      lr

div10:
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
