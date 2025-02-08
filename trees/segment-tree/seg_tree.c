#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE(v) (sizeof(v)/sizeof(v[0]))

void build_ST(int node, int low, int high, int A[], int ST[])
{
    if(low == high)
        ST[node] = A[low];
    else {
        int mid = (low+high)/2;
        build_ST(2*node, low, mid, A, ST);
        build_ST(2*node+1, mid+1, high, A, ST);
        ST[node] = ST[2*node]+ST[2*node+1];
    }
}

void update_ST(int node, int low, int high, int idx, int value, int A[], int ST[])
{
    if(low == high) {
        ST[node] = value;
        A[idx] = value;
    } else {
        int mid = (low+high)/2;
        if(low<=idx && idx<=mid)
            update_ST(2*node, low, mid, idx, value, A, ST);
        else
            update_ST(2*node+1, mid+1, high, idx, value, A, ST);
        ST[node] = ST[node*2] + ST[node*2+1];
    }
}

int query_ST(int node, int tl, int tr, int l, int r, int A[], int ST[])
{
    if(l>tr || r<tl)
        return 0;
    if(l<=tl && r>=tr)
        return ST[node];
    int mid = (tr+tl)/2;

    return query_ST(node*2, tl, mid, l, r, A, ST) + query_ST(node*2+1, mid+1, tr, l, r, A, ST);
}

int main(int argc, char *argv[])
{
    int n;
    printf("Size of the array: ");
    scanf("%d", &n);

    int A[n];
    for(int i=0; i<n; i++) {
        printf("A[%d] = ", i);
        scanf("%d", &A[i]);
    }
    
    int ST[(int)pow(2, ceil(log(n)/log(2))+1)];
    build_ST(1, 0, n-1, A, ST);

    char c;
    do {
        printf("If you wanna update the array or do the sum of a given range write down A or B respectively: ");
        scanf(" %c", &c);
        if(c == 'A') {
            int pos, value;
            printf("Write down the array's position you wanna change: ");
            scanf("%d", &pos);
            printf("New value: ");
            scanf("%d", &value);
            update_ST(1, 0, n-1, pos, value, A, ST);
            printf("Segment tree updated!\n");
        } else if(c == 'B') {
            int a, b;
            printf("Range from ");
            scanf("%d", &a);
            printf("to ");
            scanf("%d", &b);
            int ans = query_ST(1, 0, n-1, a, b, A, ST);
            printf("Answer of the sum is: %d\n", ans);
        }
    } while(c != '0');


    return 0;
}
