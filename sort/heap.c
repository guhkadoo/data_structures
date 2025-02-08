#include <stdio.h>
#define ARRAY_SIZE(v) sizeof(v)/sizeof(v[0])

void swap(int *a, int *b) { if(a!=b) {(*a^=*b), (*b^=*a), (*a^=*b);} }

void max_heapify(int v[], int n, int i)
{
    int l = 2*i+1;
    int r = 2*i+2;
    int larg = i;
    if(l < n && v[l] > v[larg])
        larg = l;
    if(r < n && v[r] > v[larg])
        larg = r;
    if(larg != i) {
        swap(&v[larg], &v[i]);
        max_heapify(v, n, larg);
    }
}

void heap_sort(int v[], int n)
{
    for(int i=n/2-1; i>=0; i--)
        max_heapify(v, n, i);
    
    n--;
    while(n) {
        swap(&v[0], &v[n--]);
        max_heapify(v, n, 0);
    }
}


int main(int argc, char *argv[])
{
    int v[] = {9,8,7,6,5,-2,3,-4,100,4,0,-1,-3};
    int len = ARRAY_SIZE(v);

    heap_sort(v, len);

    for(int i=0; i<len; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
