//
// OS homework 1
// V:1.2
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/time.h>

#define MILLIS_PER_SECOND 1000

//toggle USE_ARRAYS define to include the desired version of the set implementation
#define USE_ARRAYS
//#define USE_LIST_OPT

#ifdef USE_ARRAYS
typedef struct {
	int *elements;
	int num_elem;
} set_t;
#else
typedef struct set_elem {
    int elem;
    struct set_elem *next;
} set_elem_t;

typedef struct {
    set_elem_t *head;
    set_elem_t *tail;
    set_elem_t *last_used;
} set_t;

set_elem_t* createSetElem() {
    set_elem_t* result = malloc(sizeof(set_elem_t));
    if (result == NULL) {
        return NULL;
    }

    result->elem = 0;
    result->next = NULL;

    return result;
}
#endif

// creates an empty set whose elements are in [0,N]
void set_init(set_t *a, int N) {
#ifdef USE_ARRAYS
    if (a == NULL || N == 0) return;
    a->num_elem = N;
    a->elements = malloc(sizeof(int) * N);
    memset(a->elements, 0, sizeof(int) * N);
    if (a->elements == NULL) {
        printf("ERROR: Could not allocate space for array data.\n");
        return;
    }
#else
    if (a == NULL || N == 0) return;
    a->head = createSetElem();
    a->tail = a->head;
    a->last_used = NULL;

    for (int i = 1; i < N; i++) {
        a->tail->next = createSetElem();
        a->tail = a->tail->next;
    }
#endif
}

// adds an element tot the set
void set_add_elem(set_t *a, int e) {
#ifdef USE_ARRAYS
    a->elements[e] = 1;
#else
    int i;
    set_elem_t* iterator;
    if (a->last_used != NULL && a->last_used->elem > e) {
        iterator = a->head;
    }
    else {
#ifdef USE_LIST_OPT
        iterator = a->last_used;
#else
        iterator = a->head;
#endif
    }
    for (i = 0; iterator != NULL; i++, iterator = iterator->next) {
        if (i == e) {
            iterator->elem = 1;
            a->last_used = iterator;
            return;
        }
    }
#endif
}

// computes the union of a and b in r
void set_union(set_t *a, set_t *b, set_t *r) {
#ifdef USE_ARRAYS
    for (int i = 0; i < a->num_elem; i++) {
        r->elements[i] = a->elements[i] | b->elements[i];
    }
#else
    set_elem_t* iteratorA;
    set_elem_t* iteratorB;
    set_elem_t* iteratorC;
    for (iteratorA = a->head, iteratorB = b->head, iteratorC = r->head;
            iteratorA->next != NULL;
            iteratorA = iteratorA->next, iteratorB = iteratorB->next, iteratorC = iteratorC->next) {
        iteratorC->elem = iteratorA->elem | iteratorB->elem;
    }
#endif
}
// computes the intersection of a and b in r
void set_intersection(set_t *a, set_t *b, set_t *r) {
#ifdef USE_ARRAYS
    for (int i = 0; i < a->num_elem; i++) {
        r->elements[i] = a->elements[i] & b->elements[i];
    }
#else
    set_elem_t* iteratorA;
    set_elem_t* iteratorB;
    set_elem_t* iteratorC;
    for (iteratorA = a->head, iteratorB = b->head, iteratorC = r->head;
         iteratorA->next != NULL;
         iteratorA = iteratorA->next, iteratorB = iteratorB->next, iteratorC = iteratorC->next) {
        iteratorC->elem = iteratorA->elem & iteratorB->elem;
    }
#endif
}
// checks if the element is part of the set
int set_has_elem(set_t *a, int elem) {
#ifdef USE_ARRAYS
    if (elem >= a->num_elem) return 0;
    return a->elements[elem];
#else
    int i;
    set_elem_t* iterator;
    for (i = 0, iterator = a->head; iterator != NULL && i <= elem; i++, iterator = iterator->next) {
        if (i == elem) {
            return iterator->elem;
        }
    }
    return 0;
#endif
}


int main() {
    int N = 1000;
    set_t a, b, c, r;

    for (N = 100; N < 1000000; N += 2000) {
        int milli = 0;

        // add code to start timing
        struct timeval  startTime;
        struct timeval  endTime;
        long startMillis;
        long endMillis;
        gettimeofday(&startTime, NULL);
        startMillis = startTime.tv_sec * MILLIS_PER_SECOND + startTime.tv_usec / 1000 ;

        set_init(&a, N);
        set_init(&b, N);
        set_init(&c, N)	;
        set_init(&r, N)	;

        for (int i = 0; i < N; i++) if ((i % 2) == 0) set_add_elem(&a, i);
        for (int i = 0; i < N; i++) if ((i % 2) == 1) set_add_elem(&b, i);
        set_union(&a, &b, &a);
        set_intersection(&b, &c, &b);
        for (int i = 0; i < N; i++) if ((i % 2) == 0) set_add_elem(&b, i);
        for (int i = 0; i < N; i++) if ((i % 4) == 0) set_add_elem(&c, i);
        set_intersection(&a, &b, &r);
        set_intersection(&r, &c, &r);

        // add code to stop timing and compute the run-time in milliseconds
        // in variable milli
        //
        gettimeofday(&endTime, NULL);
        endMillis = endTime.tv_sec * MILLIS_PER_SECOND + endTime.tv_usec / 1000 ;
        milli = (int) (endMillis - startMillis);

        printf("%d\t%d\n", N, milli);
    }



    return 0;
}
