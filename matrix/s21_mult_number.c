#include "s21_matrix.h"

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int answer = OK;
  if (!A) answer = INCORRECT;
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  if (answer == OK) {
    if (!A->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    answer = s21_create_matrix(A->rows, A->columns, result);
  }
  if (answer == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] * number;
      }
    }
  }
  return answer;
}