#include "main.h"

START_TEST(ceil_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(ceil_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_8) {
  double x1 = DBL_EPSILON;
  double x2 = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_9) {
  double x1 = -DBL_EPSILON;
  double x2 = -DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST
START_TEST(ceil_10) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_11) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_12) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_13) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_14) {
  double x1 = INT_MAX;
  double x2 = INT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_15) {
  double x1 = 12345.12345;
  double x2 = 12345.12345;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_16) {
  double x1 = 4503599627370495.5;
  double x2 = 4503599627370495.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_17) {
  double x1 = 9007199254740991;
  double x2 = 9007199254740991;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_18) {
  double x1 = 9007199254740991.5;
  double x2 = 9007199254740991.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_19) {
  double x1 = -1125899906842623.6;
  double x2 = -1125899906842623.6;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_20) {
  double x1 = -123.456;
  double x2 = -123.456;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_21) {
  double x1 = 123.456;
  double x2 = 123.456;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_22) {
  double x1 = -0.5;
  double x2 = -0.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_23) {
  double x1 = -0.999990;
  double x2 = -0.999990;
  long double res1 = 0, res2 = 0;
  res1 = s21_ceil(x1);
  res2 = ceil(x2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(ceil_24) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  for (; x1 > 0.5; x1 = x1 / 2, x2 = x2 / 2) {
    res1 = s21_ceil(x1 + 0.6);
    res2 = ceil(x2 + 0.6);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq(res1, res2);
  }
}
END_TEST

START_TEST(ceil_25) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  for (; x1 < -1; x1 = x1 / 2, x2 = x2 / 2) {
    res1 = s21_ceil(x1 + 0.3);
    res2 = ceil(x2 + 0.3);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq(res1, res2);
  }
}
END_TEST

Suite *test_ceil(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_CEIL=-\033[0m");
  TCase *tc = tcase_create("ceil_tc");

  tcase_add_test(tc, ceil_1);
  tcase_add_test(tc, ceil_2);
  tcase_add_test(tc, ceil_3);
  tcase_add_test(tc, ceil_4);
  tcase_add_test(tc, ceil_5);
  tcase_add_test(tc, ceil_6);
  tcase_add_test(tc, ceil_7);
  tcase_add_test(tc, ceil_8);
  tcase_add_test(tc, ceil_9);
  tcase_add_test(tc, ceil_10);
  tcase_add_test(tc, ceil_11);
  tcase_add_test(tc, ceil_12);
  tcase_add_test(tc, ceil_13);
  tcase_add_test(tc, ceil_14);
  tcase_add_test(tc, ceil_15);
  tcase_add_test(tc, ceil_16);
  tcase_add_test(tc, ceil_17);
  tcase_add_test(tc, ceil_18);
  tcase_add_test(tc, ceil_19);
  tcase_add_test(tc, ceil_20);
  tcase_add_test(tc, ceil_21);
  tcase_add_test(tc, ceil_22);
  tcase_add_test(tc, ceil_23);
  tcase_add_test(tc, ceil_24);
  tcase_add_test(tc, ceil_25);

  suite_add_tcase(s, tc);
  return s;
}
