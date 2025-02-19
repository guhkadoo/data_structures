#include <stdio.h>
#include <stdbool.h>
#include "stack.h"

int match(char c1, char c2)
{
    if(c1 == '(' && c2 == ')')
        return 1;
    else if(c1 == '[' && c2 == ']')
        return 1;
    else if(c1 == '{' && c2 == '}')
        return 1;
    return 0;
}

int main(int argc, char *argv[])
{
    char expression[101];
    bool valid = true;
    Stack s;
    stack_initialize(&s);

    scanf(" %100[^\n]", expression);
    for(register int i=0; expression[i]!='\0'; i++)
    {
        if(expression[i]=='(' || expression[i]=='[' || expression[i]=='{')
            stack_push(s, expression[i]);
        else if(expression[i]==')' || expression[i]==']' || expression[i]=='}')
        {
            if(stack_empty(s))
                valid = false;
            else if(!match(stack_pop(s), expression[i]))
                valid = false;
        }
        if(!valid)
            break;
    }
    if(!stack_empty(s))
        valid = false;
    if(valid)
        printf("Valid expression\n");
    else
        printf("Invalid expression\n");



    return 0;
}
