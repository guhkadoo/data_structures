#ifndef DETERMINANT_H
#define DETERMINANT_H

int* create_matrix(int row, int column);
int print_matrix(int* m, int row, int column);
void read_matrix(int* m, int row, int column);
int determinant(int* m, int row, int column);

#endif //DETERMINANT_H
