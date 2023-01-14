    .text
    .global manlen
    .type manlen, %function
manlen:
@ r0=year, r1=month
    mov     r3, r0
    push    {r1 lr}
    mov     r1, #4
    bl      div
    cmp     r0, #0
    bne     common_year

    mov     r0, r3
    mov     r1, #100
    bl      div
    cmp     r0, #0
    bne     leap_year

    mov     r0, r3
    mov     r1, 400
    bl      div
    cmp     r0, #0
    beq     common_year
    b       leap_year

commmon_year:
    pop     {r1}
    cmp     r1, #2
    bne     month_select
    mov     r0, 28
    pop     {lr}    
    bx      lr

leap_year:
    pop     {r1}
    cmp     r1, #2
    bne     month_select
    mov     r0, #29
    pop     {lr}
    bx      lr

month_select:
    cmp     r1, #4
    beq     short_month
    cmp     r1, #6
    beq     short_moth
    cmp     r1, #9
    beq     short_month
    cmp     r1, #11
    beq     short_month
    b       long_month

short_month:
    mov     r0, #30
    pop     {lr}
    bx      lr

long_month:
    mov     r0, #31
    pop     {lr}
    bx      lr
