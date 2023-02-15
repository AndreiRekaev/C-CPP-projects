#include "s21_math.h"

long double s21_sqrt(double x) {
  long double result = 1;
  if (s21_isnan(x) || x < 0) {
    result = S21_NAN;
  } else if (x == S21_INF || x == 0 || x == 1) {
    result = x;
  } else {  // арифметическая оценка и вавилонски метод(или Герона)
    long double table[10] = {2.5,  6.5,  12.5, 20.5, 30.5,
                             42.5, 56.5, 72.5, 90.5, 100.0};
    int e = 0;
    result = x;
    for (; result / 100 >= 1; result /= 100, e++) {
    }
    for (int k = 0; k < 10; k++) {
      if (result <= table[k]) {
        result = k + 1;
        k = 10;
      }
    }
    for (; e > 0; e--) result *= 10;
    for (register int i = 0; i < 100; i++) {
      result = 0.5 * (result + x / result);
    }
  }
  return result;
}
