#include "main.h"

Suite *test_from_decimal_to_int(void) {
  Suite *s =
      suite_create("\033[5m\033[1;31m\033[47m-=S21_DECIMAL->INT=-\033[0m");
  TCase *tc = tcase_create("from_decimal_to_int_tc");

  // tcase_add_test(tc, from_decimal_to_int_1);

  suite_add_tcase(s, tc);
  return s;
}
