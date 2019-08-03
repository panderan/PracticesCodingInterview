#include "path_in_tree.h"
#include <unistd.h>

int _find_path(BinaryTreeNode *p_node, int prev_sum, int expected_sum)
{
    int cur_sum = p_node->m_nValue+prev_sum;
    int retval = 0;

    if (cur_sum > expected_sum) {
        return 0;
    }
    else {
        if (p_node->m_pLeft == NULL && p_node->m_pRight == NULL) {
            if (cur_sum == expected_sum) {
                return 1;
            }
            else {
                return 0;
            }
        }
        else {
            if (p_node->m_pLeft) {
                retval = _find_path(p_node->m_pLeft, cur_sum, expected_sum);
            }
            if (p_node->m_pRight) {
                retval += _find_path(p_node->m_pRight, cur_sum, expected_sum);
            }
            return retval;
        }
    }
}

int find_path(BinaryTreeNode *p_root, int expected_sum)
{
    if (p_root == NULL) {
        return 0;
    }

    return  _find_path(p_root, 0, expected_sum);
}

