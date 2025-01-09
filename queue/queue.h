#ifndef QUEUE_H
#define QUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Queue
{
    int value;
    struct Queue *next;
};

void insert(struct Queue **queue, int value)
{
    struct Queue *new_node = (struct Queue*)malloc(sizeof(struct Queue));
    if(new_node != NULL)
    {
        new_node->value = value;
        if(*queue == NULL) {
            new_node->next = *queue;
            *queue = new_node;
        } else {
            struct Queue *aux = *queue;
            while(aux->next) {
                aux = aux->next;
            }
            aux->next = new_node;
            new_node->next = NULL;
        }
    } else {
        EXIT_WITH_ERROR("Error while allocating memory...");
    }
}

struct Queue *delete(struct Queue **queue)
{
    struct Queue *rem = *queue;
    if(*queue != NULL) {
        *queue = rem->next;
    }
    return rem;
}

void print_queue(struct Queue *queue)
{
    while(queue) {
        printf("%d\n", queue->value);
        queue = queue->next;
    }
}

#endif //QUEUE_H
