#include "s21_decimal.h"

int s21_from_float_to_decimal(float src, s21_decimal *dst) {
  int result = 0;
  if (dst == NULL) {
    result = 1;
  } else {
    s21_initdec(dst);
    if (fabs(src) > 0 && fabs(src) < 1e-28) {
      s21_initdec(dst);
      result = 1;
    } else if (src == 0) {
      s21_initdec(dst);
    } else if (s21_is_big(src)) {
      result = 1;
    } else {
      double temp = 1, cp = fabs(src);
      int e = 0;
      if (cp >= 10000000) {
        for (; cp > 10000000; e--) cp /= 10;
        if ((fmod(cp, temp) - fmod(cp, temp / 10)) / (temp / 10) >= 5)
          cp += temp;
        cp -= fmod(cp, temp);
      } else {
        for (; cp < 1000000 && e < 28; e++) cp *= 10;
        int i = 0;
        for (; temp * 10 < cp; i++) temp *= 10;
        for (; i > 0; i--) temp /= 10;
        if ((fmod(cp, temp) - fmod(cp, temp / 10)) / (temp / 10) >= 5)
          cp += +temp;
        cp -= fmod(cp, temp);
      }
      for (; fmod(cp, 10) == 0 && e > 0; e--) cp /= 10;
      s21_from_int_to_decimal(cp, dst);
      if (e > 0 && e < 29) {
        s21_set_exp(e, dst);
      } else if (e < 0) {
        s21_offset(-e, dst);
        s21_sum(-e, dst);
      }
      if (src < 0) s21_set_sign(dst);
    }
  }
  return result;
}
