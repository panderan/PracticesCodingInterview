#include "convert_binary_search_tree.h"
#include <unistd.h>
void _convert(BinaryTreeNode *node, BinaryTreeNode **head, BinaryTreeNode **tail)
{
    BinaryTreeNode *lch = node->m_pLeft, *rch = node->m_pRight;

    if (lch) {
        _convert(node->m_pLeft, head, tail);
    }

    if (*tail == NULL) {
        *head = node;
        *tail = node;
        (*tail)->m_pLeft = *tail;
        (*tail)->m_pRight = *tail;
    }
    else {
        node->m_pRight = (*tail)->m_pRight;
        (*tail)->m_pRight = node;
        node->m_pLeft = (*tail);
		(*tail) = node;
    }

    if (rch) {
        _convert(rch, head, tail);
    }

}

BinaryTreeNode *convert(BinaryTreeNode *root)
{
    BinaryTreeNode *head=NULL, *tail=NULL;
    _convert(root, &head, &tail);
	tail->m_pLeft = NULL;
	head->m_pRight = NULL;
    return head;
}
