#ifndef STACK_H
#define STACK_H

typedef struct __stack__* Stack;

void stack_initialize(Stack*);
void stack_push(Stack, char);
int stack_pop(Stack);
int stack_empty(Stack);
int stack_top(Stack);
int stack_size(Stack);
void stack_print(Stack);

#endif //STACK_H
