#include "s21_math.h"

long double s21_acos(double x) {
  long double result = x, temp = s21_fmod(x, PI);
  if (s21_isnan(x) || s21_isinf(x) || x < -1 || x > 1) {
    result = S21_NAN;
  } else {
    result = PI_2 - s21_asin(temp);
  }
  return result;
}
