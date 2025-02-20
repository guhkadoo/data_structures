#include <stdio.h>
#include <string.h>

void naive(char *T, char *P)
{
    for(int i=0; i<=strlen(T)-strlen(P); i++)
    {
        char is_substr=1;
        for(int j=0; j<strlen(P); j++)
        {
            if(T[j+i] != P[j])
            {
                is_substr=0;
                break;
            }
        }
        if(is_substr)
            printf("Pattern found at index %d\n", i);
    }
}

int main(int argc, char *argv[])
{
    char T[50], P[30];
    while(1)
    {
        printf("T: ");
        scanf(" %49[^\n]", T);
        printf("P: ");
        scanf(" %29[^\n]", P);
        naive(T, P);
    }

    return 0;
}
