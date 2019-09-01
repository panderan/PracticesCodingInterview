#include "kth_node_in_bst.h"
#include <stack>

const BinaryTreeNode* kth_node(const BinaryTreeNode* proot, unsigned int k)
{
    const BinaryTreeNode *loop = NULL, *tmp = NULL;
    std::stack<const BinaryTreeNode *> s;
    int cnt = 0;

    if (proot == NULL) {
        return NULL;
    }

    for (loop=proot; loop!=NULL; s.push(loop), loop=loop->m_pLeft);
    while (!s.empty()) {
       tmp = s.top();
       cnt++;
       if (cnt == k) {
           return tmp;
       }
       s.pop();
        
        for (loop=tmp->m_pRight; loop!=NULL; s.push(loop), loop=loop->m_pLeft);
    }

    return NULL;
}

