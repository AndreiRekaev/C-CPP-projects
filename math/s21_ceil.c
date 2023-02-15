#include "s21_math.h"

long double s21_ceil(double x) {
  long double result = 0;

  if (s21_isnan(x) || x == 0 || s21_isinf(x)) {
    result = x;
  } else {
    long double y = x - s21_fmod(x, 1);
    s21_fmod(x, 1) > 0 ? (result = y + 1) : (result = y);
  }

  return result;
}
