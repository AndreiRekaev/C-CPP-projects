#include "s21_decimal.h"

int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;
  int exp_1 = s21_get_exp(value_1), exp_2 = s21_get_exp(value_2);
  int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
  if (sign_2 == -1) s21_negate(value_2, &value_2);
  if (sign_1 == -1) s21_negate(value_1, &value_1);
  if (result) s21_initdec(result);

  if (!result || s21_correct(value_1) || s21_correct(value_2)) {
    res = 4;
  } else if (s21_is_greater(value_2, value_1) && s21_is_zero(value_1)) {
    s21_copy(result, value_1);
    if (sign_1 == -1) s21_negate(*result, result);
  } else if (!s21_is_zero(value_2)) {
    res = 3;
  } else if (s21_is_equal(value_1, value_2) || !s21_is_zero(value_1)) {
    s21_initdec(result);
  } else {
    s21_bdcm val_1 = {0}, val_2 = {0};
    s21_from_dec_to_bigdec(&val_1, value_1);
    s21_from_dec_to_bigdec(&val_2, value_2);
    if (exp_1 > exp_2) {
      s21_eq_big(exp_1 - exp_2, &val_2);
      exp_2 = exp_1;
    } else if (exp_2 > exp_1) {
      s21_eq_big(exp_2 - exp_1, &val_1);
      exp_1 = exp_2;
    }
    s21_dir_mod(&val_1, &val_2);
    for (int i = 0; i < 3; i++) result->bits[i] = val_1.bits[i];
    s21_set_exp(exp_1, result);
    if (sign_1 == -1) s21_negate(*result, result);
  }
  return res;
}

void s21_dir_mod(s21_bdcm *value_1, s21_bdcm *value_2) {
  int step = 0;
  s21_bdcm temp = {0};
  s21_copy_big(&temp, *value_2);
  s21_shift_big(1, &temp);
  for (; s21_less(temp, *value_1); step++) {
    s21_copy_big(value_2, temp);
    s21_shift_big(1, &temp);
  }
  for (; s21_less_or_eq_big(*value_2, *value_1) || step > 0;) {
    if (s21_less_or_eq_big(*value_2, *value_1)) {
      s21_min(*value_1, *value_2, value_1);
    } else if (step > 0) {
      s21_cut_2_big(value_2);
      step--;
    }
  }
}