#include "reverse_list.h"
#include <unistd.h>

ListNode * reverse_list(ListNode *p_head)
{
    ListNode *p_ahead = NULL, *p_middle = NULL, *p_tail = NULL;

    if (p_head == NULL || p_head->m_pNext == NULL) {
        return p_head;
    }

    p_middle = p_head;
    p_ahead = p_head->m_pNext;
    do {
        p_middle->m_pNext = p_tail;

        p_tail = p_middle;
        p_middle = p_ahead;
        p_ahead = p_ahead->m_pNext;
    } while (p_ahead->m_pNext != NULL);
    p_ahead->m_pNext = p_middle;
    p_middle->m_pNext = p_tail;

    return p_ahead;
}

