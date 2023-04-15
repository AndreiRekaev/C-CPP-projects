#include "test_s21_matrix.h"

START_TEST(determinant_test_1) {
  matrix_t A = {S21_NULL, 0, 0};
  double result = 0.;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 1);
}
END_TEST

START_TEST(determinant_test_2) {
  matrix_t A = {S21_NULL, 0, 0};
  s21_create_matrix(1, 2, &A);
  double result = 0;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 2);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_3) {
  matrix_t A = {S21_NULL, 0, 0};
  s21_create_matrix(2, 2, &A);
  double result = 0;
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  A.matrix[1][0] = 4.;
  A.matrix[1][1] = 5.;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, -3.);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_4) {
  matrix_t A = {S21_NULL, 0, 0};
  s21_create_matrix(3, 3, &A);
  double result = 0;
  A.matrix[0][0] = 1.;
  A.matrix[0][1] = 2.;
  A.matrix[0][2] = 3.;
  A.matrix[1][0] = 4.;
  A.matrix[1][1] = 5.;
  A.matrix[1][2] = 6.;
  A.matrix[2][0] = 7.;
  A.matrix[2][1] = 8.;
  A.matrix[2][2] = 9.;
  int answer = s21_determinant(&A, &result);
  ck_assert_int_eq(answer, 0);
  ck_assert_double_eq(result, 0.);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_5) {
  matrix_t A = {0};
  int rows = 4, columns = 4;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  A.matrix[0][0] = 4;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 6;
  A.matrix[0][3] = 7;
  A.matrix[1][0] = 8;
  A.matrix[1][1] = 12;
  A.matrix[1][2] = 11;
  A.matrix[1][3] = 9;
  A.matrix[2][0] = 3;
  A.matrix[2][1] = 7;
  A.matrix[2][2] = 4;
  A.matrix[2][3] = 5;
  A.matrix[3][0] = 6;
  A.matrix[3][1] = 9;
  A.matrix[3][2] = 10;
  A.matrix[3][3] = 4;
  s21_determinant(&A, &result);
  ck_assert_double_eq(result, -135);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_6) {
  matrix_t A;
  double result = 0;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  double vars[9] = {7, 1, 2, 3, 4, 5, 6, 7, 0};
  int k = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = vars[k++];
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), 0);
  ck_assert_double_eq(result, -221);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(determinant_test_7) {
  matrix_t A = {0};
  int rows = 10, columns = 7;
  s21_create_matrix(rows, columns, &A);
  double result = 0.0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = (double)(rand()) / RAND_MAX;
    }
  }
  ck_assert_int_eq(s21_determinant(&A, &result), 2);
  s21_remove_matrix(&A);
}
END_TEST

Suite *st_s21_determinant(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=DETERMINANT=-\033[0m");
  TCase *tc_determinant = tcase_create("s21_determinant_tc");

  tcase_add_test(tc_determinant, determinant_test_1);
  tcase_add_test(tc_determinant, determinant_test_2);
  tcase_add_test(tc_determinant, determinant_test_3);
  tcase_add_test(tc_determinant, determinant_test_4);
  tcase_add_test(tc_determinant, determinant_test_5);
  tcase_add_test(tc_determinant, determinant_test_6);
  tcase_add_test(tc_determinant, determinant_test_7);

  suite_add_tcase(s, tc_determinant);
  return s;
}