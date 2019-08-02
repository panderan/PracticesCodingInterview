#include "mirror_of_binary_tree.h"
#include <queue>

using namespace std;

void mirror_recursively(BinaryTreeNode *pNode)
{
    if (pNode == NULL) {
        return;
    }

    BinaryTreeNode *tmp = pNode->m_pLeft;
    pNode->m_pLeft = pNode->m_pRight;
    pNode->m_pRight = tmp; 

    mirror_recursively(pNode->m_pLeft);
    mirror_recursively(pNode->m_pRight);

    return;
}

void mirror_circulation(BinaryTreeNode *pNode)
{
    queue<BinaryTreeNode *> q;
    
    if (pNode == NULL) {
        return ;
    }

    q.push(pNode);
    while (q.empty() == false) {
        BinaryTreeNode *current = NULL;
        
        current = q.front();
        q.pop();

        if (current->m_pLeft) {
            q.push(current->m_pLeft);
        }
        if (current->m_pRight) {
            q.push(current->m_pRight);
        }

        BinaryTreeNode *exchange = current->m_pLeft;
        current->m_pLeft = current->m_pRight;
        current->m_pRight = exchange;
    }
    return;
}
