#include "main.h"

START_TEST(abs_1) {
  int x1 = 0;
  int x2 = 0;
  int res1 = -1, res2 = -1;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_2) {
  int x1 = INT_MIN;
  int x2 = INT_MIN;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_3) {
  int x1 = INT_MAX;
  int x2 = INT_MAX;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_4) {
  int x1 = UINT_MAX;
  int x2 = UINT_MAX;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_5) {
  int x1 = (int)LONG_MIN;
  int x2 = (int)LONG_MIN;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_6) {
  int x1 = (int)LONG_MAX;
  int x2 = (int)LONG_MAX;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_7) {
  int x1 = (int)ULONG_MAX;
  int x2 = (int)ULONG_MAX;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_8) {
  int x1 = -12345;
  int x2 = -12345;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_9) {
  int x1 = 12345;
  int x2 = 12345;
  int res1 = 0, res2 = 0;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

START_TEST(abs_10) {
  int x1 = -0;
  int x2 = -0;
  int res1 = -1, res2 = -1;
  res1 = s21_abs(x1);
  res2 = abs(x2);
  ck_assert_int_eq(res1, res2);
}
END_TEST

Suite *test_abs(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_ABS=-\033[0m");
  TCase *tc = tcase_create("abs_tc");

  tcase_add_test(tc, abs_1);
  tcase_add_test(tc, abs_2);
  tcase_add_test(tc, abs_3);
  tcase_add_test(tc, abs_4);
  tcase_add_test(tc, abs_5);
  tcase_add_test(tc, abs_6);
  tcase_add_test(tc, abs_7);
  tcase_add_test(tc, abs_8);
  tcase_add_test(tc, abs_9);
  tcase_add_test(tc, abs_10);

  suite_add_tcase(s, tc);
  return s;
}
