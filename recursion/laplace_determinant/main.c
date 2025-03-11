#include "determinant.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    int row,column;
    printf("Rows: ");
    scanf("%d", &row);
    printf("Columns: ");
    scanf("%d", &column);

    int* m = create_matrix(row, column);
    read_matrix(m, row, column);
    print_matrix(m, row, column);

    int det = determinant(m, row, column);
    printf("Det: %d\n", det);

    return 0;
}
