#include "symmetrical_binary_tree.h"
#include <unistd.h>

bool _is_symmetrical(BinaryTreeNode *p_root1, BinaryTreeNode *p_root2)
{
    if (p_root1 == NULL && p_root2 == NULL) {
        return true;
    }

    if (p_root1 == NULL || p_root2 == NULL) {
        return false;
    }

    if (p_root1->m_nValue == p_root2->m_nValue) {
        return _is_symmetrical(p_root1->m_pLeft, p_root2->m_pRight) 
                && _is_symmetrical(p_root1->m_pRight, p_root2->m_pLeft);
    }
    else {
        return false;
    }
}

bool is_symmetrical(BinaryTreeNode *p_root)
{
    if (p_root == NULL) {
        return false;
    }

    return _is_symmetrical(p_root->m_pLeft, p_root->m_pRight);
}
