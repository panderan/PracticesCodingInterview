#include "construct_binary_tree.h"
#include <unistd.h>

static BinaryTreeNode * construct_core(int *preorder, int p_start, int p_end, 
                                       int *inorder, int i_start, int i_end);

BinaryTreeNode * construct(int *preorder, int *inorder, int length)
{
    if (preorder == NULL || inorder == NULL || length < 1) {
        return NULL;
    }

    BinaryTreeNode* root = construct_core(preorder, 0, length-1, inorder, 0, length-1);
    return root;


}

static BinaryTreeNode * construct_core(int *preorder, int p_start, int p_end, 
                                int *inorder, int i_start, int i_end)
{
    BinaryTreeNode* root = CreateBinaryTreeNode(*(preorder+p_start)) ;

    int idx = 0;
    for (idx = i_start; idx <= i_end; idx++) {
        if (inorder[idx] == root->m_nValue) {
            break;
        }
    }

    if (idx > i_end) {
        return NULL;
    }
    
    int np_start = 0, np_end = 0, ni_start = 0, ni_end = 0;
    int left_total = idx - i_start;

    if (idx == i_start) {
        root->m_pLeft = NULL;
    }
    else {
        np_start = p_start + 1;
        np_end = np_start + left_total - 1; 
        ni_start = i_start;
        ni_end = idx - 1;
        root->m_pLeft = construct_core(preorder, np_start, np_end,
                                     inorder, ni_start, ni_end);
    }

    if (idx == i_end) {
        root->m_pRight = NULL;
    }
    else {
        np_start = p_start + 1 + left_total;
        np_end = p_end;
        ni_start = idx + 1;
        ni_end = i_end;
        root->m_pRight = construct_core(preorder, np_start, np_end,
                                     inorder, ni_start, ni_end);
    }
    return root;
}

