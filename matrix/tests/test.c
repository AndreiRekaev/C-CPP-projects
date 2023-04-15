#include "test_s21_matrix.h"

int main(void) {
  srand(time(NULL));
  int fails = 0;
  Suite *list[] = {st_s21_create_matrix(),
                   st_s21_eq_matrix(),
                   st_s21_sum_matrix(),
                   st_s21_sub_matrix(),
                   st_s21_mult_matrix(),
                   st_s21_mult_number(),
                   st_s21_transpose(),
                   st_s21_determinant(),
                   st_s21_calc_complements(),
                   st_s21_inverse_matrix(),
                   NULL};
  for (Suite **current_testcase = list; *current_testcase != NULL;
       current_testcase++) {
    SRunner *sr = srunner_create(*current_testcase);
    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);  // CK_VERBOSE - ALL | CK_ENV - ONLY FAILS
    fails += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("====== FAILED: %d ======\n", fails);
  return fails == 0 ? 0 : 1;
}