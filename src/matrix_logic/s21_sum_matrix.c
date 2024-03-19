#include "../s21_matrix.h"

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_flag = 0;

  if (check_matrix(A) == 0 || check_matrix(B) == 0) {
    error_flag = 1;
  }

  if (error_flag == 0) {
    if (is_equal_size_matrix(A, B)) {
      if (s21_create_matrix(A->rows, A->columns, result) == 0) {
        for (int i = 0; i < A->rows; i++) {
          for (int j = 0; j < A->columns; j++) {
            result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
          }
        }
      } else {
        error_flag = 1;
      }
    } else {
      error_flag = 2;
    }
  }

  return error_flag;
}