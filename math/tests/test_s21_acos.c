#include "main.h"

START_TEST(acos_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_10) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_11) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(acos_12) {
  double x1 = -1.0 - DBL_EPSILON;
  double x2 = -1.0 - DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_13) {
  double x1 = 1.0 + DBL_EPSILON;
  double x2 = 1.0 + DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_acos(x1);
  res2 = acos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(acos_14) {
  double x1 = 1;
  double x2 = 1;
  double step = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1; x1 -= step, x2 -= step, step *= 2) {
    res1 = s21_acos(x1);
    res2 = acos(x2);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(acos_15) {
  double x1 = 1.0;
  double x2 = 1.0;
  double step = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1.0; x1 -= step, x2 -= step) {
    res1 = s21_acos(x1);
    res2 = acos(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-10);
    if (x1 > 0.1) {
      step *= 2;
    } else if (x1 < -0.1) {
      if (step / 2 > DBL_EPSILON) step /= 2;
    }
  }
}
END_TEST

Suite *test_acos(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_ACOS=-\033[0m");
  TCase *tc = tcase_create("acos_tc");

  tcase_add_test(tc, acos_1);
  tcase_add_test(tc, acos_2);
  tcase_add_test(tc, acos_3);
  tcase_add_test(tc, acos_4);
  tcase_add_test(tc, acos_5);
  tcase_add_test(tc, acos_6);
  tcase_add_test(tc, acos_7);
  tcase_add_test(tc, acos_8);
  tcase_add_test(tc, acos_9);
  tcase_add_test(tc, acos_10);
  tcase_add_test(tc, acos_11);
  tcase_add_test(tc, acos_12);
  tcase_add_test(tc, acos_13);
  tcase_add_test(tc, acos_14);
  tcase_add_test(tc, acos_15);

  suite_add_tcase(s, tc);
  return s;
}
