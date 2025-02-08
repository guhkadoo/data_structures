#include <stdio.h>
#include <stdlib.h>
int n;
int *t;

void build()
{
    for(int i=n-1; i>0; i--) t[i] = t[i<<1] + t[i<<1|1];
}

void modify(int p, int value)
{
    for(t[p += n] = value; p>1; p >>= 1) t[p>>1] = t[p] + t[p^1];
}

int query(int l, int r)
{
    int res = 0;
    for(l += n, r += n; l<r; l >>= 1, r >>= 1)
    {
        if(l&1) res += t[l++];
        if(r&1) res += t[--r];
    }
    return res;
}

int main(int argc, char *argv[])
{
    scanf("%d", &n);
    t = (int *)malloc(2*n*sizeof(int));
    for(int i=0; i<n; i++) scanf("%d", t+n+i);
    build();
    printf("%d\n", query(4,9));

    return 0;
}
