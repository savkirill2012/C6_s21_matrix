#include "../s21_matrix.h"

int s21_transpose(matrix_t *A, matrix_t *result) {
  int error_flag = 0;

  if (check_matrix(A) && s21_create_matrix(A->columns, A->rows, result) == 0) {
    for (int i = 0; i < A->columns; i++) {
      for (int j = 0; j < A->rows; j++) {
        result->matrix[i][j] = A->matrix[j][i];
      }
    }
  } else {
    error_flag = 1;
  }

  return error_flag;
}