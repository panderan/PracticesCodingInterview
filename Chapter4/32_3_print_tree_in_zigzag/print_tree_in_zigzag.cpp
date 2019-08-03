#include "print_tree_in_zigzag.h"
#include <stack>
#include <unistd.h>

void print_tree_in_zigzag(BinaryTreeNode *p_root, BinaryTreeNode* out[], int length)
{
    std::stack<BinaryTreeNode *> s1, s2;
    std::stack<BinaryTreeNode *> *s_cur = NULL, *s_next =NULL;
    int out_idx = 0;
    bool flag = true;

    if (p_root == NULL || out == NULL || length < 1) {
        return ;
    }

    s_cur = &s1;
    s_next = &s2;

    s_cur->push(p_root);
    while (s1.empty() == false || s2.empty() == false) {
        if (s_cur->empty()) {
            std::stack<BinaryTreeNode *> *exchange = s_cur;
            s_cur = s_next;
            s_next = exchange;
            out[out_idx++] = NULL;
            flag = !flag;
        }
        else {
            BinaryTreeNode * tmp = s_cur->top();
            BinaryTreeNode * nxt1 = flag ? tmp->m_pLeft : tmp->m_pRight;
            BinaryTreeNode * nxt2 = nxt1 == tmp->m_pLeft ? tmp->m_pRight : tmp->m_pLeft;

            s_cur->pop();
            out[out_idx++] = tmp;
            if (nxt1) {
                s_next->push(nxt1);
            }
            if (nxt2) {
                s_next->push(nxt2);
            }
        }
    }
}
