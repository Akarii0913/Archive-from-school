#include <stdio.h>
#include <stdlib.h>

void shell_sort(int data[], int lengthy);
int main(void){
    int i, lengthy;
    int data[1000];

    for (i=0; i < 1000; i++){
        data[i] = rand()%900 + 1;
    }

    lengthy = sizeof(data)/sizeof(int);

    shell_sort(data, lengthy);

    for (i=0; i<lengthy; i++){
        printf("%-5d", data[i]);
    }
}

void shell_sort(int data[], int lengthy){
    int h, i, j, t;

    for (h = 1; h < lengthy/9; h = h*3 + 1);
    
    for(h /= 3; h > 0; h /= 3){
        for (i = h; i < lengthy; i++){
            j = i;
            while ( j >= h && data[j-h] > data[j]){
                t = data[j]; data[j] = data[j-h]; data[j-h] = t;
                j -= h;
            }
        }
    }
}