#include "s21_math.h"

long double s21_sin(double x) {
  long double result = 0;
  if (s21_isnan(x) || s21_isinf(x)) {
    result = S21_NAN;
  } else {
    long double e = 1, fact = 1;
    long double temp = s21_fmod(x, 2.0 * PI);
    e = temp, result = temp;
    for (register int i = 1; i < 100; i++) {
      e *= (temp * temp * -1);
      fact *= (2 * i * (2 * i + 1));
      result += e / fact;
    }
  }

  return result;
}
