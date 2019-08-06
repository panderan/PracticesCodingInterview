#ifndef _SERIALIZE_BINARY_TREE_H
#define _SERIALIZE_BINARY_TREE_H

#include "../../utilities/BinaryTree.h"

char * serialize(const BinaryTreeNode *root);
BinaryTreeNode * deserialize(const char *);

#endif
