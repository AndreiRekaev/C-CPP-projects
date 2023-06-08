#include "s21_smartcalc.h"

int parser(char *input, s21_stack **INPUT, long double x_value) {
  int code = 0;
  int count = 0;
  int bracket_unar = 0;
  for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
    if (is_num(input[i]) == 0) {
      char *start_num = &input[i];
      while (is_num(input[i]) == 0) {
        i++;
      }
      char *finish = &input[--i];
      long double num = strtod(start_num, &finish);
      push(INPUT, num, 0, NUMBER);
      count++;
    } else if (input[i] == '*' || input[i] == '/' || input[i] == 'm') {
      if (input[i] == '*') {
        push(INPUT, 0, 2, MULT);
      } else if (input[i] == '/') {
        push(INPUT, 0, 2, DIV);
      } else if (input[i] == '/') {
        push(INPUT, 0, 2, MOD);
        i += 2;
      }
      continue;
    } else if ((input[i] == '+' || input[i] == '-') &&
               (input[i - 1] == '(' || is_num(input[i - 1])) && bracket_unar) {
      double num = 0;
      if (input[i] == '+') {
        i++;
        num = get_number(input, &i);
      } else {
        i++;
        num = get_number(input, &i) * (-1);
      }
      push(INPUT, num, 0, NUMBER);
      i--;
      count++;
      continue;
    } else if ((input[i] == '+' || input[i] == '-') && i == 0) {
      double number = 0;
      if (input[i] == '+') {
        i++;
        number = get_number(input, &i);
      } else {
        i++;
        number = get_number(input, &i) * (-1);
      }
      push(INPUT, number, 0, NUMBER);
      i--;
      count++;
      continue;
    } else if ((input[i] == '+' || input[i] == '-') &&
               ((input[i - 1] >= 48 && input[i - 1] <= 57) ||
                (input[i - 2] >= 48 && input[i - 2] <= 57) ||
                input[i - 1] == ')' || input[i - 2] == ')')) {
      if (input[i] == '+') {
        push(INPUT, 0, 1, PLUS);
      } else if (input[i] == '-') {
        push(INPUT, 0, 1, SUB);
      }
      continue;
    } else if (input[i] == '(' &&
               (input[i + 1] == '+' || input[i + 1] == '-')) {
      bracket_unar = 1;
      continue;
    } else if (input[i] == ')' && bracket_unar == 1) {
      bracket_unar = 0;
      continue;
    } else if (input[i] == '(' &&
               (input[i + 1] != '+' || input[i + 1] != '-')) {
      push(INPUT, 0, -1, LEFT_BR);
      continue;
    } else if (input[i] == ')' && bracket_unar == 0) {
      push(INPUT, 0, -1, RIGHT_BR);
      continue;
    } else if (input[i] == '^') {
      push(INPUT, 0, 3, POWER);
      count++;
      continue;
    } else if (input[i] == 's' || input[i] == 'c' || input[i] == 't') {
      int a = get_trigonometry_or_sqrt(input, &i);
      if (a == 0) {
        push(INPUT, 0, 4, SQRT);
      } else if (a == 1) {
        push(INPUT, 0, 4, SIN);
      } else if (a == 2) {
        push(INPUT, 0, 4, COS);
      } else if (a == 3) {
        push(INPUT, 0, 4, TAN);
      }
      count += 2;
      continue;
    } else if (input[i] == 'a') {
      i++;
      int a = get_trigonometry_or_sqrt(input, &i);
      if (a == 1) {
        push(INPUT, 0, 4, ASIN);
      } else if (a == 2) {
        push(INPUT, 0, 4, ACOS);
      } else if (a == 3) {
        push(INPUT, 0, 4, ATAN);
      }
      count += 2;
      continue;
    } else if (input[i] == 'l') {
      int a = get_log_ln(input, &i);
      if (!a) {
        push(INPUT, 0, 4, LOG);
      } else if (a == 27) {
        push(INPUT, 0, 4, LN);
      }
      count += 2;
    } else if (input[i] == 'x') {
      push(INPUT, x_value, 0, XXX);
      count++;
      continue;
    }
  }
  if (count <= 1) code = 1;
  return code;
}

int get_trigonometry_or_sqrt(char *input, int *i) {
  int code = -1;
  int k = *i;
  if (input[k] == 's') {
    if (input[k + 1] == 'i') {
      code = 1;
      k += 2;
    }
    if (input[k + 1] == 'q') {
      code = 0;
      k += 3;
    }
  } else if (input[k] == 'c') {
    code = 2;
    k += 2;
  } else if (input[k] == 't') {
    code = 3;
    k += 2;
  }
  *i = k;
  return code;
}

int get_log_ln(char *input, int *i) {
  int code = -1;
  int k = *i;
  if (input[k] == 'l' && input[k + 1] == 'o') {
    code = 0;
    k += 2;
  } else if (input[k] == 'l' && input[k + 1] == 'n') {
    code = 27;
    k += 1;
  }
  *i = k;
  return code;
}

double get_number(char *input, int *i) {
  char number[260];
  int j = 0;
  int k = *i;
  while ((input[k] >= 48 && input[k] <= 57) || input[k] == '.' ||
         input[k] == ',') {
    if (input[k] == ',') {
      number[j] = '.';
      k++;
      j++;
    } else {
      number[j] = input[k];
      k++;
      j++;
    }
  }
  *i = k;
  long double num = 0;
  sscanf(number, "%Lf", &num);
  return num;
}

int is_num(char ch) {
  int error = 1;
  if ((ch >= '0' && ch <= '9') || (ch == '.')) {
    error = 0;
  }
  return error;
}