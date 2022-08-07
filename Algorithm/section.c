#include <stdio.h>

void selection_sort(int a[], int n);

int main(void){
    int i;
    int a[] = {3, 11, 1000, 98, 1, 8};
    int n = sizeof(a)/sizeof(int);

    selection_sort(a, n);

    for (i = 0; i < n; i++){
        printf("%d, ", a[i]);
    }
}

void selection_sort(int a[], int n){
    int i, j, t, lowest, lowkey;

    for (i = 0; i < n - 1; i++){
        lowest = i;
        lowkey = a[i];
        for (j = i + 1; j < n; j++){
            if (a[j] < lowkey){
                lowest = j;
                lowkey = a[j];
            }
        }
        t = a[i];
        a[i] = a[lowest];
        a[lowest] = t;
    }
}