#include "main.h"

START_TEST(atan_1) {
  double x1 = S21_NAN;
  double x2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(atan_2) {
  double x1 = S21_INF;
  double x2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_3) {
  double x1 = S21_MINF;
  double x2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_4) {
  double x1 = DBL_MAX;
  double x2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_5) {
  double x1 = -DBL_MAX;
  double x2 = -DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_6) {
  double x1 = 0.0;
  double x2 = 0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_7) {
  double x1 = -0.0;
  double x2 = -0.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(atan_8) {
  double x1 = 1.0;
  double x2 = 1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_9) {
  double x1 = -1.0;
  double x2 = -1.0;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_10) {
  double x1 = 1 - DBL_EPSILON;
  double x2 = 1 - DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_11) {
  double x1 = -1 + DBL_EPSILON;
  double x2 = -1 + DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_12) {
  double x1 = DBL_MIN;
  double x2 = DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_13) {
  double x1 = -DBL_MIN;
  double x2 = -DBL_MIN;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_14) {
  double x1 = 0.9;
  double x2 = 0.9;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_15) {
  double x1 = -0.55;
  double x2 = -0.55;
  long double res1 = 0, res2 = 0;
  res1 = s21_atan(x1);
  res2 = atan(x2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
}
END_TEST

START_TEST(atan_16) {
  double x1 = -500.0;
  double x2 = -500.0;
  long double res1 = 0, res2 = 0;
  for (int i = 0; i < 1001; x1++, x2++, i++) {
    res1 = s21_atan(x1);
    res2 = atan(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(atan_17) {
  double x1 = 0.9;
  double x2 = 0.9;
  double step = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  for (; x1 > -1.0; x1 -= step, x2 -= step) {
    res1 = s21_atan(x1);
    res2 = atan(x2);
    // printf("%.40lf\n%.40Lf\n%.40Lf\n", x1, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
    if (x1 > 0.1) {
      step *= 2;
    } else if (x1 < -0.1) {
      if (step / 2 > DBL_EPSILON) step /= 2;
    }
  }
}
END_TEST

Suite *test_atan(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_ATAN=-\033[0m");
  TCase *tc = tcase_create("atan_tc");

  tcase_add_test(tc, atan_1);
  tcase_add_test(tc, atan_2);
  tcase_add_test(tc, atan_3);
  tcase_add_test(tc, atan_4);
  tcase_add_test(tc, atan_5);
  tcase_add_test(tc, atan_6);
  tcase_add_test(tc, atan_7);
  tcase_add_test(tc, atan_8);
  tcase_add_test(tc, atan_9);
  tcase_add_test(tc, atan_10);
  tcase_add_test(tc, atan_11);
  tcase_add_test(tc, atan_12);
  tcase_add_test(tc, atan_13);
  tcase_add_test(tc, atan_14);
  tcase_add_test(tc, atan_15);
  tcase_add_test(tc, atan_16);
  tcase_add_test(tc, atan_17);

  suite_add_tcase(s, tc);
  return s;
}
