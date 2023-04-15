#include "test_s21_matrix.h"

START_TEST(sum_test_1) {
  matrix_t A = {S21_NULL, 0, 0};
  matrix_t B = {S21_NULL, 0, 0};
  matrix_t result = {S21_NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  s21_create_matrix(2, 2, &B);
  int answer = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(sum_test_2) {
  matrix_t A = {S21_NULL, 0, 0};
  matrix_t B = {S21_NULL, 0, 0};
  matrix_t result = {S21_NULL, 0, 0};
  int answer = s21_sum_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 1);
}
END_TEST

START_TEST(sum_test_3) {
  matrix_t A = {0}, B = {0}, result = {0};
  int rows = 5, columns = 5;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &B);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_sum_matrix(&A, &B, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] + B.matrix[i][j],
                              result.matrix[i][j], 1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

Suite *st_s21_sum_matrix(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=SUM_MATRIX=-\033[0m");
  TCase *tc_sum_matrix = tcase_create("s21_sum_matrix_tc");

  tcase_add_test(tc_sum_matrix, sum_test_1);
  tcase_add_test(tc_sum_matrix, sum_test_2);
  tcase_add_test(tc_sum_matrix, sum_test_3);

  suite_add_tcase(s, tc_sum_matrix);
  return s;
}