#include <stdio.h>
#include <string.h>
#define MAX 1000
typedef long long ll;

ll memo[MAX];

ll fibonacci(int n) //top-down approach using memoization
{
    if(n==0 || n==1)
        return 1;
    if(memo[n])
        return memo[n];
    memo[n] = fibonacci(n-1)+fibonacci(n-2);
    return memo[n];
}

ll fib(int n)
{
    ll l1, l2, curr;
    l1=l2=1;
    for(int i=2; i<=n; i++)
    {
        curr = l1+l2;
        l2 = l1;
        l1 = curr;
    }
    return curr;
}

int main(int argc, char *argv[])
{
    memset(memo, 0, MAX*sizeof(ll));
    int n;
    while(1) {
        printf("n: ");
        scanf(" %d", &n);
        printf("top-down approach using memoization: fib(n) = %lli\n", fibonacci(n));
        printf("bottom-up approach: fib(n) = %lli\n", fib(n));
    }

    return 0;
}
