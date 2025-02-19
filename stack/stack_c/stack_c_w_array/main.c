#include "stack.h"

int main(int argc, char *argv[])
{
    stack s;
    stack_initialize(&s);

    stack_element se;
    int i_temp = 5;
    stack_element_initialize(&se, INT, &i_temp);

    push(s, se);

    char *s_temp = "oi";
    stack_element_initialize(&se, STRING, &s_temp);
    push(s, se);
    print_top(s);

    return 0;
}
