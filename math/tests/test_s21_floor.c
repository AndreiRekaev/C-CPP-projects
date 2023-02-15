#include "main.h"

START_TEST(floor_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(floor_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_10) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_11) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_12) {
  double x1 = INT_MAX;
  double x2 = INT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_13) {
  double x1 = 12345.12345;
  double x2 = 12345.12345;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_14) {
  double x1 = 4503599627370495.5;
  double x2 = 4503599627370495.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_15) {
  double x1 = 9007199254740991;
  double x2 = 9007199254740991;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_16) {
  double x1 = 9007199254740991.5;
  double x2 = 9007199254740991.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_17) {
  double x1 = -1125899906842623.6;
  double x2 = -1125899906842623.6;
  long double res1 = 0, res2 = 0;
  res1 = s21_floor(x1);
  res2 = floor(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(floor_18) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  for (; x1 > 0; x1 = x1 / 2, x2 = x2 / 2) {
    res1 = s21_floor(x1 + 0.6);
    res2 = floor(x2 + 0.6);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq(res1, res2);
  }
}
END_TEST

START_TEST(floor_19) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  for (; x1 < 0; x1 = x1 / 2, x2 = x2 / 2) {
    res1 = s21_floor(x1 + 0.6);
    res2 = floor(x2 + 0.6);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq(res1, res2);
  }
}
END_TEST

Suite *test_floor(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_FLOOR=-\033[0m");
  TCase *tc = tcase_create("floor_tc");

  tcase_add_test(tc, floor_1);
  tcase_add_test(tc, floor_2);
  tcase_add_test(tc, floor_3);
  tcase_add_test(tc, floor_4);
  tcase_add_test(tc, floor_5);
  tcase_add_test(tc, floor_6);
  tcase_add_test(tc, floor_7);
  tcase_add_test(tc, floor_8);
  tcase_add_test(tc, floor_9);
  tcase_add_test(tc, floor_10);
  tcase_add_test(tc, floor_11);
  tcase_add_test(tc, floor_12);
  tcase_add_test(tc, floor_13);
  tcase_add_test(tc, floor_14);
  tcase_add_test(tc, floor_15);
  tcase_add_test(tc, floor_16);
  tcase_add_test(tc, floor_17);
  tcase_add_test(tc, floor_18);
  tcase_add_test(tc, floor_19);

  suite_add_tcase(s, tc);
  return s;
}
