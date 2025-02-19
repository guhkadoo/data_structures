#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Node
{
    char value;
    struct Node *next;
};

struct __stack__
{
    struct Node *top;
    int size;
};

struct Node *create_node(char n)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node)
    {
        new_node->next = NULL;
        new_node->value = n;
    } else {
        EXIT_WITH_ERROR("Error while allocating new node");
    }
    return new_node;
}

void stack_initialize(Stack *s)
{
    *s = (Stack)malloc(sizeof(struct __stack__));
    if(*s != NULL)
    {
        (*s)->top = NULL;
        (*s)->size = 0;
    } else {
        EXIT_WITH_ERROR("Error while initializing stack");
    }
}

void stack_push(Stack s, char n)
{
    if(s->top == NULL)
    {
        s->top = create_node(n);
    } else {
        struct Node *new_node = create_node(n);
        new_node->next = s->top;
        s->top = new_node;
    }
    s->size++;
}

int stack_pop(Stack s)
{
    struct Node *remove = s->top;
    if(remove != NULL)
    {
        s->top = remove->next;
        int aux = remove->value;
        free(remove);
        s->size--;
        return aux;
    }
    return INT_MIN;
}

int stack_empty(Stack s)
{
    if(s->size == 0)
        return 1;
    return 0;
}

int stack_top(Stack s)
{
    if(s->top != NULL)
        return s->top->value;
    return INT_MIN;
}

int stack_size(Stack s)
{
    return s->size;
}

void stack_print(Stack s)
{
    struct Node *aux = s->top;
    if(aux != NULL)
    {
        printf("[%c", aux->value);
        aux = aux->next;
        while(aux != NULL && aux->next != NULL)
        {
            printf(" -> %c", aux->value);
            aux = aux->next;
        }
        if(aux != NULL)
            printf(" -> %c]\n", aux->value);
        else
            printf("]\n");
    }
}
