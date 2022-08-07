#include <stdio.h>

void insertion_sort(int a[], int n);

int main(){
    int a[] = {20, 6, 55, 74, 3, 45, 13, 87, 46, 30};
    int n = sizeof(a)/sizeof(int);
    int i;

    insertion_sort(a, n);

    for(i = 0; i < n; i++){
        printf("%-3d", a[i]);
    }

    return 0;
}

void insertion_sort(int a[], int n){
    int i, j, t;

    for(i = 1; i < n; i++){
        j = i;
        while(j >= 1 && a[j-1] > a[j]){
            t = a[j];
            a[j] = a[j-1];
            a[j-1] = t;

            j--;
        }
    }
}