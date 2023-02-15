#include "s21_math.h"

long double s21_atan(double x) {
  long double result = x;
  if (s21_isnan(x) || x == 0) {
    result = x;
  } else if (s21_isinf(x)) {
    x > 0 ? result = PI_2 : (result = -PI_2);
  } else if (s21_fabs(x) < 0.9) {
    long double e = x;
    for (int i = 3; i < 1000; i += 2) {
      e *= (x * x * -1);
      result += e / i;
    }
  } else {
    int sign = 1;
    long double temp = 0;
    s21_fabs(x) == 1 ? temp = SQRT1_2 : (temp = 1 / s21_sqrt(1 + x * x));
    if (x < 0) sign = -1;
    result = sign * s21_acos(temp);
  }
  return result;
}
