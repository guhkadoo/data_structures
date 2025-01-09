#ifndef ARITHMETIC_EXPRESSION_H
#define ARTIHMETIC_EXPRESSION_H

#include <stdio.h>
#include <stdlib.h>

#define EXIT_WITH_ERROR(msg) (fprintf(stderr, "%s\n", msg), exit(1))

struct Stack {
    char character;
    struct Stack *next;
};

struct Stack *pop(struct Stack **stack)
{
    struct Stack *remove = *stack;
    if(*stack != NULL) {
        *stack = remove->next;
    }
    return remove;
}

void push(struct Stack **stack, char c)
{
    struct Stack *new = (struct Stack*)malloc(sizeof(struct Stack));
    if(new != NULL) {
        new->character = c;
        new->next = *stack;
        *stack = new;
    } else {
        EXIT_WITH_ERROR("Error while allocating memory");
    }
}

void print_stack(struct Stack *stack)
{
    printf("[%c, ", stack->character);
    stack = stack->next;
    while(stack->next != NULL) {
        printf("%c, ", stack->character);
        stack = stack->next;
    }
    printf("%c]\n", stack->character);
}

int correct_pair(char in_stack, char not_in_stack)
{
    if(in_stack == '(' && not_in_stack == ')')
        return 1; 
    else if(in_stack == '[' && not_in_stack == ']')
        return 1;
    else if(in_stack == '{' && not_in_stack == '}')
        return 1;
    return 0;
}

int verify_expression(char expression[])
{
    struct Stack *stack = NULL;
    for(int i=0; expression[i] != '\0'; i++) {
        if(expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(&stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            struct Stack *aux = pop(&stack);
            if(correct_pair(aux->character, expression[i]) == 0) {
                printf("Wrong arithmetic expression\n");
                return 0;
            }
            free(aux);
        }
    }
    if(stack == NULL)
        return 1;
    return 0;
}


#endif //ARITHMETIC_EXPRESSION_H
