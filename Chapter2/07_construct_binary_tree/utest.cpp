#include "../../utest.h"
#include "construct_binary_tree.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void unit_test::setUp()
{
    return;
}

void unit_test::tearDown()
{
    return;
}

void unit_test::first_test()
{
    BinaryTreeNode * root = NULL;
    printf("Test1\n");
    int preorder1[8] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder1[8] = {4, 7, 2, 1, 5, 3, 8, 6};
    root = construct(preorder1, inorder1, 8);
    PrintTree(root);
    DestroyTree(root);

    printf("Test2\n");
    int preorder2[5] = {1, 2, 3, 4, 5};
    int inorder2[5] = {5, 4, 3, 2, 1};
    root = construct(preorder2, inorder2, 5);
    PrintTree(root);
    DestroyTree(root);

    printf("Test3\n");
    int preorder3[5] = {1, 2, 3, 4, 5};
    int inorder3[5] = {1, 2, 3, 4, 5};
    root = construct(preorder3, inorder3, 5);
    PrintTree(root);
    DestroyTree(root);

    printf("Test4\n");
    int preorder4[1] = {1};
    int inorder4[1] = {1};
    root = construct(preorder4, inorder4, 1);
    PrintTree(root);
    DestroyTree(root);

    printf("Test5\n");
    int preorder5[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder5[7] = {4, 2, 5, 1, 6, 3, 7};
    root = construct(preorder5, inorder5, 7);
    PrintTree(root);
    DestroyTree(root);

    printf("Test6\n");
    construct(NULL, NULL, 0);

    printf("Test7\n");
    int preorder6[7] = {1, 2, 4, 5, 3, 6, 7};
    int inorder6[7] = {4, 2, 8, 1, 6, 3, 7};
    root = construct(preorder6, inorder6, 7);
    PrintTree(root);
    DestroyTree(root);

    return;
}


