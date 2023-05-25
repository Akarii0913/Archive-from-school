#include "MyComplex.h"
#include <stdio.h>
#include <math.h>
/*複素数の宣言*/
Complex com1;
Complex com2;
Complex com_add_res;
Complex com_sub_res;
Complex com_mul_res;
Complex com_div_res;
double com1_abso_res;
double com2_abso_res;
double *com1_abso_point;
double *com2_abso_point;

/*足し算の関数の定義*/
Complex add(Complex com1, Complex com2){
   com_add_res.real = com1.real + com2.real;
   com_add_res.imag = com1.imag + com2.imag;
   return (com_add_res);
}

/*引き算の関数の定義*/
Complex sub(Complex com1, Complex com2){
   com_sub_res.real = com1.real - com2.real;
   com_sub_res.imag = com1.imag - com2.imag;
   return (com_sub_res);
}

/*掛け算の関数の定義*/
Complex mul(Complex com1, Complex com2){
   com_mul_res.real = com1.real*com2.real - com1.imag*com2.imag;
   com_mul_res.imag = com1.real*com2.imag + com1.imag*com2.real;
   return (com_mul_res);
}

/*割り算の関数の定義*/
Complex div(Complex com1, Complex com2){
   com_div_res.real = (com1.real*com2.real + com1.imag*com2.imag)/(pow(com2.real, 2.0) + pow(com2.imag, 2.0));
   com_div_res.imag = (com2.real*com1.imag - com2.imag*com1.real)/(pow(com2.real, 2.0) + pow(com2.imag, 2.0));
   return (com_div_res);
}

/*絶対値の関数の定義*/
double abso(Complex com1, Complex com2, double *com1_abso_point, double *com2_abso_point){
   *com1_abso_point = sqrt(pow(com1.real, 2.0) + pow(com1.imag, 2.0));

   *com2_abso_point = sqrt(pow(com2.real, 2.0) + pow(com2.imag, 2.0));
}
