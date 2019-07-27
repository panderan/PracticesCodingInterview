#include "delete_node.h"
#include <unistd.h>

void delete_node(ListNode** p_list_head, ListNode* p_to_be_deleted)
{
    if (p_list_head == NULL 
        || *p_list_head == NULL
        || p_to_be_deleted == NULL) {
        return ;
    }

    if (p_to_be_deleted->m_pNext == NULL) {
        if (*p_list_head == p_to_be_deleted) {
            delete p_to_be_deleted;
            *p_list_head = NULL;
            return ;
            
        }
        else {
            ListNode *prev_node = *p_list_head;
            while (prev_node != NULL && prev_node->m_pNext != p_to_be_deleted) {
                prev_node = prev_node->m_pNext;
            }
            if (prev_node == NULL) {
                return ;
            }
            prev_node->m_pNext = NULL;
            delete p_to_be_deleted; 
        }
    }
    else {
        ListNode *next_node = p_to_be_deleted->m_pNext;
        p_to_be_deleted->m_nValue = next_node->m_nValue;
        p_to_be_deleted->m_pNext = next_node->m_pNext;
        delete next_node;
    }
    return ;
}




