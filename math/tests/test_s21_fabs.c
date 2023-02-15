#include "main.h"

START_TEST(fabs_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fabs_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_10) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_11) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_12) {
  double x1 = -DBL_EPSILON;
  double x2 = -DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_13) {
  double x1 = DBL_EPSILON;
  double x2 = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_14) {
  double x1 = -DBL_MIN / 10000;
  double x2 = -DBL_MIN / 10000;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fabs_15) {
  double x1 = -DBL_MIN / DBL_MAX;
  double x2 = -DBL_MIN / DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_fabs(x1);
  res2 = fabs(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}

Suite *test_fabs(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_FABS=-\033[0m");
  TCase *tc = tcase_create("fabs_tc");

  tcase_add_test(tc, fabs_1);
  tcase_add_test(tc, fabs_2);
  tcase_add_test(tc, fabs_3);
  tcase_add_test(tc, fabs_4);
  tcase_add_test(tc, fabs_5);
  tcase_add_test(tc, fabs_6);
  tcase_add_test(tc, fabs_7);
  tcase_add_test(tc, fabs_8);
  tcase_add_test(tc, fabs_9);
  tcase_add_test(tc, fabs_10);
  tcase_add_test(tc, fabs_11);
  tcase_add_test(tc, fabs_12);
  tcase_add_test(tc, fabs_13);
  tcase_add_test(tc, fabs_14);
  tcase_add_test(tc, fabs_15);

  suite_add_tcase(s, tc);
  return s;
}
