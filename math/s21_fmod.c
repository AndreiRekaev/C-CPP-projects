#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double result = 0;
  if (s21_isnan(x) || s21_isnan(y) || y == 0 || s21_isinf(x)) {
    result = S21_NAN;
  } else {
    int sign = 1, i = 0;
    long double temp = s21_fabs(y);
    if (x < 0) sign = -1;
    result = s21_fabs(x);

    for (; temp * 2 < result; i++) {
      temp *= 2;
    }
    while ((i > 0 || result - temp >= 0)) {
      if (result - temp >= 0) {
        result -= temp;
      } else if (i > 0) {
        temp /= 2;
        i--;
      }
      // printf("%.40Lf\n%Lf\n", result, temp);
    }
    result *= sign;
  }
  return result;
}
