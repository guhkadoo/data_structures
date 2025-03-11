#include "determinant.h"
#include <stdio.h>
#include <stdlib.h>

static inline int idx(int i, int j, int column) { return i*column + j; }

int* create_matrix(int row, int column)
{
    return (int*)malloc(row*column*sizeof(int));
}

int print_matrix(int* m, int row, int column)
{
    register int i, j;
    for(i=0; i<row; i++)
    {
        for(j=0; j<column; j++)
            printf("%d ", m[idx(i,j,column)]);
        printf("\n");
    }
}

void read_matrix(int* m, int row, int column)
{
    register int i;
    for(i=0; i<row*column; i++)
        scanf("%d", &m[i]);
}

int determinant(int* m, int row, int column)
{ 
    if(row == 1 && column == 1)
        return m[0];

    int* minor_m = (int*)malloc((row-1)*(column-1)*sizeof(int)); 
    int sum = 0, n=1;
    for(int j=0; j<column; j++)
    {
        for(int i=0; i<row-1; i++)
        {
            for(int k=0; k<column-1; k++)
            {
                if(k>=j)
                    minor_m[idx(i, k, column-1)] = m[idx(i+1, k+1, column)];
                else
                    minor_m[idx(i, k, column-1)] = m[idx(i+1, k, column)];
            }
        }
        //print_matrix(minor_m, row-1, column-1);
        sum += n * m[j] * determinant(minor_m, row-1, column-1); 
        n = -n;
    }
    free(minor_m);
    return sum;
}
