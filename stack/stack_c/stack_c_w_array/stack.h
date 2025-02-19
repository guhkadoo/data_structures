#ifndef STACK_H
#define STACK_H

#define INT 1
#define FLOAT 2
#define STRING 3

// ----------------------- STACK ELEMENT DEFINITION ----------------------- 
typedef struct _stack_element* stack_element;
void stack_element_initialize(stack_element*, char type, void*);

// ----------------------- STACK DEFINITION ----------------------- 
typedef struct _stack* stack;
void stack_initialize(stack*);
void print_top(stack);
char empty(stack);
stack_element pop(stack);
void push(stack, stack_element);

#endif //STACK_H
