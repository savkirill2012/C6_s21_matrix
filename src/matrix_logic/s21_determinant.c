#include "../s21_matrix.h"

int __search_biggest_abs_num_in_column(matrix_t *A, int column_num) {
  double biggest_val = fabs(A->matrix[column_num][column_num]);
  int row_num_with_big_num = column_num;

  for (int i = column_num; i < A->rows; i++) {
    double loc_val = fabs(A->matrix[i][column_num]);
    if (loc_val > biggest_val) {
      biggest_val = loc_val;
      row_num_with_big_num = i;
    }
  }

  return row_num_with_big_num;
}

void __swap_rows_in_matrix(matrix_t *A, int num_swap_row, int num_row_to_swap) {
  double *temp_massiv = A->matrix[num_swap_row];
  A->matrix[num_swap_row] = A->matrix[num_row_to_swap];
  A->matrix[num_row_to_swap] = temp_massiv;
}

int __search_nearest_num_in_row_not_equal_zero(matrix_t *A, int column_num) {
  int num_row_to_swap = column_num;

  for (int i = column_num; i < A->columns; i++) {
    if (fabs(A->matrix[column_num][column_num] - A->matrix[column_num][i]) >
        1e-7) {
      num_row_to_swap = i;
      break;
    }
  }

  return num_row_to_swap;
}

void __swap_columns_in_matrix(matrix_t *A, int num_swap_column,
                              int num_column_to_swap) {
  for (int i = 0; i < A->columns; i++) {
    double temp_val = A->matrix[i][num_swap_column];
    A->matrix[i][num_swap_column] = A->matrix[i][num_column_to_swap];
    A->matrix[i][num_column_to_swap] = temp_val;
  }
}

void __column_lower_pos_to_zero(matrix_t *A, int pos_in_column) {
  for (int i = pos_in_column + 1; i < A->columns; i++) {
    double temp_val = A->matrix[i][pos_in_column];
    for (int j = pos_in_column; j < A->columns; j++) {
      A->matrix[i][j] =
          A->matrix[i][j] + (-1 * A->matrix[pos_in_column][j] * temp_val /
                             A->matrix[pos_in_column][pos_in_column]);
    }
  }
}

int __triangle_matrix(matrix_t *A, int *times_swap) {
  int error_flag = 0;

  for (int loc_column = 0; loc_column < A->columns; loc_column++) {
    // поиск наибольшего значения по модулю в столбце
    int num_row_to_change_with =
        __search_biggest_abs_num_in_column(A, loc_column);
    if (loc_column != num_row_to_change_with) {
      // смена строк местами
      __swap_rows_in_matrix(A, loc_column, num_row_to_change_with);
      *times_swap += 1;
    }

    if (fabs(A->matrix[loc_column][loc_column] - 0) < 1e-7) {
      // поиск позиции ближайшего элемента в строке не равного 0
      int num_column_to_change_with =
          __search_nearest_num_in_row_not_equal_zero(A, loc_column);
      if (num_column_to_change_with != loc_column) {
        // изменение столбцов местами
        __swap_columns_in_matrix(A, loc_column, num_column_to_change_with);
        *times_swap += 1;
      } else {
        // вся строка равна 0 и матрица вырожденая
        error_flag = -1;
        break;
      }
    }
    // обнуление всех строк в определенном столбце ниже текущей
    __column_lower_pos_to_zero(A, loc_column);
  }

  return error_flag;
}

//поиск определителя материцы
int s21_determinant(matrix_t *A, double *result) {
  int error_flag = 0;
  int times_swap_sign = 0;

  if (check_matrix(A)) {
    // проверка на квадратную матрицу
    if (check_is_square_matrix(A)) {
      // приведение матрицы к треугольному виду
      int ret_val = __triangle_matrix(A, &times_swap_sign);
      if (ret_val != -1) {
        *result = 1;
        // перемножение диагонали
        for (int i = 0; i < A->columns; i++) {
          *result *= A->matrix[i][i];
        }

        if (times_swap_sign % 2 == 1) {
          *result *= -1;
        }
      } else {
        *result = 0;
      }
    } else {
      error_flag = 2;
    }
  } else {
    error_flag = 1;
  }

  return error_flag;
}