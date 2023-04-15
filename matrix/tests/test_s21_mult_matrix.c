#include "test_s21_matrix.h"

START_TEST(mul_test_1) {
  matrix_t A = {0}, B = {0}, result;
  int Arows = 3, Acolumns = 5;
  int Brows = 5, Bcolumns = 6;
  s21_create_matrix(Arows, Acolumns, &A);
  s21_create_matrix(Brows, Bcolumns, &B);
  for (int i = 0; i < Arows; i++) {
    for (int j = 0; j < Acolumns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  for (int i = 0; i < Brows; i++) {
    for (int j = 0; j < Bcolumns; j++) {
      B.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 0);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_2) {
  matrix_t A = {0}, B = {0}, result = {0};
  A.matrix = NULL;
  B.matrix = NULL;
  ck_assert_int_eq(s21_mult_matrix(&A, &B, &result), 1);
}
END_TEST

START_TEST(mul_test_3) {
  matrix_t A = {S21_NULL, 0, 0};
  matrix_t B = {S21_NULL, 0, 0};
  matrix_t result = {S21_NULL, 0, 0};
  s21_create_matrix(1, 2, &A);
  s21_create_matrix(3, 1, &B);
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  B.matrix[0][0] = 2.;
  B.matrix[1][0] = 1.;
  B.matrix[2][0] = 2.;
  int answer = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(mul_test_4) {
  matrix_t A = {S21_NULL, 0, 0};
  matrix_t B = {S21_NULL, 0, 0};
  matrix_t result = {S21_NULL, 0, 0};
  int answer = s21_mult_matrix(&A, &B, &result);
  ck_assert_int_eq(answer, 1);
}
END_TEST

Suite *st_s21_mult_matrix(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=MULT_MATRIX=-\033[0m");
  TCase *tc_mult_matrix = tcase_create("s21_mult_matrix_tc");

  tcase_add_test(tc_mult_matrix, mul_test_1);
  tcase_add_test(tc_mult_matrix, mul_test_2);
  tcase_add_test(tc_mult_matrix, mul_test_3);
  tcase_add_test(tc_mult_matrix, mul_test_4);

  suite_add_tcase(s, tc_mult_matrix);
  return s;
}