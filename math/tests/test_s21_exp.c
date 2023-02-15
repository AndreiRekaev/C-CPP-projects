#include "main.h"

START_TEST(exp_1) {
  double x1 = 0;
  double x2 = 0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_2) {
  double x1 = -0;
  double x2 = -0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_3) {
  double x1 = 64;
  double x2 = 64;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("51 - %.40Lf\n51 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e+12);
}
END_TEST

START_TEST(exp_4) {
  double x1 = -64.0;
  double x2 = -64.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-64 - %.40Lf\n-64 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_5) {
  double x1 = 1000;
  double x2 = 1000;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("1000 - %Lf\n1000 - %Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_6) {
  double x1 = -1000;
  double x2 = -1000;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-1000 - %Lf\n-1000 - %Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_7) {
  double x1 = 0.5;
  double x2 = 0.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("0.5 - %.40Lf\n0.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_8) {
  double x1 = -0.5;
  double x2 = -0.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-0.5 - %.40Lf\n-0.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_9) {
  double x1 = 3.5;
  double x2 = 3.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("3.5 - %.40Lf\n3.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_10) {
  double x1 = -3.5;
  double x2 = -3.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-3.5 - %.40Lf\n-3.5 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_11) {
  double x1 = 1000.3;
  double x2 = 1000.3;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("1000.3 - %Lf\n1000.3 - %Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_12) {
  double x1 = -1000.3;
  double x2 = -1000.3;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-1000.3 - %.40Lf\n-1000.3 - %.40Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_13) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("1.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_14) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-1.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(exp_15) {
  double x1 = 1.0 / 0.0;
  double x2 = 1.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("1.0 / 0.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_16) {
  double x1 = -1.0 / 0.0;
  double x2 = -1.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-1.0 / 0.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(exp_17) {
  double x1 = 0.0 / 0.0;
  double x2 = 0.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("0.0 / 0.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(exp_18) {
  double x1 = -0.0 / 0.0;
  double x2 = -0.0 / 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("-0.0/ 0.0 - %Lf\n%Lf\n", res2, res1);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST
START_TEST(exp_19) {
  double x1 = 709.50;
  double x2 = 709.50;
  long double res1 = 0, res2 = 0;
  res1 = s21_exp(x1);
  res2 = exp(x2);
  // printf("%.40Lf\n%.40Lf\n", res2, res1);
  // ck_assert_ldouble_eq(res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e+292);
}
END_TEST
Suite *test_exp(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_EXP=-\033[0m");
  TCase *tc = tcase_create("exp_tc");

  tcase_add_test(tc, exp_1);
  tcase_add_test(tc, exp_2);
  tcase_add_test(tc, exp_3);
  tcase_add_test(tc, exp_4);
  tcase_add_test(tc, exp_5);
  tcase_add_test(tc, exp_6);
  tcase_add_test(tc, exp_7);
  tcase_add_test(tc, exp_8);
  tcase_add_test(tc, exp_9);
  tcase_add_test(tc, exp_10);
  tcase_add_test(tc, exp_11);
  tcase_add_test(tc, exp_12);
  tcase_add_test(tc, exp_13);
  tcase_add_test(tc, exp_14);
  tcase_add_test(tc, exp_15);
  tcase_add_test(tc, exp_16);
  tcase_add_test(tc, exp_17);
  tcase_add_test(tc, exp_18);
  tcase_add_test(tc, exp_19);

  suite_add_tcase(s, tc);
  return s;
}
