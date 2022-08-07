#include <stdio.h>
int partition(int data[], int first, int last);
void quick_sort(int data[], int first, int last);

int main(void){
    int data[] = {1, 32, 19, 82, 3, 85, 43, 37, 96, 77, 95, 12};
    int len = sizeof(data)/sizeof(int);

    quick_sort(data, 0, len);

    for (int i = 0; i < len; i++)
        printf("%-3d", data[i]);

    return 0;
}

int partition(int data[], int first, int last){
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

void quick_sort(int data[], int first, int last){
    int pivot;

    if(first >= last)
    return;

    pivot = partition(data, first, last);

    quick_sort(data, first, pivot-1);
    quick_sort(data, pivot+1, last);
}