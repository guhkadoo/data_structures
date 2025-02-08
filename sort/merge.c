#include <stdio.h>
#define ARRAY_LENGTH(v) sizeof(v)/sizeof(v[0])

void merge(int v[], int low, int mid, int high)
{
    int n1 = mid-low+1;
    int n2 = high-mid;
    int v1[n1], v2[n2];

    for(int i=0; i<n1; i++)
        v1[i] = v[low+i];
    for(int i=0; i<n2; i++)
        v2[i] = v[mid+1+i];

    int i=0,j=0,k=low;
    while(i<n1 && j<n2)
    {
        if(v1[i] < v2[j])
            v[k++] = v1[i++];
        else
            v[k++] = v2[j++];
    }
    while(i<n1)
        v[k++] = v1[i++];
    while(j<n2)
        v[k++] = v2[j++];
}

void merge_sort(int v[], int low, int high)
{
    if(low < high) {
        int mid = (low+high)/2;
        merge_sort(v, low, mid);
        merge_sort(v, mid+1, high);

        merge(v, low, mid, high);
    }
}

int main(int argc, char *argv[])
{
    int v[] = {9,8,7,6,-1,2};
    int len = ARRAY_LENGTH(v);

    merge_sort(v, 0, len-1);

    for(int i=0; i<len; i++)
        printf("%d ", v[i]);
    printf("\n");

    return 0;
}
