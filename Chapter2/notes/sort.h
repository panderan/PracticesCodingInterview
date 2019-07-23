#ifndef _SORT_H
#define _SORT_H

int merge_sort_recursion(int arr[], int length);
int merge_sort_loop(int arr[], int length);
int quick_sort_recursion(int arr[], int length);
int quick_sort_loop(int arr[], int length);

#define merge_sort merge_sort_loop
#define quick_sort quick_sort_loop

#endif
