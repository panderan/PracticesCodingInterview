#include "fibonacci.h"

long long fibonacci(unsigned int n)
{
    long long n1 = 1, n2 = 1, n3 = 0;

    switch (n) {
        case 0:
            return 0;
        case 1:
        case 2:
            return 1;
    }

    for (unsigned int i = 3; i<= n; i++) {
        n3 = n2 + n1;
        n1 = n2;
        n2 = n3;
    }

    return n3;
}
