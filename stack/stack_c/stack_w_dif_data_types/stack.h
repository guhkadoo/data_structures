#ifndef STACK_H
#define STACK_H

#define CHAR 1
#define INT 2
#define FLOAT 3
#define DOUBLE 4
#define STRING 5

typedef struct __stack_element__* Stack_element;
typedef struct __stack__* Stack;

void stack_element_initialize(Stack_element*, char, void*);
void stack_initialize(Stack*);
void stack_push(Stack, Stack_element);
Stack_element stack_pop(Stack);
int stack_empty(Stack);
Stack_element stack_top(Stack);
int stack_size(Stack);
void stack_print(Stack);

#endif //STACK_H
