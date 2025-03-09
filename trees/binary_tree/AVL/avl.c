#include "avl.h"

int main(int argc, char *argv[])
{
    int option, value;
    struct Node *avl = NULL;

    do {
        printf("\t\t0:quit -- 1:insert -- 2:remove -- 3:print_avl\n\n");
        scanf("%d", &option);
        switch(option) {
            case 0: break;
            case 1: 
                printf("value: ");
                scanf("%d", &value);
                avl = insert(avl, value);
                break;
            case 2:
                printf("value: ");
                scanf("%d", &value);
                avl = remove_node(avl, value);
                break;
            case 3:
                print_avl(avl, 1);
        }
    } while(option != 0);

    return 0;
}
