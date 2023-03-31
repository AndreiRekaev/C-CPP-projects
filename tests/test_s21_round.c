#include "main.h"

Suite *test_round(void) {
  Suite *s = suite_create("\033[5m\033[1;31m\033[47m-=S21_ROUND=-\033[0m");
  TCase *tc = tcase_create("round_tc");

  // tcase_add_test(tc, round_1);

  suite_add_tcase(s, tc);
  return s;
}
