CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

# PROJECT NAME
PROJECT(coding-interview)

SET(CMAKE_CXX_FLAGS " -std=c++11 -g ")

# Sub directories
ENABLE_TESTING()
ADD_SUBDIRECTORY(01_assignment_operator)
ADD_SUBDIRECTORY(02_Singleton)
ADD_SUBDIRECTORY(03_duplication_in_array)
ADD_SUBDIRECTORY(04_find_in_partially_sorted_matrix)
ADD_SUBDIRECTORY(05_replace_spaces)
ADD_SUBDIRECTORY(06_print_list_in_reversed_order)
ADD_SUBDIRECTORY(07_construct_binary_tree)
ADD_SUBDIRECTORY(08_next_node_in_binary_trees)
ADD_SUBDIRECTORY(09_queue_with_two_stacks)
ADD_SUBDIRECTORY(10_fibonacci)
ADD_SUBDIRECTORY(11_min_number_in_rotated_array)

