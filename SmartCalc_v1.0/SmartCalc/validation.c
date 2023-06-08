#include "s21_smartcalc.h"

int validation(char *IN) {
  int code = 0;
  int left = 0;
  int right = 0;
  int dot = 0;
  int i = 0;
  char input[300];
  delete_space(IN, input);
  for (; input[i] != '\n'; i++) {
    if ((input[i] >= 48 && input[i] <= 57) || input[i] == 'x') {
      continue;
    } else if ((input[i] == '+' || input[i] == '-' || input[i] == '/' ||
                input[i] == '*' || input[i] == '^') &&
               ((input[i + 1] >= 48 && input[i + 1] <= 57) ||
                input[i + 1] == 'l' || input[i + 1] == 's' ||
                input[i + 1] == 'c' || input[i + 1] == 't' ||
                input[i + 1] == 'a' || input[i + 1] == 'm' ||
                input[i + 1] == '\0' || input[i + 1] == '(' ||
                input[i + 1] == 'x') &&
               (input[i - 1] == ')' ||
                (input[i - 1] >= 48 && input[i - 1] <= 57) ||
                input[i - 1] == 'x')) {
      dot = 0;
      continue;
    } else if (input[i] == '\0' && i != 0) {
      break;
    } else if (input[i] == '(' && input[i + 1] != ')' && input[i + 1] != '\0') {
      left++;
      continue;
    } else if (input[i] == ')') {
      right++;
      continue;
    } else if (input[i] == 't' || input[i] == 'c' ||
               (input[i] == 's' && input[i + 1] == 'i')) {
      code = trigonometry_validation(input, i);
      if (!code) {
        i += 2;
        continue;
      } else {
        break;
      }
    } else if (input[i] == 's' && input[i + 1] == 'q') {
      code = sqrt_validation(input, i);
      if (!code) {
        i += 3;
        continue;
      } else {
        break;
      }
    } else if (input[i] == 'l') {
      code = logarithm_validation(input, i);
      if (!code) {
        i += 2;
        continue;
      } else if (code == 3) {
        code = 0;
        i += 1;
        continue;
      } else {
        break;
      }
    } else if (input[i] == 'a') {
      if (input[i + 1] == 't' || input[i + 1] == 's' || input[i + 1] == 'c') {
        i++;
        code = trigonometry_validation(input, i);
        if (!code) {
          i += 2;
          continue;
        } else {
          break;
        }
      }
    } else if (input[i] == 'm') {
      code = mod_validation(input, i);
      if (!code) {
        i += 2;
        dot = 0;
        continue;
      } else {
        break;
      }
    } else if ((input[i] == '+' || input[i] == '-') &&
               (input[i - 1] == '(' || i == 0) &&
               (input[i + 1] >= 48 && input[i + 1] <= 57)) {
      continue;
    } else if ((input[i] == '.' || input[i] == ',') &&
               (input[i + 1] >= 48 && input[i + 1] <= 57) &&
               (input[i - 1] >= 48 && input[i - 1] <= 57) && dot != 1) {
      dot = 1;
      continue;
    } else if (input[i] == '\0' && i == 0) {
      code = 1;
    } else {
      code = 1;
    }
    if (code) break;
  }
  IN = input;
  if (left != right) code = 1;
  return code;
}

int trigonometry_validation(char *input, int i) {
  int code = 0;
  if (input[i] == 'c' && input[i + 1] == 'o' && input[i + 2] == 's' &&
      input[i + 3] == '(') {
  } else if (input[i] == 's' && input[i + 1] == 'i' && input[i + 2] == 'n' &&
             input[i + 3] == '(') {
  } else if (input[i] == 't' && input[i + 1] == 'a' && input[i + 2] == 'n' &&
             input[i + 3] == '(') {
  } else if (input[i] == 'c' && input[i + 1] == 't' && input[i + 2] == 'g' &&
             input[i + 3] == '(') {
  } else {
    code = 1;
  }
  return code;
}

int sqrt_validation(char *input, int i) {
  int code = 0;
  if (!check_for_0(input, i, 4)) {
    if (input[i] == 's' && input[i + 1] == 'q' && input[i + 2] == 'r' &&
        input[i + 3] == 't' && input[i + 4] == '(') {
    } else {
      code = 1;
    }
  }
  return code;
}

int check_for_0(char *input, int i, int len) {
  int code = 0;
  for (; input[i] == '\0' || len == 0; len--) {
    if (input[i] != '\0') {
      code = 1;
      i++;
      break;
    }
  }
  return code;
}

int logarithm_validation(char *input, int i) {
  int code = 0;
  if (!check_for_0(input, i, 3)) {
    if (input[i] == 'l' && input[i + 1] == 'o' && input[i + 2] == 'g' &&
        input[i + 3] == '(') {
    } else if (input[i] == 'l' && input[i + 1] == 'n' && input[i + 3] == '(') {
      code = 3;
    } else {
      code = 1;
    }
  }
  return code;
}

int mod_validation(char *input, int i) {
  int code = 0;
  if (!check_for_0(input, i, 3)) {
    if (input[i] == 'm' && input[i + 1] == 'o' && input[i + 2] == 'd') {
    } else {
      code = 1;
    }
  }
  return code;
}

int *delete_space(const char *input, char *out) {
  int j = 0;
  for (int i = 0; i < 256; i++) {
    out[i] = '\0';
  }
  for (int i = 0; input[i] != '\n' && input[i] != '\0'; i++) {
    if ((input[i] != ' ' && input[i] != '\n') || input[i] != '\0') {
      out[j] = input[i];
      j++;
      continue;
    }
    if (input[i] == '\0' || input[i] == '\n') out[j] = '\0';
  }
  return 0;
}