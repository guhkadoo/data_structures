#ifndef STACK_H
#define STACK_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Stack 
{
    float value;
    struct Stack *next;
};


void push(struct Stack **stack, float value)
{
    struct Stack *new_node = (struct Stack*)malloc(sizeof(struct Stack));
    if(new_node) {
        new_node->value = value;
        new_node->next = *stack;
        *stack = new_node;
    } else {
        EXIT_WITH_ERROR("Error while allocating memory\n");
    }
}

struct Stack *pop(struct Stack **stack)
{
    struct Stack *remove = *stack;
    if(remove != NULL) {
        *stack = remove->next;
    }
    return remove;
}

void print_stack(struct Stack *stack)
{
    while(stack != NULL) {
        printf("%.3f, ", stack->value);
        stack = stack->next;
    }
    printf("\n");
}

#endif //STACK_H
