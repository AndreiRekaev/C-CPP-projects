#include "main.h"

START_TEST(cos_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(cos_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(cos_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(cos_4) {
  double x1 = UINT_MAX;
  double x2 = UINT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_5) {
  double x1 = -UINT_MAX;
  double x2 = -UINT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(cos_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(cos_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_10) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(cos_11) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(cos_12) {
  double x1 = UINT_MAX - DBL_EPSILON;
  double x2 = UINT_MAX - DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_13) {
  double x1 = -UINT_MAX + DBL_EPSILON;
  double x2 = -UINT_MAX + DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_14) {
  double x1 = PI_2;
  double x2 = PI_2;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_15) {
  double x1 = -PI_2;
  double x2 = -PI_2;
  long double res1 = 0, res2 = 0;
  res1 = s21_cos(x1);
  res2 = cos(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(cos_16) {
  double x1 = 2 * PI;
  double x2 = 2 * PI;
  double step = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1.0; x1 -= step, x2 -= step) {
    res1 = s21_cos(x1);
    res2 = cos(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
    if (x1 > 0.1 && step < 0.01) {
      step *= 2;
    }
  }
}
END_TEST

START_TEST(cos_17) {
  double x1 = 1000;
  double x2 = 1000;
  double step = PI_4;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1000; x1 -= step, x2 -= step) {
    res1 = s21_cos(x1 + DBL_EPSILON);
    res2 = cos(x2 + DBL_EPSILON);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

Suite *test_cos(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_COS=-\033[0m");
  TCase *tc = tcase_create("cos_tc");

  tcase_add_test(tc, cos_1);
  tcase_add_test(tc, cos_2);
  tcase_add_test(tc, cos_3);
  tcase_add_test(tc, cos_4);
  tcase_add_test(tc, cos_5);
  tcase_add_test(tc, cos_6);
  tcase_add_test(tc, cos_7);
  tcase_add_test(tc, cos_8);
  tcase_add_test(tc, cos_9);
  tcase_add_test(tc, cos_10);
  tcase_add_test(tc, cos_11);
  tcase_add_test(tc, cos_12);
  tcase_add_test(tc, cos_13);
  tcase_add_test(tc, cos_14);
  tcase_add_test(tc, cos_15);
  tcase_add_test(tc, cos_16);
  tcase_add_test(tc, cos_17);

  suite_add_tcase(s, tc);
  return s;
}
