// version 1.1
// -- added support for initializing the list

typedef struct list_item {
	char *value;
	struct list_item *next;
	struct list_item *prev;
} list_item_t; 

/**
global variable declaration
**/
typedef struct single_list {
	list_item_t *head;
	list_item_t *tail;
} slist_t;

void init(slist_t *list);
void add(slist_t *list, char *value, int position);
void print(slist_t *list);
void empty(slist_t *list);
void bublesort(slist_t *list);
int size(slist_t* list);