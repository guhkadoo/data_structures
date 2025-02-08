#include <stdio.h>
#define ARRAY_SIZE(v) sizeof(v)/sizeof(v[0])

void swap(int *a, int *b) { if(a!=b) { (*a^=*b), (*b^=*a), (*a^=*b); }; }

int lomuto(int v[], int low, int high)
{
    int *pivot = &v[high];
    int boundary = low;
    for(int i=low; i<high; i++) {
        if(v[i] <= *pivot)
            swap(&v[i], &v[boundary++]);
    }
    swap(pivot, &v[boundary]);

    return boundary;
}

int hoare(int v[], int low, int high)
{
    int i=low-1, j=high+1;
    int pivot = v[low];
    while(1) {
        do {
            i++;
        } while(v[i] < pivot);
        do {
            j--;
        } while(v[j] > pivot);
        if(i>=j)
            return j;
        swap(&v[i], &v[j]);
    }
}

void quick_sort(int v[], int low, int high)
{
    if(low < high) {
        int boundary = hoare(v, low, high);
        quick_sort(v, low, boundary);
        quick_sort(v, boundary+1, high);
    }
}

int main(int argc, char *argv[])
{
    int v[] = {9,8,7,6,5,-1,2,3,4};
    quick_sort(v, 0, ARRAY_SIZE(v)-1);

    for(int i=0; i<ARRAY_SIZE(v); i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
