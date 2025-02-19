#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct __stack_element__ 
{
    char etype;
    union
    {
        char cval;
        int dval;
        float fval;
        double lfval;
        char *sval;
    } element;
};

void stack_element_initialize(Stack_element *se, char type, void *value)
{
    *se = (Stack_element)malloc(sizeof(struct __stack_element__));
    if(*se != NULL)
    {
        (*se)->etype = type; 
        switch(type)
        {
            case CHAR:
                (*se)->element.cval = *(char*)value;
                break;
            case INT:
                (*se)->element.dval = *(int*)value;
                break;
            case FLOAT:
                (*se)->element.fval = *(float*)value;
                break;
            case DOUBLE:
                (*se)->element.lfval = *(double*)value;
                break;
            case STRING:
                (*se)->element.sval = (char*)malloc(30*sizeof(char));
                strcpy((*se)->element.sval, *(char**)value);
                break;
            default:
                EXIT_WITH_ERROR("Unknown stack_element type");
        }
    } else {
        EXIT_WITH_ERROR("Error while initializing stack_element");
    }
}

void stack_element_print(Stack_element se)
{
    switch(se->etype)
    {
        case CHAR:
            printf("%c", se->element.cval);
            break;
        case INT:
            printf("%d", se->element.dval);
            break;
        case FLOAT:
            printf("%f", se->element.fval);
            break;
        case DOUBLE:
            printf("%lf", se->element.lfval);
            break;
        case STRING:
            printf("%s", se->element.sval);
            break;
        default:
            EXIT_WITH_ERROR("Unknown stack_element type");
    }
}

struct Node
{
    struct __stack_element__ value;
    struct Node *next;
};

struct __stack__
{
    struct Node *top;
    int size;
};

struct Node *create_node(Stack_element n)
{
    struct Node *new_node = (struct Node*)malloc(sizeof(struct Node));
    if(new_node)
    {
        new_node->next = NULL;
        new_node->value = *n;
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

void stack_push(Stack s, Stack_element n)
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

Stack_element stack_pop(Stack s)
{
    struct Node *remove = s->top;
    if(remove != NULL)
    {
        s->top = remove->next;
        Stack_element aux = &remove->value;
        free(remove);
        s->size--;
        return aux;
    }
    return NULL;
}

int stack_empty(Stack s)
{
    if(s->size == 0)
        return 1;
    return 0;
}

Stack_element stack_top(Stack s)
{
    if(s->top != NULL)
    {
        Stack_element se = &s->top->value;
        return se;
    }
    return NULL;
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
        printf("[");
        stack_element_print(&aux->value);
        aux = aux->next;
        while(aux != NULL && aux->next != NULL)
        {
            printf(" -> ");
            stack_element_print(&aux->value);
            aux = aux->next;
        }
        if(aux != NULL)
        {
            printf(" -> ");
            stack_element_print(&aux->value);
            printf("]\n");
        }
        else
            printf("]\n");
    }
}
