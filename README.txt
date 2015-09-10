Compilation Instructions
Problem 1) gcc Problem1.c -o Problem1 -std=c99
Problem 2) gcc Problem2.c -o Problem2 -std=c99 -lm
Problem 3) gcc Problem3.c -o Problem3
Problem 4) Requires -std=c99
Problem 5) gcc sets.c -o Problem5 -std=c99


Running instructions
Problem 1) ./Problem1
Problem 2) ./Problem2 <Your number here>
Problem 3) ./Problem3 <source file> <destination file>
Problem 4) If you want to run the unit tests run
   gcc -std=c99 test/utility/test_runner.c test/utility/test_runner.h test/runTests.c list.c list.h test/linkedlist/doubly_linked_list_test.c test/linkedlist/doubly_linked_list_test.h -o Problem4Test -g
   ./Problem4Test
Problem 5) ./Problem5
   Toggle USE_ARRAY on and off. If array is off, you can define USE_LIST_OPT to enable a simple
   list optimization (it keeps track of the last accessed item and uses that instead of the head
   to add elements if its faster).
   
   The graphs are in Problem5.xlsx
