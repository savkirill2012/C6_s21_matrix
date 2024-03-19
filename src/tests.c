#include <check.h>

#include "s21_matrix.h"

#define SUITE_NAME "Unit"
#define TCASE_NAME "Tests"

START_TEST(s21_create_remove_matrix_test) {
  matrix_t test_matrix;
  int ret_val;
  ret_val = s21_create_matrix(3, 3, &test_matrix);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix.matrix[i][j] = i;
    }
  }

  s21_remove_matrix(&test_matrix);

  ck_assert_int_eq(ret_val, 0);
}
END_TEST

START_TEST(s21_equal_matrix_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_2);
  s21_create_matrix(2, 3, &test_matrix_3);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
      test_matrix_2.matrix[i][j] = i;
    }
  }

  ret_val = s21_eq_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(ret_val, 1);

  // case 2
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
      test_matrix_2.matrix[i][j] = j;
    }
  }

  ret_val = s21_eq_matrix(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(ret_val, 0);

  // case 3
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
      if (i != 2) {
        test_matrix_3.matrix[i][j] = j;
      }
    }
  }

  ret_val = s21_eq_matrix(&test_matrix_1, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(s21_sum_matrix_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3, test_matrix_4,
      test_matrix_5;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_2);

  s21_create_matrix(0, 0, &test_matrix_4);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
      test_matrix_2.matrix[i][j] = i;
    }
  }

  ret_val = s21_sum_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_3.matrix[i][j], i * 2);
    }
  }

  // case 2
  ret_val = s21_sum_matrix(&test_matrix_1, &test_matrix_4, &test_matrix_5);

  ck_assert_int_eq(ret_val, 1);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(s21_sub_matrix_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3, test_matrix_4;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(3, 3, &test_matrix_2);

  s21_create_matrix(0, 0, &test_matrix_4);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
      test_matrix_2.matrix[i][j] = i;
    }
  }

  ret_val = s21_sub_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_3.matrix[i][j], 0);
    }
  }

  // case 2
  ret_val = s21_sub_matrix(&test_matrix_1, &test_matrix_4, &test_matrix_3);

  ck_assert_int_eq(ret_val, 1);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
  s21_remove_matrix(&test_matrix_4);
}
END_TEST

START_TEST(s21_mult_number_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);
  s21_create_matrix(0, 0, &test_matrix_2);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
    }
  }

  ret_val = s21_mult_number(&test_matrix_1, 2, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_3.matrix[i][j], i * 2);
    }
  }

  // case 2
  ret_val = s21_mult_number(&test_matrix_2, 2, &test_matrix_3);

  ck_assert_int_eq(ret_val, 1);

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(s21_mult_matrix_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3;
  int ret_val;

  s21_create_matrix(3, 2, &test_matrix_1);
  s21_create_matrix(2, 3, &test_matrix_2);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      test_matrix_1.matrix[i][j] = i;
      test_matrix_2.matrix[j][i] = j;
    }
  }

  ret_val = s21_mult_matrix(&test_matrix_1, &test_matrix_2, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_3.matrix[i][j], i);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(s21_transpose_test) {
  matrix_t test_matrix_1, test_matrix_2;
  int ret_val;

  s21_create_matrix(3, 2, &test_matrix_1);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 2; j++) {
      test_matrix_1.matrix[i][j] = i;
    }
  }

  ret_val = s21_transpose(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_2.matrix[i][j], j);
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
}
END_TEST

START_TEST(s21_calc_complements_test) {
  matrix_t test_matrix_1, test_matrix_2, test_matrix_3;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i;
    }
  }

  ret_val = s21_calc_complements(&test_matrix_1, &test_matrix_2);

  ck_assert_int_eq(ret_val, 0);
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_double_eq(test_matrix_2.matrix[i][j], 0);
    }
  }

  // case 2
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 0) {
        test_matrix_1.matrix[i][j] = j + 1;
      } else if (i == 1) {
        test_matrix_1.matrix[i][j] = 3 - j;
      } else if (i == 2) {
        if (j == 2) {
          test_matrix_1.matrix[i][2 - j] = 1;
        } else {
          test_matrix_1.matrix[i][2 - j] = 2 + j;
        }
      }
    }
  }

  ret_val = s21_calc_complements(&test_matrix_1, &test_matrix_3);

  ck_assert_int_eq(ret_val, 0);
  int test_case[] = {1, -5, 7, 5, -1, -1, -4, 8, -4};
  int loc_counter = 0;
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      ck_assert_int_eq((int)roundl(test_matrix_3.matrix[i][j]),
                       test_case[loc_counter]);
      loc_counter++;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&test_matrix_2);
  s21_remove_matrix(&test_matrix_3);
}
END_TEST

START_TEST(s21_determinant_test) {
  matrix_t test_matrix_1;
  int ret_val;
  double minor;

  s21_create_matrix(3, 3, &test_matrix_1);

  // case 1
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      test_matrix_1.matrix[i][j] = i + 1;
    }
  }

  ret_val = s21_determinant(&test_matrix_1, &minor);

  ck_assert_int_eq(ret_val, 0);
  ck_assert_int_eq(minor, 0);

  // case 2
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (i == 0) {
        test_matrix_1.matrix[i][j] = j + 1;
      } else if (i == 1) {
        test_matrix_1.matrix[i][j] = 3 - j;
      } else if (i == 2) {
        if (j == 2) {
          test_matrix_1.matrix[i][2 - j] = 1;
        } else {
          test_matrix_1.matrix[i][2 - j] = 2 + j;
        }
      }
    }
  }

  ret_val = s21_determinant(&test_matrix_1, &minor);

  ck_assert_int_eq(ret_val, 0);
  ck_assert_int_eq((int)roundl(minor), 12);

  s21_remove_matrix(&test_matrix_1);
}
END_TEST

START_TEST(s21_inverse_matrix_test) {
  matrix_t test_matrix_1, result;
  int ret_val;

  s21_create_matrix(3, 3, &test_matrix_1);

  // case 1
  double test_case[] = {2, 5, 7, 6, 3, 4, 5, -2, -3};
  int loc_counter = 0;
  for (int i = 0; i < test_matrix_1.rows; i++) {
    for (int j = 0; j < test_matrix_1.rows; j++) {
      test_matrix_1.matrix[i][j] = test_case[loc_counter];
      loc_counter++;
    }
  }

  ret_val = s21_inverse_matrix(&test_matrix_1, &result);

  ck_assert_int_eq(ret_val, 0);
  int check_case[] = {1, -1, 1, -38, 41, -34, 27, -29, 24};
  loc_counter = 0;
  for (int i = 0; i < result.rows; i++) {
    for (int j = 0; j < result.rows; j++) {
      ck_assert_int_eq((int)roundl(result.matrix[i][j]),
                       check_case[loc_counter]);
      loc_counter++;
    }
  }

  s21_remove_matrix(&test_matrix_1);
  s21_remove_matrix(&result);
}
END_TEST

int main(void) {
  Suite *suite = suite_create(SUITE_NAME);
  TCase *tcase = tcase_create(TCASE_NAME);
  SRunner *srunner = srunner_create(suite);
  int counted_errors = 0;

  suite_add_tcase(suite, tcase);
  tcase_add_test(tcase, s21_create_remove_matrix_test);
  tcase_add_test(tcase, s21_equal_matrix_test);
  tcase_add_test(tcase, s21_sum_matrix_test);
  tcase_add_test(tcase, s21_sub_matrix_test);
  tcase_add_test(tcase, s21_mult_number_test);
  tcase_add_test(tcase, s21_mult_matrix_test);
  tcase_add_test(tcase, s21_transpose_test);
  tcase_add_test(tcase, s21_calc_complements_test);
  tcase_add_test(tcase, s21_determinant_test);
  tcase_add_test(tcase, s21_inverse_matrix_test);

  srunner_set_fork_status(srunner, CK_NOFORK);
  srunner_run_all(srunner, CK_VERBOSE);
  counted_errors = srunner_ntests_failed(srunner);
  srunner_free(srunner);

  return counted_errors == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
