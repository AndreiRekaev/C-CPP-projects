#include "main.h"

Suite *test_from_float_to_decimal(void) {
  Suite *s =
      suite_create("\033[5m\033[1;31m\033[47m-=S21_FLOAT->DECIMAL=-\033[0m");
  TCase *tc = tcase_create("from_float_to_decimal_tc");

  // tcase_add_test(tc, from_float_to_decimal_1);

  suite_add_tcase(s, tc);
  return s;
}
