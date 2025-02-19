#include <stdio.h>
#include "shunting_yard.h"

int main(int argc, char *argv[])
{
    char infix[50];
    while(1)
    {
        printf("infix: ");
        scanf(" %49[^\n]", infix);
        char *ans = shunting_yard(infix);
        printf("%s\n", ans);
    }


    return 0;
}
