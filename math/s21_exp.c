#include "s21_math.h"

long double s21_exp(double x) {
  long double result = 1;

  if (s21_isnan(x)) {
    result = S21_NAN;
  } else if (s21_isinf(x)) {
    x > 0 ? (result = S21_INF) : (result = 0);
  } else if (x == 0) {
    result = 1;
  } else {
    long double fact = 1, del = 1, copy_x = s21_fabs(x);
    for (int i = 1; i < 1000; i++) {
      fact *= i;
      del *= copy_x;
      result += del / fact;
      if (s21_isinf(result)) {
        i = 1000;
        result = S21_INF;
      }
      if (result == 0) i = 1000;
    }
    if (x < 0) result = 1 / result;
  }
  // printf("result - %.40Lf", result);
  return result;
}
