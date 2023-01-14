#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

#define STACK_SIZE 100

typedef long ELEM;
ELEM stack[STACK_SIZE];
int n;

void error(char *s){
    fprintf(stderr, s);
    exit(1);
}

void init(){
    n = 0;
}

void push(ELEM x){
    if(n >= STACK_SIZE)
        error("stack overflow\n");
    stack[n++] = x;
}

ELEM pop(){
    if(n <= 0)
        error("stack underflow\n");
    return stack[--n];
}

int empty(){    
    return n == 0;
}