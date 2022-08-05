#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "sort.h"

//ヒープソート用データ
int heap_data[MAX+1];

int main(void){
    int i,j;
    int *data;

    data = (int *)malloc(sizeof(int)*MAX);

    clock_t start_clock, end_clock;

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
    fp = fopen("result_simple.csv", "w");
    if(fp == NULL){
        printf("Fail to open this file.\n");
        return 1;
    }
    else{
        printf("Success to open this file. \n");
    }
    
    heap_data[0] = 0;
    for(i=1; i<MAX+1; i++)
        heap_data[i] = 0 + rand()%MAX;

    //バブル,選択,挿入,シェルソートでソートし、かかった時間をミリ秒単位で書き出し
    for(i=0; i<SIMPLE_FUNC_NUM; i++){
        //整列用データの作成
        for(i=0; i<MAX; i++)
            data[i] = 0 + rand()%MAX;
        
        start_clock = clock();
        simple_sort[i](data);
        end_clock = clock();
        fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
    }
    
    //クイック,マージソート
    int high;
    for(i=0; i<COMP_FUNC_NUM; i++){
        if(i == 1)
            high = high - 1;
        else high = MAX;

        //整列用データの作成
        srand((unsigned int)time(NULL));
        for(i=0; i<MAX; i++)
            data[i] = 0 + rand()%MAX;

        start_clock = clock();
        comp_sort[i](data, 0, high);
        end_clock = clock();
        fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
    }
    
    /*
    //ヒープソート
    start_clock = clock();
    heap_sort(heap_data, MAX);
    end_clock = clock();
    fprintf(fp, "%f,", (double)(end_clock - start_clock)/CLOCKS_PER_SEC*pow(10, 3));
    */

    fprintf(fp, "\n");
    fclose(fp);

    free(data);

    return 0;
}  