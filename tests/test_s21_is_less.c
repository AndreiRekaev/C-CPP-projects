#include "main.h"

Suite *test_is_less(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_IS_LESS=-\033[0m");
  TCase *tc = tcase_create("is_less_tc");

  // tcase_add_test(tc, is_less_1);

  suite_add_tcase(s, tc);
  return s;
}
