#include <stdio.h>
#include "MyComplex.h"
int main(void){
    Complex com1 = {1.0, 1.0};
    Complex com2 = {2.0, 2.0};

    add(com1, com2);
    sub(com1, com2);
    mul(com1, com2);
    div(com1, com2);
    abso(com1, com2, &com1_abso_res, &com2_abso_res);

    printf("%lf+%lfi\n", com_add_res.real, com_add_res.imag);
    printf("%lf+%lfi\n", com_sub_res.real, com_sub_res.imag);
    printf("%lf+%lfi\n", com_mul_res.real, com_mul_res.imag);
    printf("%lf+%lfi\n", com_div_res.real, com_div_res.imag);
    printf("com1の絶対値:%lf\ncom2の絶対値:%lf\n", com1_abso_res, com2_abso_res);

    return 0;
}
