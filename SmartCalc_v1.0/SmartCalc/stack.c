#include "s21_smartcalc.h"

void push(s21_stack **head, long double value, int priority, operation op) {
  s21_stack *tmp = malloc(sizeof(s21_stack));
  tmp->value = value;
  tmp->priority = priority;
  tmp->type = op;
  tmp->next = *head;
  *head = tmp;
}

void pop(s21_stack **head) {
  s21_stack *tmp = NULL;
  tmp = (*head)->next;
  free(*head);
  *head = tmp;
}

void pop_twice(s21_stack **head) {
  s21_stack *tmp = NULL;
  tmp = (*head)->next->next->next;
  free((*head)->next->next);
  free((*head)->next);
  (*head)->next = tmp;
}

void reverse_stack(s21_stack **src, s21_stack **dest) {
  int err = 0;
  while (1) {
    push(dest, (*src)->value, (*src)->priority, (*src)->type);
    pop(src);
    if (err) break;
    if (!(*src)->next) err = 1;
  }
}

void next_pop(s21_stack **head) {
  s21_stack *tmp = NULL;
  tmp = (*head)->next->next;
  free((*head)->next);
  (*head)->next = tmp;
}

// void print_stack(s21_stack *A) {
//   s21_stack *tmp = A;
//   while (tmp != NULL) {
//     printf("%Lf", tmp->value);
//     printf("%d", tmp->priority);
//     printf(
//         "%d\n------------------------------------------"
//         "--------------\n",
//         tmp->type);
//     if (tmp == NULL) break;
//     tmp = tmp->next;
//   }
// }
