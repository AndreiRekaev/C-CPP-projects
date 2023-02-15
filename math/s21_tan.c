#include "s21_math.h"

long double s21_tan(double x) {
  long double result = x;

  if (s21_isnan(x) || s21_isinf(x)) {
    result = S21_NAN;
  } else if (x == 0) {
    result = x;
  } else if (s21_fmod(s21_fabs(x), PI_2) == 0) {
    x > 0 ? (result = MAX) : (result = -MAX);
  } else {
    long double temp = s21_fmod(x, 2.0l * PI);
    result = s21_sin(temp) / s21_cos(temp);
  }
  return result;
}
