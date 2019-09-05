#include "balenced_binary_tree.h"
#include <unistd.h>
#include <cstdlib>

bool _is_balenced(BinaryTreeNode *proot, int &depth)
{
    BinaryTreeNode *left = NULL, *right = NULL;
    int left_depth = 0, right_depth = 0;
    bool retval = true;

    if (proot == NULL) {
        depth = 0;
        return false;
    }

    retval = retval && _is_balenced(proot->m_pLeft, left_depth);
    retval = retval && _is_balenced(proot->m_pRight, right_depth);

    if (abs(left_depth - right_depth) > 1) {
        return false;
    }

    depth = left_depth > right_depth ? left_depth+1 : right_depth+1;

    return true;
}


bool is_balenced(BinaryTreeNode *proot)
{
    int depth = 0;
    return _is_balenced(proot, depth);
}
