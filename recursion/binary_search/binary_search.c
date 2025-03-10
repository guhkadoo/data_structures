#include "binary_search.h"

int binary_search(int v[], int low, int high, int n)
{
    if(low>high)
        return -1;
    int mid = (low+high)/2;
    return (n == v[mid] ? mid : n < v[mid] ?
                                            binary_search(v, low, mid-1, n) :
                                            binary_search(v, mid+1, high, n));
}
