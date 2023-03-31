#include "s21_decimal.h"

int s21_get_sign(s21_decimal num) { return (num.bits[3] & (1 << 31)) ? -1 : 1; }

int s21_get_bit(unsigned int value, int BitNumber) {
  return value & (1 << BitNumber);
}

void s21_set_bit(unsigned int *value, int BitNumber, int BitValue) {
  *value =
      BitValue ? (*value | (1 << BitNumber)) : (*value & ~(1 << BitNumber));
}

void s21_set_sign(s21_decimal *dst) {
  if (!(dst->bits[3] & 1 << 31)) dst->bits[3] += (1 << 31);
}

// validation decimal num
int s21_correct(s21_decimal x) {
  int result = 0, mask = 1;
  for (int i = 0; i < 32 && !result; i++) {
    if ((i >= 0 && i < 16) || (i >= 24 && i < 31)) {
      if (x.bits[3] & mask << i) result = 1;
    }
  }
  int m = s21_get_exp(x);
  if (!(m >= 0 && m <= 28)) result = 1;
  return result;
}

// get exponent of decimal (exp = 0... 28)
int s21_get_exp(s21_decimal x) {
  int result = 0, mask = 1 << 16, e = 1;
  for (int i = 0; i < 8; i++, e *= 2) {
    if (x.bits[3] & mask << i) result += e;
  }
  return result;
}

void s21_initdec(s21_decimal *dst) {
  for (int i = 0; i < 4; i++) dst->bits[i] = 0;
}

void s21_initbigdec(s21_bdcm *dst) {
  for (int i = 0; i < 8; i++) dst->bits[i] = 0;
}

// validate decimal num on zero
int s21_is_zero(s21_decimal x) {
  int result = 0, mask = 1;
  for (int i = 0; i < 96 && !result; i++) {
    if (x.bits[i / 32] & mask << (i % 32)) result = 1;
  }
  return result;
}

int s21_is_zero_big(s21_bdcm x) {
  int result = 0, mask = 1;
  for (int i = 0; i < 214 && !result; i++) {
    if (x.bits[i / 32] & mask << (i % 32)) result = 1;
  }
  return result;
}

// copy src to dest
void s21_copy(s21_decimal *dst, s21_decimal src) {
  for (int i = 0; i < 4; i++) {
    dst->bits[i] = src.bits[i];
  }
}

void s21_copy_big(s21_bdcm *dst, s21_bdcm src) {
  for (int i = 0; i < 8; i++) {
    dst->bits[i] = src.bits[i];
  }
}

// equalize exponents of two decimals
int s21_equalize(int *exp_1, int *exp_2, s21_decimal *value_1,
                 s21_decimal *value_2, int *f) {
  int result = 0;
  int flag = 0;
  for (; *exp_1 > *exp_2 && !s21_is_end(*value_1); (*exp_1)--)
    s21_cut_10(value_1);
  s21_decimal temp = {0};
  s21_copy(&temp, *value_2);
  for (; *exp_2 < *exp_1 && !s21_offset(1, &temp) && !s21_sum(1, &temp);
       (*exp_2)++)
    s21_copy(value_2, temp);
  for (; *exp_1 > *exp_2; (*exp_1)--) {
    result = s21_cut_10(value_1);
    if (result && *exp_1 - 1 > *exp_2) flag = 1;
    if (result) *f = 1;
  }
  return result == 5 ? (result + flag) : result;
}

int s21_eq_big(int e, s21_bdcm *x) {
  s21_bdcm temp = {0};
  s21_shift_big(e, x);
  for (int i = 0; i < e; i++) {
    s21_copy_big(&temp, *x);
    s21_shift_big(2, x);
    s21_sum_big(x, temp);
  }
}

int s21_sum(int e, s21_decimal *dst) {
  int mask = 1, result = 0, depot = 0;
  s21_decimal temp = {0};
  for (; e > 0 && !result; e--) {
    s21_copy(&temp, *dst);
    result = s21_offset(2, &temp);
    for (int i = 0; i < 96 && !result; i++) {
      if (dst->bits[i / 32] & (mask << (i % 32))) depot++;
      if (temp.bits[i / 32] & (mask << (i % 32))) depot++;
      if (depot == 1) {
        if (!(dst->bits[i / 32] & (mask << (i % 32)))) {
          dst->bits[i / 32] += (mask << (i % 32));
        }
        depot = 0;
      } else if (depot == 2) {
        if (dst->bits[i / 32] & (mask << (i % 32))) {
          dst->bits[i / 32] -= (mask << (i % 32));
        }
        depot = 1;
      } else if (depot == 3) {
        depot = 1;
      }
    }
    if (depot) result = 1;
  }
  return result;
}

// summary two big decimals
void s21_sum_big(s21_bdcm *dst, s21_bdcm temp) {
  int depot = 0;
  for (int i = 0; i < 213; i++) {
    if (dst->bits[i / 32] & (1 << (i % 32))) depot++;
    if (temp.bits[i / 32] & (1 << (i % 32))) depot++;
    if (depot == 1) {
      if (!(dst->bits[i / 32] & (1 << (i % 32))))
        dst->bits[i / 32] += 1 << (i % 32);
      depot = 0;
    } else if (depot == 2) {
      if (dst->bits[i / 32] & (1 << (i % 32)))
        dst->bits[i / 32] -= 1 << (i % 32);
      depot = 1;
    } else if (depot == 3) {
      depot = 1;
    }
  }
}

// check overflow when all bits in 1 position
int s21_over(s21_bdcm *x) {
  int res = 1;
  for (int i = 95; i >= 0 && res; i--) {
    if (!(x->bits[i / 32] & 1 << (i % 32))) res = 0;
  }
  return res;
}

// last digits of decimal
int s21_is_end(s21_decimal x) {
  int result = 0;
  for (int i = 0; i < 96; i++) {
    if (x.bits[i / 32] & 1 << (i % 32)) {
      if (i == 0)
        result += 1;
      else if (i % 4 == 1)
        result += 2;
      else if (i % 4 == 2)
        result += 4;
      else if (i % 4 == 3)
        result += 8;
      else if (i % 4 == 0)
        result += 6;
    }
  }
  return result % 10;
}

// last digits of big decimal
int s21_is_end_big(s21_bdcm x) {
  int result = 0;
  for (int i = 0; i < 214; i++) {
    if (x.bits[i / 32] & 1 << (i % 32)) {
      if (i == 0)
        result += 1;
      else if (i % 4 == 1)
        result += 2;
      else if (i % 4 == 2)
        result += 4;
      else if (i % 4 == 3)
        result += 8;
      else if (i % 4 == 0)
        result += 6;
    }
  }
  return result % 10;
}

int s21_is_big(float x) {
  int result = 0, temp = *((int *)(&x)), mask = 1, sum = -127;
  mask <<= 23;
  for (int i = 0, e = 1; i < 8; i++, e *= 2) {
    if (temp & mask) sum += e;
    mask <<= 1;
  }
  if (sum >= 96) result = 1;
  return result;
}

// divide decimal on 10
int s21_cut_10(s21_decimal *x) {
  int result = -1;
  if (x && !s21_correct(*x)) {
    int temp = 0, mask = 10;
    s21_decimal y = {0};
    for (int i = 95; i >= 0; i--) {
      temp <<= 1;
      if (x->bits[i / 32] & 1 << i % 32) temp += 1;
      s21_offset(1, &y);
      if (temp >= mask) {
        temp -= mask;
        y.bits[0] += 1;
      }
    }
    s21_set_exp(s21_get_exp(*x) - 1, &y);
    if (s21_get_sign(*x) == -1) s21_set_sign(&y);
    s21_copy(x, y);
    result = temp;
  }
  return result;
}

// divide big decimal on 10
int s21_cut_10_big(s21_bdcm *x) {
  int result = -1;
  if (x) {
    int temp = 0, mask = 10;
    s21_bdcm y = {0};
    for (int i = 213; i >= 0; i--) {
      temp <<= 1;
      if (x->bits[i / 32] & 1 << i % 32) temp += 1;
      s21_shift_big(1, &y);
      if (temp >= mask) {
        temp -= mask;
        y.bits[0] += 1;
      }
    }
    s21_copy_big(x, y);
    result = temp;
  }
  return result;
}

int s21_cut_10s(s21_decimal *x, int start) {
  int result = -1;
  if (x && !s21_correct(*x)) {
    int temp = start, mask = 10;
    s21_decimal y = {0};
    for (int i = 95; i >= 0; i--) {
      temp <<= 1;
      if (x->bits[i / 32] & 1 << i % 32) temp += 1;
      s21_offset(1, &y);
      if (temp >= mask) {
        temp -= mask;
        y.bits[0] += 1;
      }
    }
    s21_set_exp(s21_get_exp(*x) - 1, &y);
    if (s21_get_sign(*x) == -1) s21_set_sign(&y);
    s21_copy(x, y);
    result = temp;
  }
  return result;
}

// shift decimal on e steps
int s21_offset(int e, s21_decimal *dst) {
  int mask = 1, total = 95, start = 95, result = 0, i = 0;
  for (; !(dst->bits[start / 32] & mask << start % 32) && start > 0;) start--;
  if (start + e <= total) {
    for (i = total; i >= 0; i--) {
      if (dst->bits[i / 32] & mask << i % 32) {
        if (dst->bits[(i + e) / 32] & mask << (i + e) % 32) {
        } else {
          dst->bits[(i + e) / 32] += (mask << (i + e) % 32);
        }
      } else if (dst->bits[(i + e) / 32] & mask << (i + e) % 32) {
        dst->bits[(i + e) / 32] -= (mask << (i + e) % 32);
      }
    }
    for (int k = 0; k < e; k++) {
      dst->bits[k / 32] -= (dst->bits[k / 32] & mask << k % 32);
    }
  } else {
    result = 1;
  }
  return result;
}

void s21_shift_big(int e, s21_bdcm *dst) {
  int start = 213;
  for (; !(dst->bits[start / 32] & 1 << (start % 32)) && start > 0;) start--;
  for (int i = start; i >= 0; i--) {
    int k = i + e;
    if (dst->bits[i / 32] & 1 << (i % 32)) {
      if (!(dst->bits[k / 32] & 1 << (k % 32)))
        dst->bits[k / 32] += (1 << (k % 32));
    } else {
      if (dst->bits[k / 32] & (1 << (k % 32)))
        dst->bits[k / 32] -= (1 << (k % 32));
    }
  }
  for (int m = 0; m < e; m++) {
    dst->bits[m / 32] -= 1 << (m % 32);
  }
}

// set exponent
void s21_set_exp(int e, s21_decimal *dst) {
  int mask = 1;
  for (int i = 0; i < 8; i++) {
    if (e & mask << i) {
      if (!(dst->bits[3] & mask << (16 + i))) dst->bits[3] += mask << (16 + i);
    } else {
      if (dst->bits[3] & mask << (16 + i)) dst->bits[3] -= (mask << (16 + i));
    }
  }
}

int s21_from_dec_to_bigdec(s21_bdcm *dst, s21_decimal src) {
  int res = 0;
  if (dst) {
    for (int i = 0; i < 8; i++) {
      if (i < 3)
        dst->bits[i] = src.bits[i];
      else
        dst->bits[i] = 0;
    }
  } else {
    res = 1;  // error
  }
  return res;
}

int s21_less(s21_bdcm v_1, s21_bdcm v_2) {
  int result = 0;

  for (int i = 213; i >= 0 && !result; i--) {
    int sum = 0;
    if (v_1.bits[i / 32] & 1 << (i % 32)) sum += 1;
    if (v_2.bits[i / 32] & 1 << (i % 32)) sum -= 1;
    if (sum == 1) i = 0;
    if (sum == -1) result = 1;
  }
  return result;
}

int s21_equal_big(s21_bdcm v_1, s21_bdcm v_2) {
  int result = 1;
  for (int i = 213; i >= 0 && result; i--) {
    int sum = 0;
    if (v_1.bits[i] & 1 << (i % 32)) sum += 1;
    if (v_2.bits[i] & 1 << (i % 32)) sum -= 1;
    if (sum != 0) result = 0;
  }
  return result;
}

int s21_less_or_eq_big(s21_bdcm v_1, s21_bdcm v_2) {
  return (s21_less(v_1, v_2) || s21_equal_big(v_1, v_2)) ? 1 : 0;
}

// take last bit of big decimal
int s21_lastbit(s21_bdcm *x) {
  int res = 0;
  for (int i = 223; i >= 0 && !res; i--) {
    if (x->bits[i / 32] & 1 << (i % 32)) res = i;
  }
  return res;
}

void s21_min(s21_bdcm value_1, s21_bdcm value_2, s21_bdcm *result) {
  int depot = 0, mask = 1, sum = 0;
  for (int i = 213; i >= 0; i--) {
    if (value_1.bits[i / 32] & mask << (i % 32)) sum += 1;
    if (value_2.bits[i / 32] & mask << (i % 32)) sum -= 1;
    if (sum == 1) {
      if (!(result->bits[i / 32] & mask << (i % 32)))
        result->bits[i / 32] += mask << (i % 32);
      sum -= 1;
    } else if (sum == -1) {
      result->bits[depot / 32] -= mask << (depot % 32);
      for (int k = depot - 1; k >= i; k--) {
        result->bits[k / 32] += mask << (k % 32);
      }
      sum += 1;
    } else if (result->bits[i / 32] & mask << (i % 32)) {
      result->bits[i / 32] -= mask << (i % 32);
    }
    if (result->bits[i / 32] & mask << (i % 32)) depot = i;
  }
}

int s21_cut_2_big(s21_bdcm *x) {
  int result = -1;
  if (x) {
    int temp = 0, mask = 2;
    s21_bdcm y = {0};
    for (int i = 213; i >= 0; i--) {
      temp <<= 1;
      if (x->bits[i / 32] & 1 << i % 32) temp += 1;
      s21_shift_big(1, &y);
      if (temp >= mask) {
        temp -= mask;
        y.bits[0] += 1;
      }
    }
    s21_copy_big(x, y);
    result = temp;
  }
  return result;
}
