#include "main.h"

START_TEST(sqrt_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(sqrt_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(sqrt_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(sqrt_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e+138);
}
END_TEST

START_TEST(sqrt_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(sqrt_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(sqrt_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(sqrt_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(sqrt_10) {
  double x1 = 1 - DBL_EPSILON;
  double x2 = 1 - DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_11) {
  double x1 = DBL_EPSILON;
  double x2 = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_12) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_13) {
  double x1 = INT_MAX;
  double x2 = INT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_14) {
  double x1 = ULONG_MAX;
  double x2 = ULONG_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_15) {
  double x1 = 123456789.123456789;
  double x2 = 123456789.123456789;
  long double res1 = 0, res2 = 0;
  res1 = s21_sqrt(x1);
  res2 = sqrt(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(sqrt_16) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  for (int i = 0; i < 1001; x1++, x2++, i++) {
    res1 = s21_sqrt(x1);
    res2 = sqrt(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(sqrt_17) {
  double x1 = 0.9;
  double x2 = 0.9;
  double step = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  for (; x1 > 0.0; x1 -= step, x2 -= step) {
    res1 = s21_sqrt(x1);
    res2 = sqrt(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
    if (x1 > 0.5 || x1 < 0.385) {
      step *= 2;
    } else {
      if (step / 2 > DBL_EPSILON) step /= 2;
    }
  }
}
END_TEST

START_TEST(sqrt_18) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  double step = 2;
  long double m = 1e+292;
  long double res1 = 0, res2 = 0;
  for (; x1 > 1.0; x1 /= step, x2 /= step) {
    res1 = s21_sqrt(x1);
    res2 = sqrt(x2);
    for (m = 10; m < res2; m *= 10)
      ;
    m /= 1e+16;
    if (m < 1e-6) m = 1e-6;
    // printf("%.17Lf\n%.17Lf\n%.17Lf\n", res1, res2, m);
    ck_assert_ldouble_eq_tol(res1, res2, m);
  }
}
END_TEST

Suite *test_sqrt(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_SQRT=-\033[0m");
  TCase *tc = tcase_create("sqrt_tc");

  tcase_add_test(tc, sqrt_1);
  tcase_add_test(tc, sqrt_2);
  tcase_add_test(tc, sqrt_3);
  tcase_add_test(tc, sqrt_4);
  tcase_add_test(tc, sqrt_5);
  tcase_add_test(tc, sqrt_6);
  tcase_add_test(tc, sqrt_7);
  tcase_add_test(tc, sqrt_8);
  tcase_add_test(tc, sqrt_9);
  tcase_add_test(tc, sqrt_10);
  tcase_add_test(tc, sqrt_11);
  tcase_add_test(tc, sqrt_12);
  tcase_add_test(tc, sqrt_13);
  tcase_add_test(tc, sqrt_14);
  tcase_add_test(tc, sqrt_15);
  tcase_add_test(tc, sqrt_16);
  tcase_add_test(tc, sqrt_17);
  tcase_add_test(tc, sqrt_18);

  suite_add_tcase(s, tc);
  return s;
}
