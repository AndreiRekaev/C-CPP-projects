#include "s21_math.h"

long double s21_fabs(double x) {
  unsigned long long temp = *((unsigned long long *)(&x)), mask = 1;
  mask <<= 63;
  if (temp & mask) temp -= (temp & mask);
  return *((double *)(&temp));
  // return (x < 0 || x == -0) ? (x * -1) : x;
}
