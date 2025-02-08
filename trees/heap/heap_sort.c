#include <stdio.h>
#include <stdlib.h>
#define swap(a,b) if((&a)!=(&b))((a)^=(b)^=(a)^=(b))
// HEAP SORT!
void max_heapify(int *arr, int size, int idx)
{
    int l=2*idx+1, r=2*idx+2;
    int larg=idx;
    if(l < size && arr[l] > arr[larg])
        larg = l;
    if(r < size && arr[r] > arr[larg])
        larg = r;
    if(larg != idx) {
        swap(arr[larg], arr[idx]);
        max_heapify(arr, size, larg);
    }
}

void heap_sort(int *arr, int size)
{
    for(int i=size/2-1; i>=0; i--)
        max_heapify(arr, size, i);

    while(size!=0)
    {
        swap(arr[0], arr[size-1]);
        size--;
        max_heapify(arr, size, 0);
    }
}

int main(int argc, char *argv[])
{
    int size;
    printf("size of the array: ");
    scanf("%d", &size);
    int *arr = (int *)malloc(size*sizeof(int));
    for(int i=0; i<size; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", arr + i);
    }
    heap_sort(arr, size);
    printf("--- SORTED ARRAY ---:\n");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
