#include "next_node_in_binary_trees.h"
#include <unistd.h>

BinaryTreeNode * get_next(BinaryTreeNode *pNode)
{
    BinaryTreeNode * retval = NULL;

    if (pNode->m_pRight != NULL) {
        retval = pNode->m_pRight;
        while (retval != NULL) {
            if (retval->m_pLeft != NULL) {
                retval = retval->m_pLeft;
            }
            return retval;
        }
    }
    else {
        retval = pNode; 
        while(retval != NULL) {
            if (retval->m_pParent == NULL) {
                return NULL;
            }
            if (retval->m_pParent->m_pLeft == retval) {
                return retval->m_pParent;
            }
            retval = retval->m_pParent;
        }
    }
    return NULL;
    
}
