#include <stdio.h>
extern char calender(char *s, int year);
char cal[BUFSIZ];

int main(){
    calender(cal, 2021);
    printf("%s\n", cal);
}