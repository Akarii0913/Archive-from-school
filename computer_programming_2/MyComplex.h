#ifndef MYCOMPLEX_C
#define MYCOMPLEX_C
#include <stdio.h>
/*複素数の構造体宣言*/
typedef struct Complex{
    double real;
    double imag;
} Complex;

/*extern宣言*/
extern Complex com1;
extern Complex com2;
extern Complex com_add_res;
extern Complex com_sub_res;
extern Complex com_mul_res;
extern Complex com_div_res;
extern double com1_abso_res;
extern double com2_abso_res;
extern double *com1_abso_point;
extern double *com2_abso_point;

/*足し算、引き算、掛け算、割り算、絶対値の関数プロトタイプ宣言*/
Complex add(Complex com1, Complex com2);
Complex sub(Complex com1, Complex com2);
Complex mul(Complex com1, Complex com2);
Complex div(Complex com1, Complex com2);
double abso(Complex com1, Complex com2, double *com1_abso_point, double *com2_abso_point);
#endif 