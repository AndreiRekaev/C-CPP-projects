#include "main.h"

START_TEST(log_1) {
  double x1 = 0;
  double x2 = 0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("0 - %.40Lf\n0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(log_2) {
  double x1 = -0;
  double x2 = -0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-0 - %.40Lf\n-0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(log_3) {
  double x1 = 64;
  double x2 = 64;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("64 - %.40Lf\n64 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
}
END_TEST

START_TEST(log_4) {
  double x1 = -64.0;
  double x2 = -64.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-64 - %.40Lf\n-64 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_5) {
  double x1 = 1000;
  double x2 = 1000;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("1000 - %.40Lf\n1000 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
}
END_TEST

START_TEST(log_6) {
  double x1 = -1000;
  double x2 = -1000;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-1000 - %.40Lf\n-1000 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_7) {
  double x1 = 0.5;
  double x2 = 0.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("0.5 - %.40Lf\n0.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(log_8) {
  double x1 = -0.5;
  double x2 = -0.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-0.5 - %.40Lf\n-0.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_9) {
  double x1 = 3.5;
  double x2 = 3.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("3.5 - %.40Lf\n3.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(log_10) {
  double x1 = -3.5;
  double x2 = -3.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-3.5 - %.40Lf\n-3.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_11) {
  double x1 = 1000.3;
  double x2 = 1000.3;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("1000.3 - %.40Lf\n1000.3 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(log_12) {
  double x1 = -1000.3;
  double x2 = -1000.3;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-1000.3 - %.40Lf\n-1000.3 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_13) {
  double x1 = 65.0;
  double x2 = 65.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("1.0 - %.40Lf\n1.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(log_14) {
  double x1 = -2.0;
  double x2 = -2.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-2.0 - %.40Lf\n-2.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_15) {
  double x1 = 1.0 / 0.0;
  double x2 = 1.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("1.0 / 0.0 - %.40Lf\n1.0 / 0.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(log_16) {
  double x1 = -1.0 / 0.0;
  double x2 = -1.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-1.0 / 0.0 - %.40Lf\n-1.0 / 0.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_17) {
  double x1 = 0.0 / 0.0;
  double x2 = 0.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("0.0 / 0.0 - %.40Lf\n0.0 / 0.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(log_18) {
  double x1 = -0.0 / 0.0;
  double x2 = -0.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("-0.0 / 0.0 - %.40Lf\n-0.0 / 0.0 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST
START_TEST(log_19) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("DBL_MIN - %.40Lf\nDBL_MIN - %.40Lf\n", res2, res1);
  // ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
}
END_TEST

START_TEST(log_20) {
  double x1 = DBL_MAX / 10;
  double x2 = DBL_MAX / 10;
  long double res1 = 0, res2 = 0;
  res1 = s21_log(x1);
  res2 = log(x2);
  // printf("DBL_MAX - %.40Lf\nDBL_MAX - %.40Lf\n", res2, res1);
  // ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
}
END_TEST

START_TEST(log_21) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  for (; x1 > 0; x1 /= 10, x2 /= 10) {
    res1 = s21_log(x1);
    res2 = log(x2);
    // printf("DBL_MAX - %.40Lf\nDBL_MAX - %.40Lf\n", res2, res1);
    // ck_assert_ldouble_eq(res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
  }
}
END_TEST

Suite *test_log(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_LOG=-\033[0m");
  TCase *tc = tcase_create("log_tc");

  tcase_add_test(tc, log_1);
  tcase_add_test(tc, log_2);
  tcase_add_test(tc, log_3);
  tcase_add_test(tc, log_4);
  tcase_add_test(tc, log_5);
  tcase_add_test(tc, log_6);
  tcase_add_test(tc, log_7);
  tcase_add_test(tc, log_8);
  tcase_add_test(tc, log_9);
  tcase_add_test(tc, log_10);
  tcase_add_test(tc, log_11);
  tcase_add_test(tc, log_12);
  tcase_add_test(tc, log_13);
  tcase_add_test(tc, log_14);
  tcase_add_test(tc, log_15);
  tcase_add_test(tc, log_16);
  tcase_add_test(tc, log_17);
  tcase_add_test(tc, log_18);
  tcase_add_test(tc, log_19);
  tcase_add_test(tc, log_20);
  tcase_add_test(tc, log_21);

  suite_add_tcase(s, tc);
  return s;
}
