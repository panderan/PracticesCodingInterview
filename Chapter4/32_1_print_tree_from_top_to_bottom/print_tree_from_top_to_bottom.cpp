#include "print_tree_from_top_to_bottom.h"
#include <queue>

void print_from_top_to_bottom(BinaryTreeNode *p_root, int out[], int length)
{
    std::queue<BinaryTreeNode *> q;
    int out_idx = 0;

    if (p_root == NULL || out == NULL || length < 1) {
        return;
    }

    q.push(p_root);
    while (q.empty() == false) {
        BinaryTreeNode *cur_node = q.front();
        q.pop();
        out[out_idx++] = cur_node->m_nValue;
        
        if (cur_node->m_pLeft) {
            q.push(cur_node->m_pLeft);
        }
        if (cur_node->m_pRight) {
            q.push(cur_node->m_pRight);
        }
    }
}

