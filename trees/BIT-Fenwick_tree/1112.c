#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#define swap(a,b) ((a)^=(b)^=(a)^=(b))

void updateBIT(int x, int y, int val, int row_size, int column_size, int *BIT)
{
    x += 1; y+=1;
    for(; x <= row_size; x += (x & -x))
    {
            for(int yy = y; yy <= column_size; yy += (yy & -yy))
            BIT[x * column_size + yy] += val;
    }
}

int getSum(int x, int y, int column_size, int *BIT)
{
    x += 1; y += 1;
    int sum = 0;
    for(; x>0; x -= (x&-x))
    {
        for(int yy=y; yy>0; yy -= (yy&-yy))
            sum += BIT[x * column_size + yy]; 
    }

    return sum;
}

int main(int argc, char *argv[])
{
    int x,y,p;
    int *BIT = (int *)calloc(1001001, sizeof(int));
    char c;
    scanf("%d%d%d", &x, &y, &p);
    while(x || y || p)
    {
        int q;
        scanf("%d", &q);
        while(q--)
        {
            scanf(" %c", &c);
            if(c == 'A')
            {
                int val, x1, y1;
                scanf("%d%d%d", &val, &x1, &y1);
                //updateBIT(int x, int y, int val, int row_size, int column_size, int *BIT)
                updateBIT(x1, y1, val, x, y, BIT);
            }
            else if(c == 'P')
            {
                int x1, y1, x2, y2;
                scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
                if(x2 < x1)
                    swap(x1,x2);
                if(y2 < y1)
                    swap(y1,y2);
                //getSum(int x, int y, int column_size, int *BIT)
                int v1 = getSum(x2, y2, y, BIT);
                int v2 = getSum(x2, y1-1, y, BIT);
                int v3 = getSum(x1-1, y2, y, BIT);
                int v4 = getSum(x1-1, y1-1, y, BIT);
                int sum = v1-v2-v3+v4;
                printf("%d\n", sum*p);
            }
        }
        printf("\n");
        memset(BIT, 0, 1001001 * sizeof(int));

        scanf("%d%d%d", &x, &y, &p);
    }

    return 0;
}
