#include "squence_of_bst.h"
#include <unistd.h>

bool _verify_squence_of_bst(int squence[], int length)
{
    int root = squence[length-1];
    
    if (length == 0) {
        return true;
    }
    
    int separate_idx = 0;
    for (separate_idx = 0; separate_idx < length-1; separate_idx++) {
        if (squence[separate_idx] > root) {
            break;
        }
    }

    for (; separate_idx < length-1-1; separate_idx++) {
        if (squence[separate_idx] < root) {
            return false;
		}
    }

    return _verify_squence_of_bst(squence, separate_idx) &&
            _verify_squence_of_bst(squence+separate_idx, length-separate_idx-1);
}

bool verify_squence_of_bst(int squence[], int length)
{
    if (squence == NULL || length < 1) {
        return false;
    }

    return _verify_squence_of_bst(squence, length);
}
