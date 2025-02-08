#include <bits/stdc++.h>
#define ARRAY_SIZE(v) ((sizeof(v))/(sizeof(v[0])))

using namespace std;

int getSum(int BITree[], int idx)
{
    int sum = 0;
    idx += 1;
    while(idx > 0)
    {
        sum += BITree[idx];
        idx -= idx & (-idx);
    }

    return sum;
}

void updateBIT(int BITree[], int n, int idx, int val)
{
    idx += 1; // index in BITree[] is 1 more than index in v[]
    while(idx <= n)
    {
        BITree[idx] += val;
        idx += idx & (-idx);
    }
}

int *constructBITree(int v[], int n)
{
    int *BITree = new int[n+1]();

    for(int i=0; i<n; i++)
        updateBIT(BITree, n, i, v[i]);

    return BITree;
}

int main(int argc, char *argv[])
{
    int array[] = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = ARRAY_SIZE(array);
    
    int *BITree = constructBITree(array, size);
    printf("Sum of elements in arr[0..5] is %d\n", getSum(BITree, 5));

}
