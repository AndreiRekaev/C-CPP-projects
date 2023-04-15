#include "s21_matrix.h"

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int answer = OK;
  if (!A || !B) answer = INCORRECT;
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  if (answer == OK) {
    if (!A->matrix || !B->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (A->columns != B->rows) {
      answer = CALC_ERROR;
    }
  }
  if (answer == OK) {
    answer = s21_create_matrix(A->rows, B->columns, result);
  }
  if (answer == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        for (int k = 0; k < A->columns; k++) {
          result->matrix[i][j] += A->matrix[i][k] * B->matrix[k][j];
        }
      }
    }
  }
  return answer;
}