    .text
    .global zella
    .type zella, %function
zella:
@ r0, r1, r2 = for subfunc, r3 = ans, r4 = year(saved), r5 = month(saved), r6 = date(saved), r7 = for mul

    push    {r4, r5, r6, r7, lr}

    mov     r4, r0
    mov     r5, r1
    mov     r6, r2
    mov     r3, #0
    add     r3, r3, r4
    @ r3 = y

    mov     r0, r4
    mov     r1, #4
    bl      div
    add     r3, r3, r0
    @ r3 = y + y/4

    mov     r0, r4
    mov     r1, #100
    bl      div
    sub     r3, r3, r0
    @ r3 = y + y/4 - y/100

    mov     r0, r4
    mov     r1, #400
    bl      div
    add     r3, r3, r0
    @ r3 = y + y/4 - y/100 + y/400

    mov     r7, #13
    mul     r0, r5, r7 
    add     r0, r0, #8
    mov     r1, #5
    bl      div
    add     r3, r3, r0
    @ r3 = y + y/4 - y/100 + y/400 + (13*m + 8)/5

    add     r3, r3, r6
    @ r3 = y + y/4 - y/100 + y/400 + (13*m + 8)/5 + d

    mov     r0, r3
    mov     r1, #7
    bl      mod
    @ r0 = r3%7

    pop     {r4, r5, r6, r7, lr}
    bx      lr
