#include <stdio.h>
#define MAX_ELEMENTS 10000 

void merge_sort(int data[], int low, int high);

int main(void){
    int i;
    c

    merge_sort(data, 0, 7);

    for(i = 0; i <= 7; i++)
        printf("%-3d", data[i]);

}

void merge_sort(int data[], int low, int high){
    int mid, i, j, k;
    int workspace[MAX_ELEMENTS];

    if(low >= high)
        return;

    mid = (low + high)/2;

    merge_sort(data, low, mid);
    merge_sort(data, mid+1, high);

    for(i = low; i <= mid; i++)
        workspace[i] = data[i];

    for(i = mid+1, j= high; i <= high; i++, j--)
        workspace[i] = data[j];

    i = low; j = high;
    for(k = low; k <= high; k++)
        if(workspace[i] <= workspace[j])
            data[k] = workspace[i++];
        else
            data[k] = workspace[j--];
}   