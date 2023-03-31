#include "main.h"

Suite *test_sub(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_SUB=-\033[0m");
  TCase *tc = tcase_create("sub_tc");

  // tcase_add_test(tc, sub_1);

  suite_add_tcase(s, tc);
  return s;
}
