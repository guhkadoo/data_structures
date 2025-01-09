#include "queue.h"

int main(int argc, char *argv[])
{
    
    struct Queue *queue = NULL;
    insert(&queue, 1);
    insert(&queue, 2);
    insert(&queue, 3);
    print_queue(queue);
    free(delete(&queue));
    printf("\n");
    print_queue(queue);

    return 0;
}
