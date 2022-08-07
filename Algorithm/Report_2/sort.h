#ifndef SORT_H
#define SORT_H

#define MAX 10000
#define SIMPLE_FUNC_NUM 4
#define COMP_FUNC_NUM 2
#define FUNC_NUM (SIMPLE_FUNC_NUM + COMP_FUNC_NUM)

extern void bubble_sort(int *data);
extern void selection_sort(int *data);
extern void insertion_sort(int *data);
extern void shell_sort(int *data);

extern int partition(int *data, int first, int last);
extern void quick_sort(int *data, int first, int last);

extern void merge_sort(int *data, int low, int high);
extern void merge_sort_main(int *data, int low, int high, int *workspace);

void downheap(int from, int to, int heap_data[]);
void heap_sort(int heap_data[], int n);

#endif