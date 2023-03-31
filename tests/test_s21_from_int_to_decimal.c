#include "main.h"

START_TEST(from_int_to_decimal_1) {
  s21_decimal x = {0};
  int y = 15;
  int result = s21_from_int_to_decimal(y, &x);
  printf("%d\n%d\n", result, x.bits[0]);
  ck_assert_int_eq(x.bits[0], y);
}
END_TEST

Suite *test_from_int_to_decimal(void) {
  Suite *s =
      suite_create("\033[5m\033[1;31m\033[47m-=S21_INT->DECIMAL=-\033[0m");
  TCase *tc = tcase_create("from_int_to_decimal_tc");

  tcase_add_test(tc, from_int_to_decimal_1);

  suite_add_tcase(s, tc);
  return s;
}
