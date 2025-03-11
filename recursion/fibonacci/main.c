#include <stdio.h>
#include "fibonacci.h"

int main(int argc, char *argv[])
{
    int n;
    while(1) {
        printf("n: ");
        scanf(" %d", &n);
        printf("top-down approach using memoization: fib(n) = %lli\n", recursive_fibonacci(n));
        printf("bottom-up approach: fib(n) = %lli\n", iterative_fibonacci(n));
    }

    return 0;
}
