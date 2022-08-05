#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

int main(){
    int i,j,k;

    //実行回数
    int num = 30;

    //clock関数の戻り値格納用
    clock_t start_clock, end_clock;

    //データのメモリを動的確保
    int *data, *heap_data;
    data = (int *)malloc(sizeof(int)*MAX);
    heap_data = (int *)malloc(sizeof(int)*MAX);

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
    fp = fopen("result_1000.csv", "a+");
    if(fp == NULL){
        printf("Fail to open this file.\n");
        return 1;
    }
    else{
        printf("Success to open this file. \n");
    }

    for(k=0; k<num; k++){
        //バブル,選択,挿入,シェルソート
        for(i=0; i<SIMPLE_FUNC_NUM; i++){
            //整列用データの作成
            for(j=0; j<MAX; j++)
                srand((unsigned int)time(NULL));
                data[j] = 0 + rand()%MAX;

            start_clock = clock();
            simple_sort[i](data);
            end_clock = clock();
            fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
        }

        //クイック,マージソート
        int high;
        for(i=0; i<COMP_FUNC_NUM; i++){
            if(i == 1)
                high = MAX - 1;
            else high = MAX;

            //整列用データの作成
            for(j=0; j<MAX; j++)
                srand((unsigned int)time(NULL));
                data[j] = 0 + rand()%MAX;

            start_clock = clock();
            comp_sort[i](data, 0, high);
            end_clock = clock();
            fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
        }

        //ヒープソート
        //整列用データの作成
        for(i=0; i<MAX+1; i++)
            heap_data[i] = 0 + rand()%MAX;

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