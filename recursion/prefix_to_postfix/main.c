#include "prefix_to_postfix.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
        EXIT_WITH_ERROR("provide at least 1 argument");
    char postfix[MAX_LENGTH];
    for(register size_t i=1; i<argc; i++)
    {
        convert(argv[i], postfix);
        printf("PREFIX: %s      POSTFIX: %s\n", argv[i], postfix);
    }
}
