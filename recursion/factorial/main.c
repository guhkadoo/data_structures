#include <stdio.h>
#include "factorial.h"

int main(int argc, char *argv[])
{
    while(1) {
        int n;
        printf("Write n: ");
        scanf("%d", &n);
        printf("\n(recursive) n! =  %d", recursive_factorial(n));
        printf("\n(iterative) n! =  %d\n", iterative_factorial(n));
    }

    return 0;
}
