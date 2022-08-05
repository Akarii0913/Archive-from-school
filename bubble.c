#include <stdio.h>

void bubble_sort(int a[], int n);

int main(){
    int a[] = {61, 4, 36, 11, 9, 77};
    int n = sizeof(a)/sizeof(int);
    int i;

    printf("an array a={61, 4, 36, 11, 9, 77} will be sorted  in ascending order.\n");

    bubble_sort(a, n);

    for(i = 0; i < n; i++){
        printf("%d ", a[i]);
    }
}

void bubble_sort(int a[], int n){
    int i,j,t;

    for(i = 0; i < n-1; i++){
        for(j = n - 1; j > i; j--){
            if (a[j-1] > a[j]){
                t = a[j]; a[j] = a[j-1]; a[j-1] = t;
            }
        }
    }
}