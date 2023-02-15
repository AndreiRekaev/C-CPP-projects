#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (exp == 0 || base == 1 || (base == -1 && s21_isinf(exp))) {
    result = 1;
  } else if (s21_isnan(exp) || s21_isnan(base)) {
    result = S21_NAN;
  } else if (base == 0) {
    exp < 0 ? (result = S21_INF) : (result = 0);
  } else if (s21_isinf(exp)) {
    if (exp > 0) s21_fabs(base) > 1 ? (result = S21_INF) : (result = 0);
    if (exp < 0) s21_fabs(base) > 1 ? (result = 0) : (result = S21_INF);
  } else if (s21_isinf(base)) {
    exp > 0 ? result = S21_INF : (result = 0);
  } else if ((base < 0 && s21_fmod(exp, 1))) {
    result = S21_NAN;
  } else if ((base < 0 && s21_fmod(exp, 1) == 0) || base >= 0) {
    long double int_st = s21_fabs(exp) - s21_fmod(exp, 1);
    long double temp = s21_exp(s21_fmod(exp, 1) * s21_log(s21_fabs(base)));
    // result = s21_exp(exp * s21_log(s21_fabs(base)));
    if (temp != 0) exp > 0 ? (result *= temp) : (result /= temp);
    // printf("%.20Lf\n%.20Lf\n", result, int_st);
    if (int_st < ULONG_MAX && int_st != 0) {
      temp = base;
      unsigned long long mask = 1, st = int_st;
      for (register int i = 0; i < 63; i++) {
        if (mask & st) {
          exp > 0 ? result *= temp : (result /= temp);
        }
        mask <<= 1;
        temp *= temp;

        if (s21_isinf(result)) {
          result = S21_INF;
          i = 63;
        }
        if (s21_fabs(result) < DBL_MIN) {
          result = 0;
          i = 63;
        }
      }
    } else {
      for (; int_st > 0; int_st--) {
        exp > 0 ? (result *= base) : (result *= 1 / base);
        if (s21_isinf(result)) {
          result = S21_INF;
          int_st = 1;
        }
        if (s21_fabs(result) < DBL_MIN) {
          result = 0;
          int_st = 1;
        }
        // printf("%.20Lf\n%.20Lf\n", result, int_st);
      }
    }
    // int_st = s21_exp(s21_fmod(exp, 1) * s21_log(s21_fabs(base)));
    // printf("%.20Lf\n%.20Lf\n", result, int_st);
    // exp > 0 ? (result *= int_st) : (result /= int_st);
  }
  return result;
}
