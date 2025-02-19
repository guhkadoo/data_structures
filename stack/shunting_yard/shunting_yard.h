#ifndef SHUNTING_YARD_H
#define SHUNTING_YARD_H

// ------------------------------- STACK ------------------------------------
typedef struct _stack* stack;

void stack_initialize(stack*);
void stack_push(stack, char);
char stack_pop(stack);
char stack_is_empty(stack);
void stack_print(stack);
char stack_top(stack);
int stack_size(stack);
// --------------------------------------------------------------------------





// --------------------------- SHUNTING YARD --------------------------------
char* shunting_yard(char* infix);
// --------------------------------------------------------------------------

#endif
