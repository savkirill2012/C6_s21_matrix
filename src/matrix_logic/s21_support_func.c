#include "../s21_matrix.h"

int is_equal_size_matrix(matrix_t *A, matrix_t *B) {
  int is_equal = 0;

  if (A->columns == B->columns && A->rows == B->rows) {
    is_equal = 1;
  }

  return is_equal;
}

int check_matrix(const matrix_t *A) {
  int error_flag = 1;

  if (!A || A->columns < 1 || A->rows < 1) {
    error_flag = 0;
  }

  return error_flag;
}

int check_is_square_matrix(matrix_t *A) {
  int error_flag = 0;

  if (A->rows == A->columns) {
    error_flag = 1;
  }

  return error_flag;
}