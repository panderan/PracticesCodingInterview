#include "merge_sorted_lists.h"
#include <unistd.h>

ListNode * merge(ListNode *p_head1, ListNode* p_head2)
{
    if (p_head1 == NULL && p_head2 == NULL) {
        return NULL;
    }
    if (p_head1 == NULL) {
        return p_head2;
    }
    if (p_head2 == NULL) {
        return p_head1;
    }

    ListNode *loop1 = NULL, *loop2 = NULL;
    
    loop1 = p_head1->m_nValue < p_head2->m_nValue ? p_head1 : p_head2;
    loop2 = loop1 == p_head1 ? p_head2 : p_head1;
    while (loop1->m_pNext && loop2) {
        ListNode *tmp = NULL;
        for (; loop2 != NULL && loop2->m_nValue < loop1->m_nValue; loop2 = loop2->m_pNext);
        for (; loop1->m_pNext != NULL && loop1->m_pNext->m_nValue < loop2->m_nValue; loop1 = loop1->m_pNext);
        tmp = loop2->m_pNext;
        loop2->m_pNext = loop1->m_pNext;
        loop1->m_pNext = loop2;
        loop2 = tmp;
    }
    if (loop1->m_pNext == NULL && loop2) {
        loop1->m_pNext = loop2;
    }

    return p_head1->m_nValue < p_head2->m_nValue ? p_head1 : p_head2;;
}
