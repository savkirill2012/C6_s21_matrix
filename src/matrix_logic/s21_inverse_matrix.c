#include "../s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int error_flag = 0;

  if (check_matrix(A)) {
    double determinant;
    matrix_t copy_matrix;
    s21_create_matrix(A->rows, A->columns, &copy_matrix);

    for (int i = 0; i < copy_matrix.rows; i++) {
      for (int j = 0; j < copy_matrix.columns; j++) {
        copy_matrix.matrix[i][j] = A->matrix[i][j];
      }
    }

    if (check_is_square_matrix(A) &&
        s21_determinant(&copy_matrix, &determinant) == 0) {
      matrix_t loc_matrix_1, loc_matrix_2;
      error_flag = s21_calc_complements(A, &loc_matrix_1);

      if (error_flag == 0) {
        s21_transpose(&loc_matrix_1, &loc_matrix_2);
        s21_remove_matrix(&loc_matrix_1);
        s21_mult_number(&loc_matrix_2, -1, result);
        s21_remove_matrix(&loc_matrix_2);
      }
    } else {
      error_flag = 2;
    }

    s21_remove_matrix(&copy_matrix);
  } else {
    error_flag = 1;
  }

  return error_flag;
}