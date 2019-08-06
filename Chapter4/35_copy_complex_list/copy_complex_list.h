#ifndef _COPY_COMPLEX_LIST_H
#define _COPY_COMPLEX_LIST_H

#include <unistd.h>
#include <cstdlib>
typedef struct complex_list_node {
    int value;
    struct complex_list_node *next;
    struct complex_list_node *sibling;
} complex_list_node_t;

complex_list_node_t *create_node(int value);
void build_nodes(complex_list_node_t *node, complex_list_node_t *next, complex_list_node_t *sibling);
void destroy_complex_list(complex_list_node_t *head);
complex_list_node_t *clone_complex_list(complex_list_node_t *head);

#endif

