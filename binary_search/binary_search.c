#include "binary_search.h"

int binary_search(int v[], int low, int high, int n)
{
    int mid = (low+high)/2;
    if(n < v[mid])
        return binary_search(v, low, mid-1, n);
    else if(n > v[mid])
        return binary_search(v, mid+1, high, n);
    return mid;
}
