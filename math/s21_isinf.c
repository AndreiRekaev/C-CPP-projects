#include "s21_math.h"

int s21_isinf(double x) { return (x == 1.0 / 0.0 || x == -1.0 / 0.0) ? 1 : 0; }
