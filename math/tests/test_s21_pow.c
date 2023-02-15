#include "main.h"

START_TEST(pow_1) {
  double x = 0., y = S21_INF;
  // printf("1:\n%.40Lf\n%.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_2) {
  double x = 0., y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_3) {
  double x = 0.0, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_4) {
  double x = 0.0, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_5) {
  double x = 1.0, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_6) {
  double x = 1.0, y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_7) {
  double x = 1.0, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_8) {
  double x = 1.0, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_9) {
  double x = -1.0, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_10) {
  double x = -1.0, y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_11) {
  double x = -1.0, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_12) {
  double x = -1.0, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_13) {
  double x = S21_INF, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_14) {
  double x = S21_INF, y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_15) {
  double x = S21_INF, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_16) {
  double x = S21_INF, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_17) {
  double x = -S21_INF, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_18) {
  double x = -S21_INF, y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_19) {
  double x = -S21_INF, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_20) {
  double x = -S21_INF, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_21) {
  double x = S21_NAN, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_22) {
  double x = -S21_NAN, y = -S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_23) {
  double x = S21_NAN, y = S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_24) {
  double x = S21_NAN, y = -S21_NAN;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_25) {
  double x = 0.52, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_26) {
  double x = 0.52, y = -S21_INF;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_27) {
  double x = -0.52, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_28) {
  double x = -0.52, y = -S21_INF;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_29) {
  double x = 1.52, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_30) {
  double x = 1.52, y = -S21_INF;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_31) {
  double x = -6.52, y = S21_INF;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_32) {
  double x = -6.52, y = -S21_INF;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_33) {
  double x = 6.52, y = 0.0;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_34) {
  double x = -6.52, y = 0.0;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_35) {
  double x = -6.52, y = 3.5;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_36) {
  double x = -6.52, y = -3.5;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_nan(s21_pow(x, y));
  ck_assert_ldouble_nan(pow(x, y));
}
END_TEST

START_TEST(pow_37) {
  double x = -6.52, y = 3.;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_38) {
  double x = -6.52, y = -3.;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_39) {
  double x = DBL_MIN, y = 1000;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_40) {
  double x = DBL_MIN, y = -1000;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_41) {
  double x = DBL_MAX, y = 10;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_42) {
  double x = DBL_MAX, y = -10;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_43) {
  double x = S21_INF, y = 0.0;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_44) {
  double x = -S21_INF, y = 0.0;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_45) {
  double x = S21_NAN, y = 0.0;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_46) {
  double x = -S21_NAN, y = 0.0;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST
START_TEST(pow_47) {
  double x = 1.0, y = 0.0;
  // printf("0 && 0 - %.40Lf\n0 && 0 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_48) {
  double x = -1.0, y = 0.0;
  // printf("0 && 15 - %.40Lf\n0 && 15 - %.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_49) {
  double x = 1.0001, y = DBL_MAX;
  // printf("%.40Lf\n%.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq(s21_pow(x, y), pow(x, y));
}
END_TEST

START_TEST(pow_50) {
  double x = 0.9999, y = DBL_MAX;
  // printf("%.40Lf\n%.40lf\n", s21_pow(x, y), pow(x, y));
  ck_assert_ldouble_eq_tol(s21_pow(x, y), pow(x, y), 1e-6);
}
END_TEST

START_TEST(pow_51) {
  double x = 3., y = -100;
  long double res1 = 0, res2 = 0;
  for (; y < 34; y++) {
    res1 = s21_pow(x, y);
    res2 = pow(x, y);
    // printf("%.3lf && %.0lf\n%.40Lf\n%.40Lf\n", x, y, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

START_TEST(pow_52) {
  double x = -123.123, y = 3.;
  long double res1 = 0, res2 = 0;
  for (; x < 124; x++) {
    res1 = s21_pow(x, y);
    res2 = pow(x, y);
    // printf("%lf && %lf\n%.40Lf\n%.40Lf\n", x2, y2, res1, res2);
    ck_assert_ldouble_eq_tol(res1, res2, 1e-6);
  }
}
END_TEST

Suite *test_pow(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_POW=-\033[0m");
  TCase *tc = tcase_create("pow_tc");

  tcase_add_test(tc, pow_1);
  tcase_add_test(tc, pow_2);
  tcase_add_test(tc, pow_3);
  tcase_add_test(tc, pow_4);
  tcase_add_test(tc, pow_5);
  tcase_add_test(tc, pow_6);
  tcase_add_test(tc, pow_7);
  tcase_add_test(tc, pow_8);
  tcase_add_test(tc, pow_9);
  tcase_add_test(tc, pow_10);
  tcase_add_test(tc, pow_11);
  tcase_add_test(tc, pow_12);
  tcase_add_test(tc, pow_13);
  tcase_add_test(tc, pow_14);
  tcase_add_test(tc, pow_15);
  tcase_add_test(tc, pow_16);
  tcase_add_test(tc, pow_17);
  tcase_add_test(tc, pow_18);
  tcase_add_test(tc, pow_19);
  tcase_add_test(tc, pow_20);
  tcase_add_test(tc, pow_21);
  tcase_add_test(tc, pow_22);
  tcase_add_test(tc, pow_23);
  tcase_add_test(tc, pow_24);
  tcase_add_test(tc, pow_25);
  tcase_add_test(tc, pow_26);
  tcase_add_test(tc, pow_27);
  tcase_add_test(tc, pow_28);
  tcase_add_test(tc, pow_29);
  tcase_add_test(tc, pow_30);
  tcase_add_test(tc, pow_31);
  tcase_add_test(tc, pow_32);
  tcase_add_test(tc, pow_33);
  tcase_add_test(tc, pow_34);
  tcase_add_test(tc, pow_35);
  tcase_add_test(tc, pow_36);
  tcase_add_test(tc, pow_37);
  tcase_add_test(tc, pow_38);
  tcase_add_test(tc, pow_39);
  tcase_add_test(tc, pow_40);
  tcase_add_test(tc, pow_41);
  tcase_add_test(tc, pow_42);
  tcase_add_test(tc, pow_43);
  tcase_add_test(tc, pow_44);
  tcase_add_test(tc, pow_45);
  tcase_add_test(tc, pow_46);
  tcase_add_test(tc, pow_47);
  tcase_add_test(tc, pow_48);
  tcase_add_test(tc, pow_49);
  tcase_add_test(tc, pow_50);
  tcase_add_test(tc, pow_51);
  tcase_add_test(tc, pow_52);

  suite_add_tcase(s, tc);
  return s;
}
