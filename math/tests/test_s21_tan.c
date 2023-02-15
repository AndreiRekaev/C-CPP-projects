#include "main.h"

START_TEST(tan_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(tan_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(tan_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(tan_4) {
  double x1 = 153.0 + PI_4;
  double x2 = 153.0 + PI_4;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_5) {
  double x1 = -153.0 + PI_4;
  double x2 = -153.0 + PI_4;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(tan_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(tan_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_10) {
  double x1 = PI_2 - DBL_EPSILON * 1e+9;
  double x2 = PI_2 - DBL_EPSILON * 1e+9;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_11) {
  double x1 = -PI_2 + DBL_EPSILON * 1e+9;
  double x2 = -PI_2 + DBL_EPSILON * 1e+9;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_12) {
  double x1 = PI_4;
  double x2 = PI_4;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_13) {
  double x1 = INT_MAX;
  double x2 = INT_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_14) {
  double x1 = PI_2;
  double x2 = PI_2;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_15) {
  double x1 = -PI_2;
  double x2 = -PI_2;
  long double res1 = 0, res2 = 0;
  res1 = s21_tan(x1);
  res2 = tan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(tan_16) {
  double x1 = PI_2 - DBL_EPSILON * 1e+9;
  double x2 = PI_2 - DBL_EPSILON * 1e+9;
  double step = DBL_EPSILON * 1e+9;
  long double res1 = 0, res2 = 0;
  for (; x1 > -PI_2; x1 -= (step * 100), x2 -= (step * 100)) {
    res1 = s21_tan(x1 - step);
    res2 = tan(x2 - step);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(tan_17) {
  double x1 = 1000;
  double x2 = 1000;
  double step = 1;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1000; x1 -= step, x2 -= step) {
    res1 = s21_tan(x1 + DBL_EPSILON);
    res2 = tan(x2 + DBL_EPSILON);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

Suite *test_tan(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_TAN=-\033[0m");
  TCase *tc = tcase_create("tan_tc");

  tcase_add_test(tc, tan_1);
  tcase_add_test(tc, tan_2);
  tcase_add_test(tc, tan_3);
  tcase_add_test(tc, tan_4);
  tcase_add_test(tc, tan_5);
  tcase_add_test(tc, tan_6);
  tcase_add_test(tc, tan_7);
  tcase_add_test(tc, tan_8);
  tcase_add_test(tc, tan_9);
  tcase_add_test(tc, tan_10);
  tcase_add_test(tc, tan_11);
  tcase_add_test(tc, tan_12);
  tcase_add_test(tc, tan_13);
  tcase_add_test(tc, tan_14);
  tcase_add_test(tc, tan_15);
  tcase_add_test(tc, tan_16);
  tcase_add_test(tc, tan_17);

  suite_add_tcase(s, tc);
  return s;
}
