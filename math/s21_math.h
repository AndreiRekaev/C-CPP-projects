#ifndef _SRC_MATH_H_
#define _SRC_MATH_H_

#include <float.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_MINF (-1.0 / 0.0)
#define S21_INF (1.0 / 0.0)
#define S21_NAN (0.0 / 0.0)
#define E 2.71828182845904523536
#define PI 3.14159265358979323846
#define PI_2 1.57079632679489661923
#define PI_4 0.785398163397448309616
#define LN2 0.693147180559945309417
#define LN10 2.30258509299404568402L
#define SQRT2 1.41421356237309504880
#define SQRT1_2 0.707106781186547524401
#define MAX 16331239353195370.0L
#define S21_EPS 1e-06

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(double x);
long double s21_atan(double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_nod(long double x, long double y);
int s21_isinf(double x);
int s21_isnan(double x);
#endif  // _SRC_MATH_H_
