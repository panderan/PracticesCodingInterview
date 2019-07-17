#include "print_list_in_reversed_order.h"
#include <iostream>
#include <stack>
#include <cstring>

void print_list_in_reversed_order(ListNode *p_head, char buff[], int length)
{
    std::stack<ListNode*> nodes;
    
    if (p_head == NULL || buff == NULL) {
        return;
    }

    ListNode *p_node = p_head;
    while (p_node != NULL) {
        nodes.push(p_node);
        p_node = p_node->m_pNext;
    }

    strcpy(buff, "");
    char *chptr = buff;
    while (nodes.empty() == false) {
        p_node = nodes.top();
        sprintf(chptr, "%d,", p_node->m_nValue);
        nodes.pop();
        chptr = buff + strlen(buff);
    }
    buff[strlen(buff)-1] = '\0';

    return;
}

