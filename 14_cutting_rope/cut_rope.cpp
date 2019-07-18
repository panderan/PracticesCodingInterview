#include "cut_rope.h"
#include <unistd.h>
#include <cstdlib>
#include <cmath>

int max_product_cut_rope(int length)
{   
    switch (length) {
        case 0:
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
    }

    int *products = NULL;

    products = (int *)calloc(sizeof(int), length+1);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    for (int i = 4; i < length+1; i++) {
        int middle = i / 2;
        int prod = 0, max_prod = 0;
        for (int j = 1; j <= middle; j++) {
            prod = products[j] * products[i-j];
            max_prod = max_prod < prod ? prod : max_prod;
        }
        products[i] = max_prod;
    }

    return products[length];
}

int max_product_cut_rope2(int length) 
{
    switch (length) {
        case 0:
        case 1:
            return 0;
        case 2:
            return 1;
        case 3:
            return 2;
        case 4:
            return 4;
    }

    int time_of_3 = 0, time_of_2 = 0;
    time_of_3 = length%3==1 ? length/3-1 : length/3;
    time_of_2 = (length - time_of_3*3)/2;

    return (int) (pow(3, time_of_3)*pow(2,time_of_2));
}
