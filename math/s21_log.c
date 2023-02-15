#include "s21_math.h"

long double s21_log(double x) {
  long double result = 0;
  if (x == 0) {
    result = S21_MINF;
  } else if (x < 0 || s21_isnan(x)) {
    result = S21_NAN;
  } else if (x == S21_INF) {
    result = S21_INF;
  } else {
    long double temp = x;
    int p = 0;

    if (temp < 1) {
      for (; temp < 1; p--) {
        temp *= 10;
      }
    } else if (temp > 100) {
      for (; temp > 100; p++) {
        temp /= 10;
      }
    }

    long double del = (temp - 1) / (temp + 1);
    temp = del;
    for (int i = 1; i < 10000; i += 2) {
      result += del / i;
      del *= (temp * temp);
    }
    result = result * 2 + p * LN10;
  }
  return result;
}
