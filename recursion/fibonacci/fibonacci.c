#include "fibonacci.h"
#include <stdio.h>
#define MAX 1000

long long recursive_fibonacci(int n) //top-down approach using memoization
{
    static long long memo[MAX] = {0};
    if(n==0 || n==1)
        return 1;
    if(memo[n])
        return memo[n];
    memo[n] = recursive_fibonacci(n-1)+recursive_fibonacci(n-2);
    return memo[n];
}

long long iterative_fibonacci(int n)
{
    long long l1, l2, curr;
    l1=l2=1;
    for(int i=2; i<=n; i++)
    {
        curr = l1+l2;
        l2 = l1;
        l1 = curr;
    }
    return curr;
}
