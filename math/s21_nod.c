#include "s21_math.h"

long double s21_nod(long double x, long double y) {
  long double temp = 0, result = 0;

  while (!result) {
    if (s21_fmod(x, y) == 0) {
      result = y;
    } else {
      temp = s21_fmod(x, y);
      x = y;
      y = temp;
    }
  }
  return result;
}
