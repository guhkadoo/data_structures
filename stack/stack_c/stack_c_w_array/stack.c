#include "stack.h"
#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))
#define STACK_SIZE 100
#define STRING_SIZE 50

// ----------------------- STACK ELEMENT DEFINITION ----------------------- 
struct _stack_element 
{
    char etype;
    union
    {
        int ival;
        float fval;
        char *sval;
    } element;
};

void stack_element_initialize(stack_element* se, char type, void* value)
{
    (*se) = (stack_element)malloc(sizeof(struct _stack_element));
    (*se)->etype = type; 
    switch(type)
    {
        case INT: (*se)->element.ival = *(int*)value; break;
        case FLOAT: (*se)->element.fval = *(float*)value; break;
        case STRING: 
            (*se)->element.sval = (char *)malloc(STRING_SIZE); 
            (*se)->element.sval = *(char**)value; break;
    }
}


// ----------------------- STACK DEFINITION ----------------------- 
struct _stack
{
    char top;
    struct _stack_element items[STACK_SIZE];
};

void stack_initialize(stack* s)
{
    (*s) = (stack)malloc(sizeof(struct _stack));
    (*s)->top = -1;
}

void print_top(stack s)
{
    struct _stack_element se = s->items[s->top];
    switch(se.etype)
    {
        case INT: printf("%d\n", se.element.ival); break;
        case FLOAT: printf("%f\n", se.element.fval); break;
        case STRING: printf("%s\n", se.element.sval); break;
    }
}

char empty(stack s)
{
    return (s->top == -1);
}

stack_element pop(stack s)
{
    if(empty(s))
        EXIT_WITH_ERROR("stack underflow");
    return &s->items[s->top--];
}

void push(stack s, stack_element se)
{
    if(s->top == STACK_SIZE-1)
        EXIT_WITH_ERROR("stack overflow");
    s->items[++(s->top)] = *se;
}
