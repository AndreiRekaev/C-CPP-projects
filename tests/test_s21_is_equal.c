#include "main.h"

Suite *test_is_equal(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_IS_EQUAL=-\033[0m");
  TCase *tc = tcase_create("is_equal_tc");

  // tcase_add_test(tc, is_equal_1);

  suite_add_tcase(s, tc);
  return s;
}