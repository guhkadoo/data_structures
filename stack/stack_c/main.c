#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    Stack s;
    int size;
    stack_initialize(&s);
    stack_push(s, 10);
    stack_push(s, 20);
    stack_push(s, 30);
    stack_print(s);
    size = stack_size(s);
    printf("size: %d\n", size);

    int n1 = stack_pop(s);
    int n2 = stack_pop(s);
    int n3 = stack_pop(s);
    int n4 = stack_pop(s);

    printf("removed: %d %d %d %d\n", n1, n2, n3, n4);
    size = stack_size(s);
    printf("size: %d\n", size);
    stack_print(s);

    printf("is stack empty? %d\n", stack_empty(s));
    printf("top of the stack: %d\n", stack_top(s));
    

    return 0;
}
