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


