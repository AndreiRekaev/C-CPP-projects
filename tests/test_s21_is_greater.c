#include "main.h"

Suite *test_is_greater(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_IS_GREATER=-\033[0m");
  TCase *tc = tcase_create("is_greater_tc");

  // tcase_add_test(tc, is_greater_1);

  suite_add_tcase(s, tc);
  return s;
}
