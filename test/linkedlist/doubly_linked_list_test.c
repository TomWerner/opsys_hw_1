//
// Created by Test on 8/25/15.
//

#include "doubly_linked_list_test.h"
#include "../utility/test_runner.h"
#include "../../list.h"
#include <stdlib.h>
#include <stdio.h>

bool testDLCreateDLList(char **testName) {
    nameTest(testName, "dlCreateList create node");

    slist_t list;
    init(&list);
    add(&list, "hello", 0);

    if (!assertEqualsSm("Node value initialized correctly", "hello", list.head->value)) return false;
    if (!assertEqualsIm("The list only has 1 element", 1, size(&list))) return false;

    if (!assertEqualsLm("Forward link correct", (long) list.head, (long) list.head->next)) return false;
    if (!assertEqualsLm("Backward link correct", (long) list.head, (long) list.head->prev)) return false;

    return true;
}

bool testDLAddAfterWithOneValue(char **testName) {
    nameTest(testName, "dlAddAfter with just the head");

    slist_t list;
    init(&list);
    add(&list, "hi", 0);
    add(&list, "there", 1); // hi --> there
    list_item_t* head = list.head;

    if (!assertEqualsIm("The list has two elements", 2, size(&list))) return false;
    if (!assertEqualsLm("head.next = head.prev", (long) head->next, (long) head->prev)) return false;
    if (!assertEqualsSm("head has correct value", "hi", head->value)) return false;
    if (!assertEqualsSm("new node has correct value", "there", head->next->value)) return false;
    if (!assertEqualsSm("last node has correct value", "there", head->prev->value)) return false;
    if (!assertEqualsSm("tail has correct value", "there", list.tail->value)) return false;

    return true;
}

bool testDLAddAfterWithNextValue(char **testName) {
    nameTest(testName, "dlAddAfter in the middle");

    slist_t list;
    init(&list);
    add(&list, "5", 0);
    add(&list, "6", 1);
    add(&list, "8", 2);
    add(&list, "7", 3);
    list_item_t* head = list.head;

    if (!assertEqualsIm("The list has 4 elements", 4, size(&list))) return false;
    if (!assertEqualsSm("head has correct value", "5", head->value)) return false;
    if (!assertEqualsSm("a", "6", head->next->value)) return false;
    if (!assertEqualsSm("b", "8", head->next->next->value)) return false;
    if (!assertEqualsSm("c", "7", head->next->next->next->value)) return false;
    if (!assertEqualsSm("d", "5", head->next->next->next->next->value)) return false;
    if (!assertEqualsSm("e", "7", head->prev->value)) return false;
    if (!assertEqualsSm("f", "8", head->prev->prev->value)) return false;
    if (!assertEqualsSm("g", "6", head->prev->prev->prev->value)) return false;
    if (!assertEqualsSm("h", "5", head->prev->prev->prev->prev->value)) return false;
    if (!assertEqualsLm("Tail is correct", (long) head->prev, (long) list.tail)) return false;

    return true;
}

bool testDLAddAfterWithNullHead(char **testName) {
    nameTest(testName, "dlAddAfter with the null head");

    add(NULL, "3", 0);

    return true;
}

bool testDLAddBeforeWithNextValue(char **testName) {
    nameTest(testName, "dlAddAfter in the middle");

    slist_t list;
    init(&list);
    add(&list, "5", 0);
    add(&list, "7", 1);
    add(&list, "8", 2);
    add(&list, "6", 3);
    list_item_t* head = list.head;

    if (!assertEqualsIm("The list has 4 elements", 4, size(&list))) return false;
    if (!assertEqualsSm("head has correct value", "5", head->value)) return false;

    if (!assertEqualsS("7", head->next->value)) return false;
    if (!assertEqualsS("8", head->next->next->value)) return false;
    if (!assertEqualsS("6", head->next->next->next->value)) return false;
    if (!assertEqualsS("5", head->next->next->next->next->value)) return false;

    if (!assertEqualsS("6", head->prev->value)) return false;
    if (!assertEqualsS("8", head->prev->prev->value)) return false;
    if (!assertEqualsS("7", head->prev->prev->prev->value)) return false;
    if (!assertEqualsS("5", head->prev->prev->prev->prev->value)) return false;
    if (!assertEqualsLm("Tail is correct", (long) head->prev, (long) list.tail)) return false;

    return true;
}

bool testDLAddBeforeWithOneValue(char **testName) {
    nameTest(testName, "dlAddBefore with just the head");

    slist_t list;
    init(&list);
    add(&list, "5", 0);
    add(&list, "7", 1);
    list_item_t* head = list.head;

    if (!assertEqualsIm("The list has two elements", 2, size(&list))) return false;
    if (!assertEqualsLm("head.next = head.prev", (long) head->next, (long) head->prev)) return false;
    if (!assertEqualsSm("head has correct value", "5", head->value)) return false;
    if (!assertEqualsSm("new node has correct value", "7", head->next->value)) return false;
    if (!assertEqualsSm("last node has correct value", "7", head->prev->value)) return false;
    if (!assertEqualsLm("Tail is correct", (long) head->prev, (long) list.tail)) return false;

    return true;
}

bool testDLAddBeforeWithNullHead(char **testName) {
    nameTest(testName, "dlAddBefore with the null head");

    add(NULL, "3", 0);

    return true;
}

bool testDLEmptyNullList(char **testName) {
    nameTest(testName, "empty with null list");

    slist_t list_;
    slist_t *list = &list_;
    init(list);
    empty(list);

    return true;
}

bool testDLEmptyOneNode(char **testName) {
    nameTest(testName, "empty with one node");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "5", 0);
    if (!assertEqualsIm("one element", 1, size(list))) return false;

    empty(list);

    if (!assertEqualsIm("emptied", 0, size(list))) return false;

    return true;
}

bool testDLEmptyMultipleNodes(char **testName) {
    nameTest(testName, "empty with one node");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "1", 0);
    add(list, "2", 0);
    add(list, "3", 0);
    add(list, "4", 0);
    add(list, "5", 0);
    add(list, "6", 0);
    add(list, "7", 0);
    add(list, "8", 0);
    if (!assertEqualsIm("8 elements", 8, size(list))) return false;

    empty(list);

    if (!assertEqualsIm("emptied", 0, size(list))) return false;

    return true;
}

bool testDLSortEmptyList(char **testName) {
    nameTest(testName, "sort empty list");

    slist_t list_;
    slist_t* list = &list_;
    init(list);

    bublesort(list);

    return true;
}

bool testDLSortSingleElem(char **testName) {
    nameTest(testName, "sort single element");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "12", 0);

    bublesort(list);
    if (!assertEqualsS(list->head->value, "12")) return false;

    return true;
}

bool testDLSortTwoElemOutOfOrder(char **testName) {
    nameTest(testName, "sort two elem out of order");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "b", 0);
    add(list, "a", 1);

    if (!assertEqualsSm("1", "b", list->head->value)) return false;
    if (!assertEqualsSm("2", "a", list->head->next->value)) return false;

    bublesort(list);

    if (!assertEqualsSm("3", "a", list->head->value)) return false;
    if (!assertEqualsSm("4", "b", list->head->next->value)) return false;

    return true;
}

bool testDLSortTwoElemInOrder(char **testName) {
    nameTest(testName, "sort two elem in order");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "a", 0);
    add(list, "b", 1);

    if (!assertEqualsS(list->head->value, "a")) return false;
    if (!assertEqualsS(list->head->next->value, "b")) return false;

    bublesort(list);

    if (!assertEqualsS(list->head->value, "a")) return false;
    if (!assertEqualsS(list->head->next->value, "b")) return false;

    return true;
}

bool testDLSortMultiInOrder(char **testName) {
    nameTest(testName, "sort multi elem in order");

    slist_t list_;
    slist_t* list = &list_;
    init(list);
    add(list, "a", 0);
    add(list, "b", 1);
    add(list, "c", 2);
    add(list, "d", 3);
    add(list, "e", 4);

    if (!assertEqualsS("a", list->head->value)) return false;
    if (!assertEqualsS("b", list->head->next->value)) return false;
    if (!assertEqualsS("c", list->head->next->next->value)) return false;
    if (!assertEqualsS("d", list->head->next->next->next->value)) return false;
    if (!assertEqualsS("e", list->head->next->next->next->next->value)) return false;

    bublesort(list);

    if (!assertEqualsS("a", list->head->value)) return false;
    if (!assertEqualsS("b", list->head->next->value)) return false;
    if (!assertEqualsS("c", list->head->next->next->value)) return false;
    if (!assertEqualsS("d", list->head->next->next->next->value)) return false;
    if (!assertEqualsS("e", list->head->next->next->next->next->value)) return false;

    return true;
}

bool testDLSortMultiOutOfOrder(char **testName) {
    nameTest(testName, "sort multi elem out of order");

    slist_t list_;
    slist_t* list = &list_;
    init(list);

    add(list, "ab", 0);
    add(list, "d", 1);
    add(list, "b", 2);
    add(list, "c", 3);
    add(list, "e", 4);
    add(list, "A", 5);
    add(list, "z", 6);
    add(list, "3", 7);
    add(list, "aa", 8);
    add(list, "1a3", 9);

    if (!assertEqualsS("ab",  list->head->value)) return false;
    if (!assertEqualsS("d",   list->head->next->value)) return false;
    if (!assertEqualsS("b",   list->head->next->next->value)) return false;
    if (!assertEqualsS("c",   list->head->next->next->next->value)) return false;
    if (!assertEqualsS("e",   list->head->next->next->next->next->value)) return false;
    if (!assertEqualsS("A",   list->head->next->next->next->next->next->value)) return false;
    if (!assertEqualsS("z",   list->head->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsS("3",   list->head->next->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsS("aa",  list->head->next->next->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsS("1a3", list->head->next->next->next->next->next->next->next->next->next->value)) return false;

    bublesort(list);

    if (!assertEqualsSm("1", "1a3", list->head->value)) return false;
    if (!assertEqualsSm("2", "3",   list->head->next->value)) return false;
    if (!assertEqualsSm("3", "A",   list->head->next->next->value)) return false;
    if (!assertEqualsSm("4", "aa",  list->head->next->next->next->value)) return false;
    if (!assertEqualsSm("5", "ab",  list->head->next->next->next->next->value)) return false;
    if (!assertEqualsSm("6", "b",   list->head->next->next->next->next->next->value)) return false;
    if (!assertEqualsSm("7", "c",   list->head->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsSm("8", "d",   list->head->next->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsSm("9", "e",   list->head->next->next->next->next->next->next->next->next->value)) return false;
    if (!assertEqualsSm("10","z",   list->head->next->next->next->next->next->next->next->next->next->value)) return false;

    return true;
}
