#include "list.c"
#include "list.h"

int main(int argc, char const *argv[]) {
    int_list list = list_init();

    list_push_front(&list, 1);
    list_push_front(&list, 20);
    list_push_front(&list, 3);
    // list_push_back(&list, 1);
    // list_push_back(&list, 2);
    // list_pop_back(&list);
    // list_pop_front(&list);
    // list_push_back(&list, 3);
    // list_pop_front(&list);

    print_list(&list);
    list_free(&list);

    return 0;
}
