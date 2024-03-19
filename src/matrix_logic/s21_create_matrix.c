#include "../s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t* result) {
  int error_flag = 0;
  double** tmp_matrix = (double**)malloc((sizeof(double) * columns * rows) +
                                         sizeof(double*) * rows);
  double* ptr = (double*)(tmp_matrix + rows);

  if (tmp_matrix != NULL) {
    for (int i = 0; i < rows; i++) {
      tmp_matrix[i] = ptr + (i * columns);
    }

    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        tmp_matrix[i][j] = 0;
      }
    }

    result->matrix = tmp_matrix;
    result->columns = columns;
    result->rows = rows;
  } else {
    error_flag = 1;
  }

  return error_flag;
}