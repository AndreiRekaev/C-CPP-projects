#include "s21_math.h"

long double s21_floor(double x) {
  long double result = 0;
  if (s21_isnan(x) || s21_isinf(x) || x == 0) {
    result = x;
  } else {
    unsigned long long temp = *((unsigned long long *)(&x)), mask = 1;
    int sign = 1, e = 1, sum = -1023;
    mask <<= 52;
    if (x < 0) sign = -1;

    for (int i = 0; i < 11; i++) {
      if (temp & mask) sum += e;
      e *= 2;
      mask <<= 1;
    }
    mask = 1;
    if (sum >= 52) {
      result = x;
    } else if (sum < 0) {
      sign == -1 ? (result = -1) : (result = 0);
    } else {
      int flag = 0;
      for (int k = 52; k > sum; k--) {
        if (temp & mask) {
          temp -= (temp & mask);
          flag = 1;
        }
        mask <<= 1;
      }
      result = *((double *)(&temp));
      if (flag && sign == -1) result += sign;
    }
  }
  return result;
}
