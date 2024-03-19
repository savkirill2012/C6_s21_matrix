#include "../s21_matrix.h"

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int error_flag = 1;

  if (is_equal_size_matrix(A, B)) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        if (A->matrix[i][j] - B->matrix[i][j] > 1e-7) {
          error_flag = 0;
          break;
        }
      }
    }
  } else {
    error_flag = 0;
  }

  return error_flag;
}