#include <stdio.h>
// I'm gonna make a matrix using an array (single memory block) -> M[i][j] = A[i*column_size+j]

void update(int node, int b_row, int e_row, int b_column, int e_column, int x, int y, int column_size, int *ST)
{
    if(b_row == e_row)
        finalUpdate();
    else
    {
        int mid = (b_row+e_row)/2;
        if(b_row <= x && x <= mid)
            update(2*node, b_row, mid, b_column, e_column, x, y, column_size, ST);
        else
            update(2*node+1, mid+1, e_row, b_column, e_column, x, y, column_size, ST);
        for(int i=1; i<column_size; i++)
            ST[node*column_size+i] = ST[2*node*column_size+i] + ST[2*node*column_size+1+i];
    }
}

int main(int argc, char *argv[])
{

    return 0;
}
