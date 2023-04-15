#include "test_s21_matrix.h"

START_TEST(mulnum_test_1) {
  matrix_t A = {S21_NULL, 0, 0};
  matrix_t result = {S21_NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  A.matrix[0][0] = 1.;
  int answer = s21_mult_number(&A, 5., &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result.matrix[0][0], 5.);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mulnum_test_2) {
  matrix_t A = {S21_NULL, 0, 0};
  s21_create_matrix(1, 1, &A);
  int answer = s21_mult_number(&A, 5., S21_NULL);
  ck_assert_int_eq(answer, 1);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(mulnum_test_3) {
  matrix_t A = {0}, result = {0};
  int rows = 5, columns = 5;
  double number = (double)(rand()) / RAND_MAX;
  s21_create_matrix(rows, columns, &A);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_number(&A, number, &result), 0);
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      ck_assert_double_eq_tol(A.matrix[i][j] * number, result.matrix[i][j],
                              1e-8);
    }
  }
  s21_remove_matrix(&A);
  s21_remove_matrix(&result);
}
END_TEST

Suite *st_s21_mult_number(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=MULT_NUMBER=-\033[0m");
  TCase *tc_mult_number = tcase_create("s21_mult_number_tc");

  tcase_add_test(tc_mult_number, mulnum_test_1);
  tcase_add_test(tc_mult_number, mulnum_test_2);
  tcase_add_test(tc_mult_number, mulnum_test_3);

  suite_add_tcase(s, tc_mult_number);
  return s;
}