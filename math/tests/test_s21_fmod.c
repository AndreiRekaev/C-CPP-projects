#include "main.h"

START_TEST(fmod_1) {
  double x1 = S21_NAN, y1 = 2.5;
  double x2 = S21_NAN, y2 = 2.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fmod_2) {
  double x1 = 10.23, y1 = S21_NAN;
  double x2 = 10.23, y2 = S21_NAN;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fmod_3) {
  double x1 = 10.23, y1 = 0;
  double x2 = 10.23, y2 = 0;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fmod_4) {
  double x1 = S21_INF, y1 = 2.5;
  double x2 = S21_INF, y2 = 2.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fmod_5) {
  double x1 = S21_MINF, y1 = 2.5;
  double x2 = S21_MINF, y2 = 2.5;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_nan(res1);
  ck_assert_ldouble_nan(res2);
}
END_TEST

START_TEST(fmod_6) {
  double x1 = 10.6, y1 = S21_INF;
  double x2 = 10.6, y2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_7) {
  double x1 = 10.6, y1 = S21_MINF;
  double x2 = 10.6, y2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_8) {
  double x1 = DBL_MAX, y1 = S21_INF;
  double x2 = DBL_MAX, y2 = S21_INF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_9) {
  double x1 = DBL_MIN, y1 = S21_MINF;
  double x2 = DBL_MIN, y2 = S21_MINF;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_10) {
  double x1 = DBL_MAX, y1 = DBL_MAX;
  double x2 = DBL_MAX, y2 = DBL_MAX;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_11) {
  double x1 = DBL_MIN, y1 = DBL_EPSILON;
  double x2 = DBL_MIN, y2 = DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_12) {
  double x1 = -DBL_MAX, y1 = -DBL_EPSILON * 3;
  double x2 = -DBL_MAX, y2 = -DBL_EPSILON * 3;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_13) {
  double x1 = -DBL_MIN, y1 = -DBL_EPSILON;
  double x2 = -DBL_MIN, y2 = -DBL_EPSILON;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_14) {
  double x1 = 123456.123456, y1 = 10.66;
  double x2 = 123456.123456, y2 = 10.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_15) {
  double x1 = -123456.123456, y1 = 10.66;
  double x2 = -123456.123456, y2 = 10.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Le\n%.40Le\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_16) {
  double x1 = -123456.123456, y1 = 1234523450.66;
  double x2 = -123456.123456, y2 = 1234523450.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_17) {
  double x1 = 0, y1 = 1234523450.66;
  double x2 = 0, y2 = 1234523450.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_18) {
  double x1 = DBL_MAX, y1 = 1234523450.66;
  double x2 = DBL_MAX, y2 = 1234523450.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_19) {
  double x1 = -234564512453212341234.2 * 12345.365637, y1 = 1234523450.66;
  double x2 = -234564512453212341234.2 * 12345.365637, y2 = 1234523450.66;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_20) {
  double x1 = 12, y1 = 2;
  double x2 = 12, y2 = 2;
  long double res1 = 0, res2 = 0;
  res1 = s21_fmod(x1, y1);
  res2 = fmod(x2, y2);
  // printf("%.40Lf\n%.40Lf\n", res1, res2);
  ck_assert_ldouble_eq(res1, res2);
}
END_TEST

START_TEST(fmod_21) {
  double x1 = DBL_MAX, y1 = -123.123;
  double x2 = DBL_MAX, y2 = -123.123;
  long double res1 = 0, res2 = 0;
  for (; x1 >= 0; x1 = x1 / 2 - 1, x2 = x2 / 2 - 1) {
    res1 = s21_fmod(x1, y1);
    res2 = fmod(x2, y2);
    // printf("%.40Lf\n%.40Lf\n", res1, res2);
    ck_assert_ldouble_eq(res1, res2);
  }
}
END_TEST

Suite *test_fmod(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_FMOD=-\033[0m");
  TCase *tc = tcase_create("fmod_tc");

  tcase_add_test(tc, fmod_1);
  tcase_add_test(tc, fmod_2);
  tcase_add_test(tc, fmod_3);
  tcase_add_test(tc, fmod_4);
  tcase_add_test(tc, fmod_5);
  tcase_add_test(tc, fmod_6);
  tcase_add_test(tc, fmod_7);
  tcase_add_test(tc, fmod_8);
  tcase_add_test(tc, fmod_9);
  tcase_add_test(tc, fmod_10);
  tcase_add_test(tc, fmod_11);
  tcase_add_test(tc, fmod_12);
  tcase_add_test(tc, fmod_13);
  tcase_add_test(tc, fmod_14);
  tcase_add_test(tc, fmod_15);
  tcase_add_test(tc, fmod_16);
  tcase_add_test(tc, fmod_17);
  tcase_add_test(tc, fmod_18);
  tcase_add_test(tc, fmod_19);
  tcase_add_test(tc, fmod_20);
  tcase_add_test(tc, fmod_21);

  suite_add_tcase(s, tc);
  return s;
}
