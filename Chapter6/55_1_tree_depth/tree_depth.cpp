#include "tree_depth.h"
#include <unistd.h>

int tree_depth(const BinaryTreeNode *proot)
{
    int left = 0, right = 0;

    if (proot == NULL) {
        return 0;
    }

    left = 1 + tree_depth(proot->m_pLeft);
    right = 1 + tree_depth(proot->m_pRight);

    return left>right ? left : right;

}
