#include "s21_smartcalc.h"

// int main() {
//   char start_string[256] = {"9*x"};
//   long double x_value = 3.0;
//   long double result = 0.0;
//   QT_processing(start_string, x_value, &result);
//   printf("%Lf\n", result);
//   return 0;
// }

int QT_processing(char *input, long double value, long double *result) {
  int code = ERROR;
  if (!validation(input)) {
    code = SUCCESS;
    s21_stack *one = NULL, *one_rev = NULL, *two = NULL, *three = NULL,
              *rpn_sup = NULL, *rpn_num = NULL;
    if (!parser(input, &one, value)) {
      reverse_stack(&one, &one_rev);
      rev_polish_notation(&one_rev, &rpn_num, &rpn_sup);
      reverse_stack(&rpn_num, &two);
      calculator(&two, &three);
      *result = three->value;
      pop(&three);
    } else {
      code = ERROR;
    }
    free(three);
  }
  return code;
}

void rev_polish_notation(s21_stack **first, s21_stack **polish_num,
                         s21_stack **polish_support) {
  int err = 0;
  while (1) {
    if (*first) {
      if ((*first)->type == RIGHT_BR) {
        pop(first);
        while ((*polish_support)->type != LEFT_BR) {
          push(polish_num, (*polish_support)->value,
               (*polish_support)->priority, (*polish_support)->type);
          pop(polish_support);
        }
        pop(polish_support);
      } else {
        if ((*first)->type == NUMBER || (*first)->type == XXX) {
          push(polish_num, (*first)->value, (*first)->priority, (*first)->type);
          pop(first);
        } else {
          if (*polish_support) {
            if (((*first)->priority != -1 &&
                 (*first)->priority <= (*polish_support)->priority)) {
              while (*polish_support) {
                push(polish_num, (*polish_support)->value,
                     (*polish_support)->priority, (*polish_support)->type);
                pop(polish_support);
              }
            }
          }
          push(polish_support, (*first)->value, (*first)->priority,
               (*first)->type);
          pop(first);
        }
      }
    }
    if (!(*first) || err) break;
    if (!(*first)->next) err = 1;
  }
  err = 0;
  if (*polish_support) {
    while (1) {
      push(polish_num, (*polish_support)->value, (*polish_support)->priority,
           (*polish_support)->type);
      pop(polish_support);
      if (err || !(*polish_support)) break;
      if (!(*polish_support)->next) err = 1;
    }
  }
}

void calculator(s21_stack **queue, s21_stack **output) {
  int check_num = 0;
  int code = 0;
  while (1) {
    if ((*queue)->type == PLUS) {
      pop(queue);
      push(output, (*output)->next->value + (*output)->value, 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == SUB) {
      pop(queue);
      push(output, (*output)->next->value - (*output)->value, 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == MULT) {
      pop(queue);
      push(output, (*output)->next->value * (*output)->value, 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == DIV) {
      pop(queue);
      push(output, (*output)->next->value / (*output)->value, 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == MOD) {
      pop(queue);
      push(output, fmodl((*output)->next->value, (*output)->value), 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == POWER) {
      pop(queue);
      push(output, pow((*output)->next->value, (*output)->value), 0, NUMBER);
      pop_twice(output);
    } else if ((*queue)->type == SIN) {
      pop(queue);
      push(output, sin((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == COS) {
      pop(queue);
      push(output, cos((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == TAN) {
      pop(queue);
      push(output, tan((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == ASIN) {
      pop(queue);
      push(output, asin((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == ACOS) {
      pop(queue);
      push(output, acos((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == ATAN) {
      pop(queue);
      push(output, atan((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == SQRT) {
      pop(queue);
      push(output, sqrt((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == LN) {
      pop(queue);
      push(output, log((*output)->value), 0, NUMBER);
      next_pop(output);
    } else if ((*queue)->type == LOG) {
      pop(queue);
      push(output, log10((*output)->value), 0, NUMBER);
      next_pop(output);
    }
    if (*queue) {
      if ((*queue)->type == NUMBER || (*queue)->type == XXX) {
        check_num++;
        push(output, (*queue)->value, (*queue)->priority, (*queue)->type);
        pop(queue);
      }
    }
    if (!(*queue) || code) break;
    if (!(*queue)->next) code = 1;
  }
}
