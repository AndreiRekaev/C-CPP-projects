#include "s21_decimal.h"

int s21_is_equal(s21_decimal num1, s21_decimal num2) {
  int result = 1;
  int ex = s21_get_exp(num1), ey = s21_get_exp(num2);
  if (s21_correct(num1) || s21_correct(num2)) {
    result = 0;
  } else if (!s21_is_zero(num1) && !s21_is_zero(num2)) {
    result = 1;
  } else if (ex == ey) {
    int mask = 1;
    for (int i = 0; i < 128 && result; i++) {
      if (i != 127) {
        if ((num1.bits[i / 32] & mask << i % 32) !=
            (num2.bits[i / 32] & mask << i % 32))
          result = 0;
      } else {
        if (s21_get_sign(num1) != s21_get_sign(num2)) result = 0;
      }
    }
  } else {
    result = 0;
    if (ex < ey) {
      if (!(s21_offset(ey - ex, &num1)) && !(s21_sum(ey - ex, &num1))) {
        s21_set_exp(ey, &num1);
        result = s21_is_equal(num1, num2);
      }
    } else {
      if (!(s21_offset(ex - ey, &num2)) && !(s21_sum(ex - ey, &num2))) {
        s21_set_exp(ex, &num2);
        result = s21_is_equal(num1, num2);
      }
    }
  }
  return result;
}
