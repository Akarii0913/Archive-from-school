#include <stdio.h>
#define MAX 10

void downheap(int from, int to, int heap_data[]);
void heap_sort(int heap_data[], int n);

int main(){
    int data[MAX+1] = {0, 10, 1, 4, 8, 9, 60, 99, 87, 44, 17};

    heap_sort(data, MAX);

    for(int i=0; i<MAX+1; i++)
        printf("%-3d", data[i]);

    return 0;
}


void downheap(int from, int to, int heap_data[]){
    int i, j;
    int val;

    val = heap_data[from];

    i = from;
    while(i <= to/2){
        j = i* 2;
        if(j+1 <= to && heap_data[j] > heap_data[j+1])
            j++;

        if(val <= heap_data[j])
            break;

        heap_data[i] = heap_data[j];
        i = j; 
    }
    heap_data[i] = val;
}

void heap_sort(int heap_data[], int n){
    int i, tmp;

    for(i = n/2; i >= 1; i--)
        downheap(i, n, heap_data);

    for(i = n; i >= 2; i--){
        tmp = heap_data[1];
        heap_data[1] = heap_data[i];
        heap_data[i] = tmp;
        downheap(1, i-1, heap_data);
    }
}