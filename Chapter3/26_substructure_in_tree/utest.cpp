#include "utest.h"
#include "substructure_in_tree.h"
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

// 树中结点含有分叉，树B是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     2
//               / \
//              4   7
void unit_test::first_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	CPPUNIT_ASSERT_MESSAGE("Test1", has_sub_tree(pNodeA1, pNodeB1) == true);

    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
    return;
}

// 树中结点含有分叉，树B不是树A的子结构
//                  8                8
//              /       \           / \
//             8         7         9   2
//           /   \
//          9     3
//               / \
//              4   7
void unit_test::second_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(7);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeA6 = CreateBinaryTreeNode(4);
    BinaryTreeNode* pNodeA7 = CreateBinaryTreeNode(7);

    ConnectTreeNodes(pNodeA1, pNodeA2, pNodeA3);
    ConnectTreeNodes(pNodeA2, pNodeA4, pNodeA5);
    ConnectTreeNodes(pNodeA5, pNodeA6, pNodeA7);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, pNodeB3);

	CPPUNIT_ASSERT_MESSAGE("Test2", has_sub_tree(pNodeA1, pNodeB1) == false);
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    2
//         /      
//        2        
//       /
//      5
void unit_test::third_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
    ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
    ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
    ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
    ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

	CPPUNIT_ASSERT_MESSAGE("Test3", has_sub_tree(pNodeA1, pNodeB1) == true);
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有左子结点，树B不是树A的子结构
//                8                  8
//              /                   / 
//             8                   9   
//           /                    /
//          9                    3
//         /      
//        2        
//       /
void unit_test::fourth_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, pNodeA2, nullptr);
    ConnectTreeNodes(pNodeA2, pNodeA3, nullptr);
    ConnectTreeNodes(pNodeA3, pNodeA4, nullptr);
    ConnectTreeNodes(pNodeA4, pNodeA5, nullptr);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);

    ConnectTreeNodes(pNodeB1, pNodeB2, nullptr);
    ConnectTreeNodes(pNodeB2, pNodeB3, nullptr);

	CPPUNIT_ASSERT_MESSAGE("Test4", has_sub_tree(pNodeA1, pNodeB1) == false);
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树中结点只有右子结点，树B是树A的子结构
//       8                   8
//        \                   \
//         8                   9   
//          \                   \
//           9                   2
//            \
//             2        
//              \
//               5
void unit_test::fifth_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
    ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
    ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, nullptr, pNodeB3);

	CPPUNIT_ASSERT_MESSAGE("Test5", has_sub_tree(pNodeA1, pNodeB1) == true);
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

// 树A中结点只有右子结点，树B不是树A的子结构
//       8                   8
//        \                   \
//         8                   9   
//          \                 / \
//           9               3   2
//            \
//             2        
//              \
//               5
void unit_test::sixth_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);
    BinaryTreeNode* pNodeA5 = CreateBinaryTreeNode(5);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, nullptr, pNodeA3);
    ConnectTreeNodes(pNodeA3, nullptr, pNodeA4);
    ConnectTreeNodes(pNodeA4, nullptr, pNodeA5);

    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

	CPPUNIT_ASSERT_MESSAGE("Test6", has_sub_tree(pNodeA1, pNodeB1) == false);
    DestroyTree(pNodeA1);
    DestroyTree(pNodeB1);
}

void unit_test::seventh_test()
{
    BinaryTreeNode* pNodeB1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeB2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeB3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeB4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeB1, nullptr, pNodeB2);
    ConnectTreeNodes(pNodeB2, pNodeB3, pNodeB4);

	CPPUNIT_ASSERT_MESSAGE("Test7", has_sub_tree(NULL, pNodeB1) == false);
    DestroyTree(pNodeB1);
}

void unit_test::eighth_test()
{
    BinaryTreeNode* pNodeA1 = CreateBinaryTreeNode(8);
    BinaryTreeNode* pNodeA2 = CreateBinaryTreeNode(9);
    BinaryTreeNode* pNodeA3 = CreateBinaryTreeNode(3);
    BinaryTreeNode* pNodeA4 = CreateBinaryTreeNode(2);

    ConnectTreeNodes(pNodeA1, nullptr, pNodeA2);
    ConnectTreeNodes(pNodeA2, pNodeA3, pNodeA4);

	CPPUNIT_ASSERT_MESSAGE("Test8", has_sub_tree(pNodeA1, NULL) == false);
    DestroyTree(pNodeA1);
}

void unit_test::nineth_test()
{
	CPPUNIT_ASSERT_MESSAGE("Test8", has_sub_tree(NULL, NULL) == false);
}
