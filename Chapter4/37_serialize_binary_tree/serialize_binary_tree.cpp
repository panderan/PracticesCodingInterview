#include "serialize_binary_tree.h"
#include <unistd.h>
#include <cstdio>
#include <stack>

char * serialize(const BinaryTreeNode *root)
{
    if (root == NULL) {
        return NULL;
    }
    
    char *buff = NULL;
    int idx = 0, buff_len=512;
    std::stack<const BinaryTreeNode *> s;
    s.push(root);
    buff = (char *)calloc(buff_len, sizeof(char));

    while (s.empty() == false) {
        char item[64];
        const BinaryTreeNode *tmp = NULL;

        tmp = s.top();
        s.pop();

        if (idx==buff_len) {
            buff_len *= 2;
            buff = (char *) realloc(buff, buff_len);
            if (buff == NULL) {
                free(buff);
                return NULL;
            }
        }
        if (tmp) {
            sprintf(item, "%d,", tmp->m_nValue);
            s.push(tmp->m_pRight);
            s.push(tmp->m_pLeft);
        }
        else {
            strcpy(item, "$,");
        }
        strcat(buff, item);
        idx+=strlen(item);

    }
    buff[--idx]='\0';
    return buff;
}


BinaryTreeNode *_deserialize(const char buff[], int length, int &consume)
{
    BinaryTreeNode *node = NULL;
    int idx = 0, i = 0, value=0, consume_left=0, consume_right=0;
    char item[64] = {0};

    for (idx=0, i=0; idx<length && buff[idx]!=','; item[i++]=buff[idx++]);
    item[i] = '\0';
    consume = idx == length ? strlen(item) : strlen(item)+1;
    
    if (item[0] == '$') {
        return NULL;
    }
    else {
        value = atoi(item);
        node = CreateBinaryTreeNode(value);
        node->m_pLeft = _deserialize(buff+consume, length-consume, consume_left);
        consume += consume_left;
        node->m_pRight = _deserialize(buff+consume, length-consume, consume_right);
        consume += consume_right;
        return node;
    }
}

BinaryTreeNode * deserialize(const char buff[])
{
    int length = 0, consume=0;
    if (buff == NULL) {
        return NULL;
	}

    length = strlen(buff);
    return _deserialize(buff, length, consume);
}








