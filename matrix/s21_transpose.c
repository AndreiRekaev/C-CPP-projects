#include "s21_matrix.h"

int s21_transpose(matrix_t* A, matrix_t* result) {
  int answer = OK;
  if (!A) answer = INCORRECT;
  if (answer == OK) {
    if (!A->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  if (answer == OK) {
    answer = s21_create_matrix(A->columns, A->rows, result);
  }
  if (answer == OK) {
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        result->matrix[j][i] = A->matrix[i][j];
      }
    }
  }
  return answer;
}