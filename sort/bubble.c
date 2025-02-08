#include <stdio.h>
#define ARRAY_SIZE(v) sizeof(v)/sizeof(v[0])

void swap(int *a, int *b) { if(a!=b) { (*a^=*b), (*b^=*a), (*a^=*b); } }

void bubble_sort(int v[], int length)
{
    register int i, j;
    for(i=0; i<length-1; i++)
    {
        int is_sorted = 1;
        for(j=0; j<length-i-1; j++)
        {
            if(v[j+1] < v[j])
            {
                swap(&v[j+1], &v[j]);
                is_sorted = 0;
            }
        }
        if(is_sorted)
            break;
    }
}

int main(int argc, char *argv[])
{
    int v[] = {9,8,7,6,5,4,3,2,1};
    int len = ARRAY_SIZE(v);
    bubble_sort(v, len); 
    for(register int i=0; i<len; i++)
        printf("%d ", v[i]);
    printf("\n");

}
