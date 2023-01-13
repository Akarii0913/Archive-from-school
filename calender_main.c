#include <stdio.h>
extern char cal(char *buf, int year);
char buf[100];

int main(){
    cal(buf, 2021);
}