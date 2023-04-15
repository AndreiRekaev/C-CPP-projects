#ifndef SRC_TEST_H_
#define SRC_TEST_H_

#include <check.h>
#include <stdio.h>
#include <time.h>

#include "../s21_matrix.h"

Suite *st_s21_create_matrix(void);
Suite *st_s21_eq_matrix(void);
Suite *st_s21_sum_matrix(void);
Suite *st_s21_sub_matrix(void);
Suite *st_s21_mult_number(void);
Suite *st_s21_mult_matrix(void);
Suite *st_s21_transpose(void);
Suite *st_s21_calc_complements(void);
Suite *st_s21_determinant(void);
Suite *st_s21_inverse_matrix(void);

#endif  // SRC_TEST_H_