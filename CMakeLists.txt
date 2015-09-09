cmake_minimum_required(VERSION 3.3)
project(Homework1)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

set(TEST_FILES test/utility/test_runner.c test/utility/test_runner.h test/runTests.c list.c list.h test/linkedlist/doubly_linked_list_test.c test/linkedlist/doubly_linked_list_test.h)
add_executable(Problem1 Problem1.c)
add_executable(Problem2 Problem2.c)
add_executable(Problem3 Problem3.c)
add_executable(Problem4 Problem4.c list.c list.h)
add_executable(Problem5 sets.c)
add_executable(Problem4Test ${TEST_FILES})