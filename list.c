//
// Created by twrner on 8/31/15.
//

#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void init(slist_t *list) {
    if (list == NULL) {
        return;
    }

    list->head = NULL;
    list->tail = NULL;
}

list_item_t* createItem(char* value) {
    list_item_t* newItem = malloc(sizeof(list_item_t));
    if (newItem == NULL) {
        printf("Error allocating space for new item.\n");
        return NULL;
    }
    newItem->value = malloc(strlen(value) * sizeof(char));
    if (newItem->value == NULL) {
        printf("Error allocating space for new item's value\n");
        return NULL;
    }
    strncpy(newItem->value, value, strlen(value) + 1);
    newItem->value[strlen(value)] = '\0';

    newItem->next = NULL;
    newItem->prev = NULL;

    return newItem;
}

void add(slist_t *list, char* value, int position) {
    if (list == NULL) {
        printf("Error: Cannot add value to NULL list\n");
        return;
    }

    list_item_t* newNode = createItem(value);
    list_item_t* node = list->head;

    for (int i = 1; i < position; i++) {
        node = node->next;
    }

    //No nodes
    if (node == NULL) {
        list->head = newNode;
        list->tail = newNode;
        newNode->next = newNode;
        newNode->prev = newNode;
    }
    // One node
    else if (node->next == node) {
        newNode->prev = node;
        newNode->next = node;
        node->next = newNode;
        node->prev = newNode;
    }
    // Two nodes
    else if (node->next == node->prev) {
        list_item_t* other = node->next;
        node->next = newNode;
        newNode->next = other;
        other->next = node;

        node->prev = other;
        other->prev = newNode;
        newNode->prev = node;
    }
    // N nodes
    else {
        list_item_t* next = node->next;
        node->next = newNode;
        newNode->prev = node;
        next->prev = newNode;
        newNode->next = next;
    }

    list->tail = list->head->prev;
}

void print(slist_t *list) {
    if (list == NULL || list->head == NULL) {
        return;
    }
    list_item_t* iterator = list->head;
    printf("%s ", iterator->value);
    iterator = iterator->next;

    while (iterator != NULL && iterator != list->head) {
        printf("%s ", iterator->value);
        iterator = iterator->next;
    }
    printf("\n");

}

void empty(slist_t *list) {
    list_item_t* iterator = list->head;
    if (iterator != NULL) {
        iterator->prev->next = NULL;
    }
    while (iterator != NULL) {
        list_item_t* toRemove = iterator;
        iterator = iterator->next;

        free(toRemove->value);
        free(toRemove);
    }
    list->head = NULL;
    list->tail = NULL;
}

void swapItems(list_item_t *item1, list_item_t *item2) {
    list_item_t* before = item1->prev;
    list_item_t* after = item2->next;
    before->next = item2;
    after->prev = item1;
    item1->next = item2->next;
    item2->prev = item1->prev;
    item2->next = item1;
    item1->prev = item2;
}

void bublesort(slist_t *list) {
    list_item_t* current = list->head;

    int count = size(list);

    if (current == NULL) { // No elements
        return;
    }
    else if (count == 1) { // One element
        return;
    }
    else {
        int i,j;
        for(i = 0; i < count; i++) {
            current = list->head;
            for (j = 0; j < count - 1 - i && current->next != list->head; j++) {
                if (strcmp(current->value, current->next->value) > 0) {
                    swapItems(current, current->next);
                    if (current == list->head) {
                        list->head = list->head->prev;
                        list->tail = list->tail->prev;
                    }
                }
                else {
                    current = current->next;
                }
            }
        }
    }
}

int size(slist_t *list) {
    if (list == NULL) {
        perror("Cannot get the size of a null list.");
        return 0;
    }
    list_item_t* iterator = list->head;
    if (iterator == NULL) {
        return 0;
    }
    int count = 1;

    while (iterator->next != NULL && iterator->next != list->head) {
        count++;
        iterator = iterator->next;
    }

    return count;
}
