#include "list.h"

int main(int argc, char *argv[])
{
    struct Node *my_list = NULL;
    append(&my_list, 1);
    append(&my_list, 2);
    append(&my_list, 4);
    append(&my_list, 5);
    print_list(my_list);

    sort_insert(&my_list, 3);
    sort_insert(&my_list, -10);
    sort_insert(&my_list, 1203);
    sort_insert(&my_list, 1000);
    print_list(my_list);
    remove_node(&my_list, -10);
    remove_node(&my_list, 2);
    remove_node(&my_list, 0);
    print_list(my_list);


    return 0;
}
