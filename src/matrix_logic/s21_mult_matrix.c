#include "../s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int error_flag = 0;
  int loc_column = 0;

  if (check_matrix(A) && check_matrix(B)) {
    if (A->columns == B->rows) {
      if (s21_create_matrix(A->rows, B->columns, result) == 0) {
        while (loc_column < A->columns) {
          for (int i = 0; i < A->rows; i++) {
            for (int j = 0; j < B->columns; j++) {
              result->matrix[i][j] +=
                  A->matrix[i][loc_column] * B->matrix[loc_column][j];
            }
          }
          loc_column++;
        }
      } else {
        error_flag = 1;
      }
    } else {
      error_flag = 2;
    }
  } else {
    error_flag = 1;
  }

  return error_flag;
}