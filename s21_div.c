#include "s21_decimal.h"

int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result) {
  int res = 0;

  if (!result || s21_correct(value_1) || s21_correct(value_2)) {
    res = 4;
  } else if (!s21_is_zero(value_2)) {
    res = 3;
  } else if (!s21_is_zero(value_1)) {
    s21_initdec(result);
  } else {
    if (result) s21_initdec(result);
    int exp_1 = s21_get_exp(value_1), exp_2 = s21_get_exp(value_2), rest = 0;
    int sign_1 = s21_get_sign(value_1), sign_2 = s21_get_sign(value_2);
    s21_bdcm val_1 = {0}, val_2 = {0}, r = {0};
    s21_from_dec_to_bigdec(&val_1, value_1);
    s21_from_dec_to_bigdec(&val_2, value_2);

    if (exp_1 >= exp_2) {
      exp_1 -= exp_2;
      exp_2 = 0;
    } else if (exp_2 > exp_1) {
      s21_eq_big(exp_2 - exp_1, &val_1);
      exp_1 = 0;
      exp_2 -= exp_1;
    }
    s21_dir_div(&val_1, &val_2, &r, &exp_1);
    if (s21_lastbit(&r) < 96) {
      for (int i = 0; i < 3; i++) result->bits[i] = r.bits[i];
      s21_set_exp(exp_1, result);
      if (sign_1 != sign_2) s21_negate(*result, result);
    } else {
      (sign_1 == sign_2) ? (res = 1) : (res = 2);
    }
  }
  return res;
}

void s21_dir_div(s21_bdcm *val_1, s21_bdcm *val_2, s21_bdcm *r, int *exp) {
  s21_bdcm temp = {0}, temp_r = {0};
  int flag = 0;
  for (int br = 0; *exp <= 29 && !br;) {
    for (int i = s21_lastbit(val_1); i >= 0; i--) {
      s21_shift_big(1, &temp);
      if (val_1->bits[i / 32] & 1 << (i % 32)) temp.bits[0] += 1;
      if (s21_less_or_eq_big(*val_2, temp)) {
        s21_min(temp, *val_2, &temp);
        temp_r.bits[0] += 1;
      }
      if (i) s21_shift_big(1, &temp_r);
    }
    s21_sum_big(r, temp_r);
    s21_initbigdec(&temp_r);
    if (!s21_is_zero_big(temp) || s21_lastbit(r) > 212) {
      br = 1;
    } else {
      if (*exp == 29 && s21_is_zero_big(temp)) flag = 1;
      if (*exp != 29) {
        s21_copy_big(val_1, temp);
        s21_eq_big(1, val_1);
        s21_eq_big(1, r);
        s21_initbigdec(&temp);
        (*exp)++;
      } else {
        br = 1;
      }
    }
  }
  int rest = 0;
  for (; *exp > 28 || (s21_lastbit(r) > 95 && *exp > 0);) {
    rest = s21_cut_10_big(r);
    (*exp)--;
  }
  // banking rounding
  if (s21_over(r) && *exp > 0 &&
      (rest > 5 || (rest == 5 && (flag || s21_is_end_big(*r) % 2)))) {
    if (!(flag) && rest) flag = 1;
    rest = s21_cut_10_big(r);
    (*exp)--;
  }
  if (rest > 5 || (rest == 5 && (flag || s21_is_end_big(*r) % 2))) {
    s21_bdcm a = {{1, 0}};
    s21_sum_big(r, a);
  }
}
