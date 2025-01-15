#include <stdio.h>

struct coord
{
    int i, j;
};

struct coord find_2d_peak(int matrix[][3], int row, int low, int high)
{
    struct coord c;
    int j = (high+low)/2;

    int i, max = matrix[0][j];
    c.i = 0; c.j = j;
    for(i=1; i<=row; i++) {
        if(matrix[i][j] > max) {
            max = matrix[i][j];
            c.i = i; c.j = j;
        }
    }
    if(matrix[c.i][c.j-1] > max) {
        return find_2d_peak(matrix, row, 0, j-1);
    } else if(matrix[c.i][c.j+1] > max) {
        return find_2d_peak(matrix, row, j+1, high);
    }

    return c;
}

int peak_find(int v[], int low, int high)
{
    int m = (low+high)/2;
    if(v[m+1] > v[m])
        return peak_find(v, m+1, high);
    else if(v[m-1] > v[m])
        return peak_find(v, low, m-1);

    return m;
}

int main(int argc, char *argv[])
{
    int matrix[][3] = { 
        {15, 9, -1},
        {8, 8 , 11},
        {10, 9, 8},
        {16, 0, 20}
    };

    int rows = sizeof(matrix)/sizeof(matrix[0]) - 1;
    int columns = sizeof(matrix[0])/sizeof(matrix[0][0]) - 1;

    struct coord c = find_2d_peak(matrix, rows, 0, columns);
    printf("2d peak is %d\n", matrix[c.i][c.j]);

    int v[] = {1,2,6,3,7,6,4,3};
    int length = sizeof(v)/sizeof(v[0]) - 1;

    int peak_1d = peak_find(v, 0, length);
    printf("1d peak is %d\n", v[peak_1d]);
}
