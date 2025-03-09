#ifndef LIST_H
#define LIST_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Node
{
    int value;
    struct Node *next;
};

void append(struct Node **list, int value)
{
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    if(new) {
        new->value = value;
        new->next = NULL;
        if(*list == NULL) {
            *list = new;
        } else {
            struct Node *aux = *list;
            while(aux->next != NULL) {
                aux = aux->next;
            }
            aux->next = new;
        }
    } else {
        EXIT_WITH_ERROR("Error while allocating memory...");
    }
}


void insert(struct Node **list, int index, int value)
{
    int current_pos = 0;
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    struct Node *aux = *list;

    if(new) {
        new->value = value;
        if(index == 0) {
            new->next = *list;
            *list = new;
        } else {
            while(current_pos != index-1 && aux->next != NULL) {
                aux = aux->next; 
                current_pos += 1;
            }
            new->next = aux->next;
            aux->next = new;
        }
    } else {
        EXIT_WITH_ERROR("Error while allocating memory...");
    }
}

void print_list(struct Node *list)
{
    printf("[%d, ", list->value);
    list = list->next;
    while(list->next != NULL) {
        printf("%d, ", list->value);
        list = list->next;
    }
    printf("%d]\n", list->value);
}

void sort_insert(struct Node **list, int value)
{
    struct Node *aux = *list;
    struct Node *new = (struct Node*)malloc(sizeof(struct Node));
    
    if(new) {
        new->value = value;
        if(value <= aux->value) {
            new->next = *list;
            *list = new;
        } else {
            while(aux->next != NULL && value > aux->next->value) {
                aux = aux->next;
            }
            new->next = aux->next;
            aux->next = new;
        }
    } else {
        EXIT_WITH_ERROR("Error while allocating memory...");
    }
}

struct Node* remove_node(struct Node **list, int value)
{
    struct Node *aux = *list, *remove = NULL;
    if(*list) { // if there are elements in the list
        if(value == aux->value) {    //removes the first element
            remove = *list;
            *list = aux->next;
        } else {
            while(aux->next && aux->next->value != value) {
                aux = aux->next;
            }
            if(aux->next) {
                remove = aux->next;
                aux->next = remove->next;
            }                   
        }
    }
    return remove;
}

#endif //LIST_H
