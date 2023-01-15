    .text
    .global calender
    .type   calender, %function
calender:

last_date_and_day:
@ r0 = year, r1 = month, r2 = &buf
@ r4 = year(saved), r5 = month(saved)
    push    {r2, bl}
    mov     r4, r0
    mov     r5, r1
    bl      manlen
    push    {r0}
    mov     r2, r0
    mov     r0, r4
    mov     r1, r5
    bl      zella

set_num:
@ r1 = manlen, r2 = &buf, r3 = count, r4 = space, 
    mov     r3, r0
    pop     {r0, r2}
    mov     r1, r0
    mov     r4, #10
set_num_loop:
    cmp     r1, #0
    beq     set_num_comp
    cmp     r3, #0
    beq     count_clear
    push    {r1}
    sub     r1, r1, #1
    sub     r3, r3, #1
    b       set_num_loop
count_clear:
    mov     r5, r1
    mov     r1, #10
    push    {r1}
    mov     r1, r5
    mov     r3, #6
    b       set_num_loop
set_num_comp:
    mov     r1, #32
    cmp     r3, #0
    beq     set_num_out
    push    {r1}
    sub     r3, r3, #1
    b       set_num_comp:

set_num_out





