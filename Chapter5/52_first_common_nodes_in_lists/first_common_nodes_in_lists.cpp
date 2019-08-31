#include "first_common_nodes_in_lists.h"
#include <unistd.h>

ListNode * find_first_common_node(ListNode *phead1, ListNode *phead2)
{
    int len1 = 0, len2 = 0;
    ListNode *loop1 = NULL, *loop2 = NULL;

    if (phead1 == NULL || phead2 == NULL) {
        return NULL;
    }

    for (loop1=phead1,len1=0; loop1!=NULL; loop1=loop1->m_pNext,len1++);
    for (loop2=phead2,len2=0; loop2!=NULL; loop2=loop2->m_pNext,len2++);
    
    loop1 = phead1;
    loop2 = phead2;
    if (len1 > len2) {
        for (; len1!=len2; loop1=loop1->m_pNext,len1--);
    }
    else {
        for (; len2!=len1; loop2=loop2->m_pNext,len2--);
    }

    while (loop1!=NULL && loop2!=NULL) {
        if (loop1 == loop2) {
            return loop1;
        }
		loop1 = loop1->m_pNext;
		loop2 = loop2->m_pNext;
    }

    return NULL;
}
