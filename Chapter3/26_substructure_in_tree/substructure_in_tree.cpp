#include "substructure_in_tree.h"
#include <unistd.h>

bool _has_sub_tree(BinaryTreeNode *p_root, BinaryTreeNode *p_sub_root)
{
	bool retval = false;

    if (p_sub_root == NULL) {
        return true;
    }

    if (p_root == NULL) {
        return false;
    }

    if (p_root->m_nValue == p_sub_root->m_nValue) {
        retval = _has_sub_tree(p_root->m_pLeft, p_sub_root->m_pLeft) && 
                	_has_sub_tree(p_root->m_pRight, p_sub_root->m_pRight);
		if (retval == true) {
			return retval;
		}
    }
	
	if (p_sub_root->m_pParent != NULL) {
		return false;
	}
    else {
        return _has_sub_tree(p_root->m_pLeft, p_sub_root) || 
                _has_sub_tree(p_root->m_pRight, p_sub_root);
    }

    
}

bool has_sub_tree(BinaryTreeNode *p_root, BinaryTreeNode *p_sub_root)
{
    if (p_root == NULL || p_sub_root == NULL) {
        return false;
    }

    return _has_sub_tree(p_root, p_sub_root);
}

