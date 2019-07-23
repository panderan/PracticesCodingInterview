#include <iostream>
#include "sort.h"

using namespace std;

int main(int argc, char *argv[])
{
    int arr[] = {2,5,12,65,34,7,90,76,2,15,20};
    int length = sizeof(arr)/sizeof(int);
    
    quick_sort_loop(arr, length);
    // quick_sort_recursion(arr, length);
    // merge_sort(arr, length);

    for (int i=0; i<length; i++)
        cout << arr[i] << ", ";
    cout << endl;
    return 0;
}
