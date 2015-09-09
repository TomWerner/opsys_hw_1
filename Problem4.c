//
// Created by twrner on 8/31/15.
//

#include "list.h"

int main() {
    slist_t list_;
    slist_t* list = &list_;

    init(list);
    add(list, "Hi");
    add(list, "my");
    add(list, "name");
    add(list, "is");
    add(list, "Tom");
    add(list, "Werner");
    add(list, ".ff");

    print(list);

    return 0;
}