#include "utest.h"
#include "copy_complex_list.h"
#include <cstring>

CPPUNIT_TEST_SUITE_REGISTRATION(unit_test);

void verify(const char * message, complex_list_node_t *origin)
{
	complex_list_node_t *origin_loop = origin, *clone = NULL, *clone_loop = NULL;

	clone = clone_complex_list(origin);
	clone_loop = clone;

	while (origin_loop != NULL && clone_loop != NULL) {
		CPPUNIT_ASSERT_MESSAGE(message, origin_loop->value == clone_loop->value);
		if (origin_loop->sibling != NULL && clone_loop->sibling != NULL) {
			CPPUNIT_ASSERT_MESSAGE(message, origin_loop->sibling->value == clone_loop->sibling->value);
		}
        origin_loop = origin_loop->next;
        clone_loop = clone_loop->next;
	}
}

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
    complex_list_node_t* pNode1 = create_node(1);
    complex_list_node_t* pNode2 = create_node(2);
    complex_list_node_t* pNode3 = create_node(3);
    complex_list_node_t* pNode4 = create_node(4);
    complex_list_node_t* pNode5 = create_node(5);

    build_nodes(pNode1, pNode2, pNode3);
    build_nodes(pNode2, pNode3, pNode5);
    build_nodes(pNode3, pNode4, nullptr);
    build_nodes(pNode4, pNode5, pNode2);
	
	verify("Test1", pNode1);

    return;
}


void unit_test::second_test()
{
    complex_list_node_t* pNode1 = create_node(1);
    complex_list_node_t* pNode2 = create_node(2);
    complex_list_node_t* pNode3 = create_node(3);
    complex_list_node_t* pNode4 = create_node(4);
    complex_list_node_t* pNode5 = create_node(5);

    build_nodes(pNode1, pNode2, nullptr);
    build_nodes(pNode2, pNode3, pNode5);
    build_nodes(pNode3, pNode4, pNode3);
    build_nodes(pNode4, pNode5, pNode2);

	verify("Test2", pNode1);
}


void unit_test::third_test()
{
    complex_list_node_t* pNode1 = create_node(1);
    complex_list_node_t* pNode2 = create_node(2);
    complex_list_node_t* pNode3 = create_node(3);
    complex_list_node_t* pNode4 = create_node(4);
    complex_list_node_t* pNode5 = create_node(5);

    build_nodes(pNode1, pNode2, nullptr);
    build_nodes(pNode2, pNode3, pNode4);
    build_nodes(pNode3, pNode4, nullptr);
    build_nodes(pNode4, pNode5, pNode2);

    verify("Test3", pNode1);

}


void unit_test::fourth_test()
{
    complex_list_node_t* pNode1 = create_node(1);
    build_nodes(pNode1, nullptr, pNode1);

    verify("Test4", pNode1);
}


void unit_test::fifth_test()
{
	verify("Test5", NULL);
}

