#include "../s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int error_falg = 0;

  if (check_matrix(A)) {
    if (check_is_square_matrix(A)) {
      s21_create_matrix(A->rows, A->columns, result);
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      for (int i = 0; i < A->rows; i++) {
        for (int j = 0; j < A->columns; j++) {
          double determinant;
          int minor_row = 0;
          int minor_column = 0;

          for (int row = 0; row < A->rows; row++) {
            for (int column = 0; column < A->rows; column++) {
              if (!(row == i || column == j)) {
                minor.matrix[minor_row][minor_column] = A->matrix[row][column];
                minor_column++;
                if (minor_column == A->columns - 1) {
                  minor_column = 0;
                  minor_row++;
                }
              }
            }
          }

          s21_determinant(&minor, &determinant);
          result->matrix[i][j] = pow(-1, i + j) * determinant;
        }
      }
      s21_remove_matrix(&minor);
    } else {
      error_falg = 2;
    }
  } else {
    error_falg = 1;
  }

  return error_falg;
}