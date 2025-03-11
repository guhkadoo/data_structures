#include "factorial.h"
#include <stdio.h>

long long recursive_factorial(int n)
{
    if(n==1 || n==0)
        return 1;
    return n*recursive_factorial(n-1);
}

long long iterative_factorial(int n)
{
    if(n==1 || n==0) return 1;
    long long ans=1;
    for(int i=n; i>=2; i--)
    {
        ans *= i;
    }
    return ans;
}
