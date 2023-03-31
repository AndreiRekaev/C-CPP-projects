#include "s21_decimal.h"

void pr(s21_bdcm r) {
  for (int i = 223; i >= 0; i--) {
    printf("%d", (r.bits[i / 32] & 1 << (i % 32)) ? 1 : 0);
    if (i % 8 == 0) printf(" ");
    if (i == 0) printf("\n");
  }
}

void print_bits(s21_decimal r) {
  for (int i = 127; i >= 0; i--) {
    printf("%d", (r.bits[i / 32] & 1 << (i % 32)) ? 1 : 0);
    if (i % 8 == 0) printf(" ");
    if (i == 0) printf("\n");
  }
}

void print_d(s21_decimal x) {
  char res[34] = {0};
  int e = s21_get_exp(x), flag = 0, s = s21_get_sign(x);
  if (e > 0) flag = 1;
  int i = 0;
  for (; i < 32 && (s21_is_zero(x) || e > 0); i++) {
    if (!e) s21_set_exp(1, &x);
    res[i] = s21_cut_10(&x) + 48;
    e = s21_get_exp(x);
    if (flag && e == 0) {
      res[++i] = '.';
      flag = 0;
    }
  }
  if (i) {
    if (res[i - 1] == '.') res[i] = 48;
  } else {
    res[i] = 48;
  }
  if (s == -1) printf("-");
  for (; i >= 0; i--) printf("%c", res[i]);
  printf("\n");
}
