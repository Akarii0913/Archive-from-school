#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubble_sort(int *data){
    int i,j,t;

    for(i = 0; i < MAX-1; i++){
        for(j = MAX - 1; j > i; j--){
            if (data[j-1] > data[j]){
                t = data[j]; data[j] = data[j-1]; data[j-1] = t;
            }
        }
    }
}

void selection_sort(int *data){
    int i, j, t, lowest, lowkey;

    for (i = 0; i < MAX - 1; i++){
        lowest = i;
        lowkey = data[i];
        for (j = i + 1; j < MAX; j++){
            if (data[j] < lowkey){
                lowest = j;
                lowkey = data[j];
            }
        }
        t = data[i];
        data[i] = data[lowest];
        data[lowest] = t;
    }
}

void insertion_sort(int *data){
    int i, j, t;

    for(i = 1; i < MAX; i++){
        j = i;
        while(j >= 1 && data[j-1] > data[j]){
            t = data[j];
            data[j] = data[j-1];
            data[j-1] = t;

            j--;
        }
    }
}

void shell_sort(int *data){
    int h, i, j, t;

    for (h = 1; h < MAX/9; h = h*3 + 1);
    
    for(h /= 3; h > 0; h /= 3){
        for (i = h; i < MAX; i++){
            j = i;
            while ( j >= h && data[j-h] > data[j]){
                t = data[j]; data[j] = data[j-h]; data[j-h] = t;
                j -= h;
            }
        }
    }
}

int partition(int *data, int first, int last){
    int i, j, pivot, tmp;

    i = first-1;
    j = last;

    pivot = data[last];

    for(;;){
        while (data[++i] < pivot);
        while (i < --j && pivot < data[j]);

        if (i >= j)
            break;

        tmp = data[i]; data[i]=data[j]; data[j]=tmp;
    }

    tmp = data[i]; data[i] = data[last]; data[last]=tmp;
    return i;
}

void quick_sort(int *data, int first, int last){
    int pivot;

    if(first >= last)
    return;

    pivot = partition(data, first, last);

    quick_sort(data, first, pivot-1);
    quick_sort(data, pivot+1, last);
}

void merge_sort(int *data, int low, int high){
    int mid, i, j, k;
    int *workspace;
    workspace = (int *)malloc(sizeof(int)*MAX);

    high = high - 1;

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

    free(workspace);
}

void downheap(int from, int to, int heap_data[]){
    int i, j;
    int val;

    val = heap_data[from];

    i = from;
    while(i <= to/2){
        j = i* 2;
        if(j+1 <= to && heap_data[j] < heap_data[j+1])
            j++;

        if(val >= heap_data[j])
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