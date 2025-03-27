#include "towers.h"
#include <stdio.h>

static int str_to_int(char* str);

int main(size_t argc, char* argv[])
{
    if(argc < 2)
        EXIT_WITH_ERROR("provide at least 1 argument");
    for(register size_t i=1; i<argc; i++)
    {

        towers(str_to_int(argv[i]), 'A', 'C', 'B');
        printf("\n");
    }
}

static int str_to_int(char* str)
{
    int ans=0;
    for(register size_t i=0; str[i]!='\0'; i++)
        ans += ans*10 + (str[i] - '0');
    return ans;
}
