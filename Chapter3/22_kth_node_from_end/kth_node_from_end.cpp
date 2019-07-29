#include "kth_node_from_end.h"
#include <unistd.h>

ListNode* find_kth_to_tail(ListNode *p_head, unsigned int k)
{
    if (p_head == NULL || k < 1) {
        return NULL;
    }

    ListNode *p_ahead = NULL, *p_follow = NULL;
	int i = 0;
    for (i=0, p_ahead=p_head; i<k-1 && p_ahead!=NULL; p_ahead=p_ahead->m_pNext, i++);
    for (p_follow=p_head; p_ahead!=NULL && p_ahead->m_pNext!=NULL; p_follow=p_follow->m_pNext, p_ahead=p_ahead->m_pNext);

    if (p_ahead == NULL) {
        return NULL;
    }
    else {
        return p_follow;
    }
}

