#ifndef SRC_CAT_S21_CAT_H_
#define SRC_CAT_S21_CAT_H_

#include <getopt.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct flag {
  int b;
  int e;
  int n;
  int s;
  int t;
  int v;
} s21_flags;

int parser(int argc, char *argv[], s21_flags *flag);
int reader(char *argv[], s21_flags *flag);

#endif  // SRC_CAT_S21_CAT_H_