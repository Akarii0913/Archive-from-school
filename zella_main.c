#include <stdio.h>
extern int zella(int year, int month, int day);

int main(){
    int a;
    a = zella(2021, 6, 1);
    printf("%d\n", a);
}