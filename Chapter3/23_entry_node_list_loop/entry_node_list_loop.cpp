#include "entry_node_list_loop.h"
#include <unistd.h>

ListNode * entry_node_list_loop(ListNode *p_head)
{
    if (p_head == NULL) {
        return NULL;
    }
    
    bool has_loop = false;
    ListNode *p_one_step = p_head, *p_two_step = p_head;

    while (p_one_step != NULL && p_two_step != NULL) {
        p_one_step = p_one_step->m_pNext;
        p_two_step = p_two_step->m_pNext==NULL?NULL:p_two_step->m_pNext->m_pNext;

        if (p_one_step == NULL || p_two_step == NULL) {
            return NULL;
        } 

        if (p_two_step == p_one_step) {
            has_loop = true;
            break;
        }
    }
    if (has_loop == false) {
        return NULL;
    }
    
    int cnt_of_node_in_loop = 0;
    p_two_step = p_one_step;
    p_one_step = p_one_step->m_pNext;
    for (cnt_of_node_in_loop=1; 
         p_one_step!=p_two_step; 
         p_one_step = p_one_step->m_pNext, cnt_of_node_in_loop++);
    
    int i = 0;
    ListNode *p_ahead = p_head, *p_follow = p_head;
    for (i=0; p_ahead!=NULL && i<cnt_of_node_in_loop; p_ahead=p_ahead->m_pNext,i++);
    for (;p_follow!=p_ahead; p_follow=p_follow->m_pNext, p_ahead=p_ahead->m_pNext);

    return p_follow;
}

