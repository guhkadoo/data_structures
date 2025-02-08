#include <stdio.h>
#define ARRAY_SIZE(v) sizeof(v)/sizeof(v[0])

static inline void swap(int *a, int *b) { if(a!=b) { (*a^=*b), (*b^=*a), (*a^=*b); } }

void insertion_sort(int v[], int len)
{
    register int i, j;
    for(i=1; i<len; i++)
    {
        int key = v[i];
        for(j=i-1; j>=0 && v[j]>key; j--)
            v[j+1] = v[j];
        swap(&v[j+1], &key);
    }
}

int main(int argc, char *argv[])
{
    int v[] = {1,7,6,5,-4,3,-1,2,9,0};
    int len = ARRAY_SIZE(v);
    insertion_sort(v, len);
    for(register int i=0; i<len; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
