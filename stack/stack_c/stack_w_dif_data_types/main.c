#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
    Stack s;
    stack_initialize(&s);

    Stack_element se;

    float i=1.2;
    stack_element_initialize(&se, FLOAT, &i);
    stack_push(s, se);

    char *j="this is a string";
    stack_element_initialize(&se, STRING, &j);
    stack_push(s, se);

    int k=10;
    stack_element_initialize(&se, INT, &k);
    stack_push(s, se);

    stack_print(s);

    return 0;
}
