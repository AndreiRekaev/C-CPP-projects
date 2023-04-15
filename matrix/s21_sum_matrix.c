#include "s21_matrix.h"

int s21_sum_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int answer = check_correct_matrix(A, B, result);
  if (answer == OK) {
    answer = s21_create_matrix(A->rows, A->columns, result);
  }
  if (answer == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        result->matrix[i][j] = A->matrix[i][j] + B->matrix[i][j];
      }
    }
  }
  return answer;
}

int check_correct_matrix(matrix_t* A, matrix_t* B, matrix_t* result) {
  int answer = OK;
  if (!A || !B) answer = INCORRECT;
  if (answer == OK) {
    if (!A->matrix || !B->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (A->rows != B->rows || A->columns != B->columns) answer = CALC_ERROR;
  }
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  return answer;
}