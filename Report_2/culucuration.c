#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int main(){
    int i,j,k;
    char file_name[50];

    //実行回数
    int num = 30;

    //clock関数の戻り値格納用
    clock_t start_clock, end_clock;

    //データのメモリを動的確保
    int *data, *heap_data;
    data = (int *)malloc(sizeof(int)*MAX);
    heap_data = (int *)malloc(sizeof(int)*MAX);

    srand((unsigned int)time(NULL));

    //バブル,選択,挿入,シェルソートの関数ポインタの配列
    void(*simple_sort[SIMPLE_FUNC_NUM])(int *data) = {
        bubble_sort,
        selection_sort,
        insertion_sort,
        shell_sort,
    };

    //クイック,マージソートの関数ポインタの配列
    void(*comp_sort[COMP_FUNC_NUM])(int *data, int first, int last) = {
        quick_sort,
        merge_sort,
    };

    //ファイルのオープン
    FILE *fp;
    sprintf(file_name, "result_%d.csv", MAX);
    fp = fopen(file_name, "a+");
    if(fp == NULL){
        printf("Fail to open this file.\n");
        return 1;
    }
    else{
        printf("Success to open this file. \n");
    }

    for(i=0; i<num; i++){
        //バブル,選択,挿入,シェルソート
        for(j=0; j<SIMPLE_FUNC_NUM; j++){
            //整列用データの作成
            for(k=0; k<MAX; k++){
                data[k] = 0 + rand()%MAX;
            }

            start_clock = clock();
            simple_sort[j](data);
            end_clock = clock();
            fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
        }

        //クイック,マージソート
        int high;
        for(j=0; j<COMP_FUNC_NUM; j++){
            if(j == 1)
                high = MAX - 1;
            else high = MAX;

            //整列用データの作成
            for(k=0; k<MAX; k++){
                data[k] = 0 + rand()%MAX;
            }

            start_clock = clock();
            comp_sort[j](data, 0, high);
            end_clock = clock();
            fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
        }

        //ヒープソート
        //整列用データの作成
        for(j=0; j<MAX+1; j++)
            heap_data[j] = 0 + rand()%MAX;

        start_clock = clock();
        heap_sort(heap_data, MAX);
        end_clock = clock();
        fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));

        fprintf(fp, "\n");
    }
    fclose(fp);

    free(data);
    free(heap_data);

    return 0;
}