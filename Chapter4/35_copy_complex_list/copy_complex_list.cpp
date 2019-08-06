#include "copy_complex_list.h"

complex_list_node_t *create_node(int value)
{
    complex_list_node_t* node = (complex_list_node_t *) malloc(sizeof(complex_list_node_t));
    node->value = value;
    node->next = NULL;
    node->sibling = NULL;
    return node;
}

void build_nodes(complex_list_node_t *node, complex_list_node_t *next, complex_list_node_t *sibling)
{
    if (node != NULL) {
        node->next = next;
        node->sibling = sibling;
    }
}

void destroy_complex_list(complex_list_node_t *head)
{
    complex_list_node_t *loop = head;
    while (loop != NULL) {
        complex_list_node_t *tmp = loop;
        loop = loop->next;
        free(tmp);
    }
}

static int clone_nodes(complex_list_node_t *head)
{
    complex_list_node_t * loop = head;
    while(loop!=NULL) {
        complex_list_node_t *tmp = NULL;
        tmp = (complex_list_node_t *) malloc(sizeof(complex_list_node_t));
        if (tmp == NULL) {
            return 1;
        }
        tmp->value = loop->value;
        tmp->sibling = NULL;
        tmp->next = loop->next;
        loop->next = tmp;
        loop=tmp->next;
    }
    return 0;
}

static int connect_sibling_nodes(complex_list_node_t *head) 
{
    complex_list_node_t *loop = head;
    while (loop!=NULL) {
        if (loop->sibling != NULL) {
            loop->next->sibling = loop->sibling->next;
        }
       loop=loop->next->next;
    }
    return 0;
}

static complex_list_node_t* reconnect_nodes(complex_list_node_t *head)
{
    complex_list_node_t *clone_head = NULL, *clone_loop = NULL;
    complex_list_node_t *loop = head;

    while (loop!=NULL) {
        if (clone_head == NULL) {
            clone_head = loop->next;
            clone_loop = loop->next;
        }
        clone_loop->next = loop->next;
        loop->next = clone_loop->next;
        clone_loop = clone_loop->next;
        if (clone_loop) {
            clone_loop->next = NULL;
        }
        loop = loop->next;
    }
    return clone_head;
}

complex_list_node_t* clone_complex_list(complex_list_node_t *head)
{
    if (clone_nodes(head)) {
        return NULL;
    }
    connect_sibling_nodes(head);
    return reconnect_nodes(head);
}

