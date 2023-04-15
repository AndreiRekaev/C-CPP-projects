#include "test_s21_matrix.h"

START_TEST(inverse_matrix_test_1) {
  matrix_t A, result, result_true;
  int rows = 3, columns = 3;
  s21_create_matrix(rows, columns, &A);
  s21_create_matrix(rows, columns, &result_true);
  A.matrix[0][0] = 2;
  A.matrix[0][1] = 5;
  A.matrix[0][2] = 7;
  A.matrix[1][0] = 6;
  A.matrix[1][1] = 3;
  A.matrix[1][2] = 4;
  A.matrix[2][0] = 5;
  A.matrix[2][1] = -2;
  A.matrix[2][2] = -3;
  result_true.matrix[0][0] = 1;
  result_true.matrix[0][1] = -1;
  result_true.matrix[0][2] = 1;
  result_true.matrix[1][0] = -38;
  result_true.matrix[1][1] = 41;
  result_true.matrix[1][2] = -34;
  result_true.matrix[2][0] = 27;
  result_true.matrix[2][1] = -29;
  result_true.matrix[2][2] = 24;
  s21_inverse_matrix(&A, &result);

  ck_assert_int_eq(s21_eq_matrix(&result, &result_true), 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&result_true);
  s21_remove_matrix(&result);
}
END_TEST

START_TEST(inverse_matrix_test_2) {
  matrix_t A;
  matrix_t B;
  int rows = 1, columns = 1;
  s21_create_matrix(rows, columns, &A);
  double vars[1] = {-7};
  int k = 0;
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < columns; j++) {
      A.matrix[i][j] = vars[k++];
    }
  }
  ck_assert_int_eq(s21_inverse_matrix(&A, &B), 0);
  ck_assert_double_eq(B.matrix[0][0], -1.0 / 7);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
}
END_TEST

START_TEST(inverse_matrix_test_3) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 9;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  matrix_t res;
  int return_value = s21_inverse_matrix(&A, &res);
  matrix_t C;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = 27;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 1;
  C.matrix[1][2] = -6;
  C.matrix[2][0] = 0;
  C.matrix[2][1] = 0.0;
  C.matrix[2][2] = 1;
  if (return_value == OK) return_value = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(return_value, 1);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_test_4) {
  matrix_t A, B, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 44300.0 / 367429.0;
  C.matrix[0][1] = -236300.0 / 367429.0;
  C.matrix[0][2] = 200360.0 / 367429.0;
  C.matrix[1][0] = 20600.0 / 367429.0;
  C.matrix[1][1] = 56000.0 / 367429.0;
  C.matrix[1][2] = -156483.0 / 367429.0;
  C.matrix[2][0] = 30900.0 / 367429.0;
  C.matrix[2][1] = 84000.0 / 367429.0;
  C.matrix[2][2] = -51010.0 / 367429.0;
  A.matrix[0][0] = 2.8;
  A.matrix[0][1] = 1.3;
  A.matrix[0][2] = 7.01;
  A.matrix[1][0] = -1.03;
  A.matrix[1][1] = -2.3;
  A.matrix[1][2] = 3.01;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = -3;
  A.matrix[2][2] = 2;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_test_5) {
  matrix_t A, C;
  s21_create_matrix(3, 3, &A);
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1.0;
  C.matrix[0][1] = -1.0;
  C.matrix[0][2] = 1.0;
  C.matrix[1][0] = -38.0;
  C.matrix[1][1] = 41.0;
  C.matrix[1][2] = -34.0;
  C.matrix[2][0] = 27.0;
  C.matrix[2][1] = -29.0;
  C.matrix[2][2] = 24.0;
  A.matrix[0][0] = 2.0;
  A.matrix[0][1] = 5.0;
  A.matrix[0][2] = 7.0;
  A.matrix[1][0] = 6.0;
  A.matrix[1][1] = 3.0;
  A.matrix[1][2] = 4.0;
  A.matrix[2][0] = 5.0;
  A.matrix[2][1] = -2.0;
  A.matrix[2][2] = -3.0;
  matrix_t B;
  s21_inverse_matrix(&A, &B);
  int res = s21_eq_matrix(&B, &C);
  ck_assert_int_eq(res, 1);
  s21_remove_matrix(&A);
  s21_remove_matrix(&B);
  s21_remove_matrix(&C);
}
END_TEST

START_TEST(inverse_matrix_test_6) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    m.matrix[0][0] = 1431.12312331;
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(result.matrix[0][0] == (1.0 / m.matrix[0][0]), 1);
    ck_assert_int_eq(code, OK);
    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
  }
}
END_TEST

START_TEST(inverse_matrix_test_7) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 1, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_matrix_test_8) {
  matrix_t m = {0};
  matrix_t result = {0};
  int code = s21_inverse_matrix(&m, &result);
  ck_assert_int_eq(code, INCORRECT);
}
END_TEST

START_TEST(inverse_matrix_test_9) {
  matrix_t m = {0};
  matrix_t result = {0};
  int codec = s21_create_matrix(1, 4, &m);
  if (!codec) {
    int code = s21_inverse_matrix(&m, &result);
    ck_assert_int_eq(code, CALC_ERROR);
    s21_remove_matrix(&m);
  }
}
END_TEST

START_TEST(inverse_matrix_test_10) {
  matrix_t m = {0};
  matrix_t expected = {0};
  int codec1, codec2;
  codec1 = s21_create_matrix(3, 3, &m);
  if (!codec1) codec2 = s21_create_matrix(3, 3, &expected);

  if (!codec1 && !codec2) {
    m.matrix[0][0] = 2;
    m.matrix[0][1] = 5;
    m.matrix[0][2] = 7;

    m.matrix[1][0] = 6;
    m.matrix[1][1] = 3;
    m.matrix[1][2] = 4;

    m.matrix[2][0] = 5;
    m.matrix[2][1] = -2;
    m.matrix[2][2] = -3;

    expected.matrix[0][0] = 1;
    expected.matrix[0][1] = -1;
    expected.matrix[0][2] = 1;

    expected.matrix[1][0] = -38;
    expected.matrix[1][1] = 41;
    expected.matrix[1][2] = -34;

    expected.matrix[2][0] = 27;
    expected.matrix[2][1] = -29;
    expected.matrix[2][2] = 24;
    matrix_t result = {0};
    int code = s21_inverse_matrix(&m, &result);

    ck_assert_int_eq(s21_eq_matrix(&result, &expected), SUCCESS);
    ck_assert_int_eq(code, OK);

    s21_remove_matrix(&m);
    s21_remove_matrix(&result);
    s21_remove_matrix(&expected);
  }
}
END_TEST

START_TEST(inverse_matrix_test_11) {
  /* const int size = rand() % 100 + 1; */
  const int size = 3;
  matrix_t m = {0};
  s21_create_matrix(size, size, &m);

  m.matrix[0][0] = 2;
  m.matrix[0][1] = 5;
  m.matrix[0][2] = 7;
  m.matrix[1][0] = 6;
  m.matrix[1][1] = 3;
  m.matrix[1][2] = 4;
  m.matrix[2][0] = 5;
  m.matrix[2][1] = -2;
  m.matrix[2][2] = -3;

  matrix_t res = {0};
  s21_inverse_matrix(&m, &res);

  matrix_t expected = {0};
  s21_create_matrix(size, size, &expected);
  expected.matrix[0][0] = 1;
  expected.matrix[0][1] = -1;
  expected.matrix[0][2] = 1;
  expected.matrix[1][0] = -38;
  expected.matrix[1][1] = 41;
  expected.matrix[1][2] = -34;
  expected.matrix[2][0] = 27;
  expected.matrix[2][1] = -29;
  expected.matrix[2][2] = 24;

  ck_assert_int_eq(s21_eq_matrix(&expected, &res), SUCCESS);

  s21_remove_matrix(&expected);
  s21_remove_matrix(&res);
  s21_remove_matrix(&m);
}
END_TEST

START_TEST(inverse_matrix_test_12) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 1;
  A.matrix[0][2] = 1;
  A.matrix[1][0] = 1;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 1;
  A.matrix[2][0] = 1;
  A.matrix[2][1] = 1;
  A.matrix[2][2] = 1;
  matrix_t res;
  int return_value = s21_inverse_matrix(&A, &res);
  ck_assert_int_eq(return_value, CALC_ERROR);
  s21_remove_matrix(&A);
}
END_TEST

START_TEST(inverse_matrix_test_13) {
  matrix_t A;
  s21_create_matrix(3, 3, &A);
  A.matrix[0][0] = 1;
  A.matrix[0][1] = 6;
  A.matrix[0][2] = 9;
  A.matrix[1][0] = 0;
  A.matrix[1][1] = 1;
  A.matrix[1][2] = 6;
  A.matrix[2][0] = 0;
  A.matrix[2][1] = 0;
  A.matrix[2][2] = 1;
  matrix_t res;
  int return_value = s21_inverse_matrix(&A, &res);
  matrix_t C;
  s21_create_matrix(3, 3, &C);
  C.matrix[0][0] = 1;
  C.matrix[0][1] = -6;
  C.matrix[0][2] = 27;
  C.matrix[1][0] = 0.0;
  C.matrix[1][1] = 1;
  C.matrix[1][2] = -6;
  C.matrix[2][0] = 0;
  C.matrix[2][1] = 0.0;
  C.matrix[2][2] = 1;
  if (return_value == OK) return_value = s21_eq_matrix(&res, &C);
  ck_assert_int_eq(return_value, SUCCESS);
  s21_remove_matrix(&C);
  s21_remove_matrix(&A);
  s21_remove_matrix(&res);
}
END_TEST

START_TEST(inverse_matrix_test_14) {
  int return_value = s21_inverse_matrix(NULL, NULL);
  ck_assert_int_eq(return_value, INCORRECT);
}
END_TEST

Suite *st_s21_inverse_matrix(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=INVERSE_MATRIX=-\033[0m");
  TCase *tc_inverse_matrix = tcase_create("s21_inverse_matrix_tc");

  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_1);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_2);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_3);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_4);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_5);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_6);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_7);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_8);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_9);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_10);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_11);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_12);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_13);
  tcase_add_test(tc_inverse_matrix, inverse_matrix_test_14);

  suite_add_tcase(s, tc_inverse_matrix);
  return s;
}