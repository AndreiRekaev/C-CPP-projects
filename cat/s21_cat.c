# My cat utility educational version program

#include "./s21_cat.h"

int main(int argc, char *argv[]) {
  int error = 0;
  s21_flags flag = {0};
  error = parser(argc, argv, &flag);
  if (error != 1) {
    if (flag.b) flag.n = 0;
    while (optind < argc) {
      if ((error = reader(argv, &flag)) == 2)
        fprintf(stderr, "%s: %s: %s\n", argv[0], argv[optind], strerror(error));
      optind++;
    }
  }
  return error;
}

int parser(int argc, char *argv[], s21_flags *flag) {
  int opt = 0;
  int opt_index = 0;
  int error = 0;

  static struct option long_option[] = {
      {"number-nonblank", no_argument, NULL, 'b'},
      {"number", no_argument, NULL, 'n'},
      {"squeeze-blank", no_argument, NULL, 's'},
      {NULL, 0, NULL, 0}};

  while ((opt = getopt_long(argc, argv, "+benstvTE", long_option,
                            &opt_index)) != -1) {
    switch (opt) {
      case 'E':
        flag->e = 1;
        break;
      case 'b':
        flag->b = 1;
        break;
      case 'e': {
        flag->e = 1;
        flag->v = 1;
        break;
      }
      case 'T':
        flag->t = 1;
        break;
      case 'n':
        flag->n = 1;
        break;
      case 's':
        flag->s = 1;
        break;
      case 't': {
        flag->t = 1;
        flag->v = 1;
        break;
      }
      case 'v':
        flag->v = 1;
        break;
      default: {
        fprintf(stderr, "usage flags -benstvTE");
        error = 1;
        break;
      }
    }
  }
  return error;
}

int reader(char *argv[], s21_flags *flag) {
  int error = 0;
  FILE *file = fopen(argv[optind], "r");
  if (file != NULL) {
    int current_symbol = 0;
    int empty_str_cnt = 0;
    int str_cnt = 0;
    int next_symbol = '\n';

    while ((current_symbol = fgetc(file)) != EOF) {
      if (flag->s && current_symbol == '\n' && next_symbol == '\n') {
        empty_str_cnt++;
        if (empty_str_cnt > 1) continue;
      } else {
        empty_str_cnt = 0;
      }

      if (next_symbol == '\n' &&
          ((flag->b && current_symbol != '\n') || flag->n)) {
        str_cnt++;
        printf("%6d\t", str_cnt);
      }

      if (flag->e && current_symbol == '\n') {
        printf("$");
      }

      if (flag->t && current_symbol == '\t') {
        printf("^I");
      } else if (current_symbol < 32 && flag->v && current_symbol != 9 &&
                 current_symbol != 10) {
        printf("^%c", current_symbol + 64);
      } else if (current_symbol == 127 && flag->v) {
        printf("^?");
      } else {
        printf("%c", current_symbol);
      }
      next_symbol = current_symbol;
    }
    fclose(file);
  } else {
    error = 2;
  }
  return error;
}
