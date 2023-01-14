#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define QUEUE_SIZE 100
#define next(a) (((a) + 1)%QUEUE_SIZE)

typedef long ELEM;
ELEM queue[QUEUE_SIZE];
int front, rear;

void error(char *s){
    fprintf(stderr, s);
    exit(1);
}

void init(){
    front = rear = 0;
}

void enqueue(ELEM x){
    if (next(rear) == front)
        error("Queue is full.\n");
    queue[rear] = x;
    rear = next(rear);
}

ELEM dequeue(){
    ELEM x;

    if(front == rear)
        error("Queue is empty.\n");
    
    x = queue[front];
    front = next(front);
    return x;
}

int empty(){    
    return front == rear;
}