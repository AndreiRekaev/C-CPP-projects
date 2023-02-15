#include "s21_math.h"

long double s21_asin(double x) {
  long double result = x;
  if (s21_isnan(x) || s21_isinf(x) || x < -1 || x > 1) {
    result = S21_NAN;
  } else if (s21_fabs(x) > 0.9) {
    result = PI_2 - s21_asin(s21_sqrt(1 - x * x));
    if (x < 0) result *= -1;
  } else {
    long double up = 1, down = 1, a = x, temp = 1;
    for (register int i = 1; i < 1000; i++) {
      if (s21_fabs(a) > LDBL_MIN) a *= (x * x);
      up *= (2 * i - 1);
      down *= (2 * i);
      result += (up * a / (down * (2 * i + 1)));
      if (i % 10 == 0) {
        temp = s21_nod(down, up);
        up /= temp;
        down /= temp;
      }
    }
  }
  return result;
}
