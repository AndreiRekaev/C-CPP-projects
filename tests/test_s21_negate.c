#include "main.h"

Suite *test_negate(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_NEGATE=-\033[0m");
  TCase *tc = tcase_create("negate_tc");

  // tcase_add_test(tc, negate_1);

  suite_add_tcase(s, tc);
  return s;
}
