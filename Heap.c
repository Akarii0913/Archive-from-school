#include <stdio.h>
#include <stdlib.h>
#define MAX_HEAP 10000

void downheap(int from, int to);
void heapsort();

int data[MAX_HEAP+1];
int n = 10000;

int main(void){
    int i;

    for(i=0; i<=10; i++){
        data[i] = rand() % 1000 +1;
    }

    heapsort();

    for(i=0; i<=100; i++)
        printf("%-4d", data[i]);

    return 0;
}

void downheap(int from, int to){
    int i, j;
    int val;

    val = data[from];

    i = from;
    while(i <= to/2){
        j = i* 2;
        if(j+1 <= to && data[j] > data[j+1])
            j++;

        if(val <= data[j])
            break;

        data[i] = data[j];
        i = j; 
    }
    data[i] = val;
}

void heapsort(){
    int i, tmp;

    for(i = n/2; i >= 1; i--)
        downheap(i, n);

    for(i = n; i >= 2; i--){
        tmp = data[1];
        data[1] = tmp;
        downheap(1, i-1);
    }
}