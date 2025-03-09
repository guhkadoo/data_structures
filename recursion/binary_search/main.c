#include "binary_search.h"
#include <stdio.h>

int main(int argc, char *argv[])
{
    int v[] = {-9,-8,-7,-6,-5,-4,-3,-2,-1,0,1,2,3,4,5,6,7,8,9,10,11,12,13};
    int len = ARRAY_SIZE(v);
    int i = binary_search(v, 0, len-1, -5);
    printf("i: %d      v[i]: %d\n", i, v[i]);
}
