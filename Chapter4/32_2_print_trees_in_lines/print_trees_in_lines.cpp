#include "print_trees_in_lines.h"
#include <queue>

void print_trees_in_lines(BinaryTreeNode *p_root, BinaryTreeNode* out[], int length)
{
    int cur_cnt = 0, next_cnt = 0, out_idx = 0;

    if (p_root == NULL || out == NULL || length < 1) {
        return ;
    }

    std::queue<BinaryTreeNode *> q;
    
    q.push(p_root);
    cur_cnt++;
    while (q.empty() == false) {
        if (cur_cnt == 0) {
            cur_cnt = next_cnt;
            next_cnt = 0;
            out[out_idx++] = NULL;
        }
        else {
            BinaryTreeNode *tmp = q.front();
            q.pop();
			cur_cnt--;		
            out[out_idx++] = tmp;

            if (tmp->m_pLeft) {
                q.push(tmp->m_pLeft);
				next_cnt++;
            }
            if (tmp->m_pRight) {
                q.push(tmp->m_pRight);
				next_cnt++;
            }
        }
    }
}

void print_trees_in_lines_with_two_queue(BinaryTreeNode *p_root, BinaryTreeNode* out[], int length)
{
    std::queue<BinaryTreeNode *> q1,q2;
    std::queue<BinaryTreeNode *> *cur = NULL, *next = NULL;
    int out_idx = 0;

    cur = &q1;
    next = &q2;

    if (p_root == NULL || out == NULL || length < 1) {
        return ;
    }

    cur->push(p_root);
    while (q1.empty() == false || q2.empty() == false) {
        BinaryTreeNode *tmp = NULL;
        
        if (cur->empty()) {
            std::queue<BinaryTreeNode *> *exchange = cur;
            cur = next;
            next = exchange;
            out[out_idx++] = NULL;
        }
        else {
            tmp = cur->front();
            cur->pop();
            out[out_idx++] = tmp;

            if (tmp->m_pLeft) {
                next->push(tmp->m_pLeft);
            }
            if (tmp->m_pRight) {
                next->push(tmp->m_pRight);
            }
        }
    }
}









