#ifndef _SRC_DECIMAL_H_
#define _SRC_DECIMAL_H_

#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 79228162514264337593543950335.L

/*
bits[0], bits[1], and bits[2] contain the low, middle, and high 32 bits of the
96-bit integer number accordingly. bits[3] contains the scale factor and sign,
and consists of following parts:

Bits 0 to 15, the lower word, are unused and must be zero.
Bits 16 to 23 must contain an exponent between 0 and 28, which indicates the
power of 10 to divide the integer number. Bits 24 to 30 are unused and must be
zero. Bit 31 contains the sign; 0 meaning positive, and 1 meaning negative.
 */

typedef struct {
  int bits[4];
} s21_decimal;

// big decimal is useful for arithmetic operations
// when we can get overflow 96 bits
typedef struct {
  int bits[8];
} s21_bdcm;

int s21_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mul(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_div(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_mod(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
int s21_is_less(s21_decimal num1, s21_decimal num2);
int s21_is_less_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_greater(s21_decimal num1, s21_decimal num2);
int s21_is_greater_or_equal(s21_decimal num1, s21_decimal num2);
int s21_is_equal(s21_decimal num1, s21_decimal num2);
int s21_is_not_equal(s21_decimal num1, s21_decimal num2);
int s21_from_int_to_decimal(int src, s21_decimal *dst);
int s21_from_float_to_decimal(float src, s21_decimal *dst);
int s21_from_decimal_to_int(s21_decimal src, int *dst);
int s21_from_decimal_to_float(s21_decimal src, float *dst);
int s21_floor(s21_decimal value, s21_decimal *result);
int s21_round(s21_decimal value, s21_decimal *result);
int s21_truncate(s21_decimal value, s21_decimal *result);
int s21_negate(s21_decimal value, s21_decimal *result);

/*
  Helper functions for bit manipulation
*/
int s21_get_sign(s21_decimal num);
int s21_get_bit(unsigned int value, int BitNumber);
void s21_set_sign(s21_decimal *dst);
int s21_dir_add(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_dir_mul(s21_bdcm val_1, s21_bdcm val_2, s21_bdcm *r, int *);
int s21_sub_helper(s21_decimal value_1, s21_decimal value_2,
                   s21_decimal *result);
void s21_dir_sub(s21_decimal value_1, s21_decimal value_2, s21_decimal *result);
void s21_dir_div(s21_bdcm *val_1, s21_bdcm *val_2, s21_bdcm *r, int *exp);
void s21_dir_mod(s21_bdcm *value_1, s21_bdcm *value_2);
int s21_correct(s21_decimal x);
int s21_get_exp(s21_decimal x);
void s21_initdec(s21_decimal *dst);
void s21_initbigdec(s21_bdcm *dst);
int s21_is_zero(s21_decimal x);
int s21_is_zero_big(s21_bdcm x);
void s21_copy(s21_decimal *dst, s21_decimal src);
void s21_copy_big(s21_bdcm *dst, s21_bdcm src);
int s21_equalize(int *exp_1, int *exp_2, s21_decimal *value_1,
                 s21_decimal *value_2, int *f);
int s21_eq_big(int e, s21_bdcm *x);
int s21_is_end(s21_decimal x);
int s21_is_end_big(s21_bdcm x);
int s21_cut_10(s21_decimal *x);
int s21_cut_10s(s21_decimal *x, int start);
int s21_cut_10_big(s21_bdcm *x);
int s21_cut_2_big(s21_bdcm *x);
int s21_offset(int e, s21_decimal *dst);
void s21_set_exp(int e, s21_decimal *dst);
int s21_from_dec_to_bigdec(s21_bdcm *dst, s21_decimal src);
void s21_shift_big(int e, s21_bdcm *dst);
void s21_set_exp(int e, s21_decimal *dst);
int s21_from_dec_to_bigdec(s21_bdcm *dst, s21_decimal src);
int s21_less(s21_bdcm v_1, s21_bdcm v_2);
int s21_equal_big(s21_bdcm v_1, s21_bdcm v_2);
int s21_less_or_eq_big(s21_bdcm v_1, s21_bdcm v_2);
int s21_lastbit(s21_bdcm *x);
void s21_min(s21_bdcm value_1, s21_bdcm value_2, s21_bdcm *result);
void s21_sum_big(s21_bdcm *dst, s21_bdcm temp);
int s21_over(s21_bdcm *x);
int s21_sum(int e, s21_decimal *dst);
int s21_is_big(float x);

/*
  Print functions of decimal
*/
void pr(s21_bdcm r);
void print_d(s21_decimal x);
void print_bits(s21_decimal r);

#endif  // _SRC_DECIMAL_H_
