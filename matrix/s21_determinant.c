#include "s21_matrix.h"

int s21_determinant(matrix_t* A, double* result) {
  int answer = OK;
  if (!A) answer = INCORRECT;
  if (answer == OK) {
    if (A->rows != A->columns) {
      answer = CALC_ERROR;
    } else if (!A->rows || !A->columns) {
      answer = INCORRECT;
    }
  }
  if (answer == OK) {
    if (!A->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (A->rows < 1 || A->columns < 1) answer = INCORRECT;
  }
  double result_minor = 0.;
  *result = 0.;
  if (answer == OK && A->rows == 2) {
    *result =
        A->matrix[0][0] * A->matrix[1][1] - A->matrix[0][1] * A->matrix[1][0];
  } else if (answer == OK && A->rows == 1) {
    *result = A->matrix[0][0];
  } else if (answer == OK) {
    matrix_t minor = {S21_NULL, 0, 0};
    double tmp = 0.;
    for (int i = 0; i < A->columns && answer == OK; i++) {
      answer = create_minor(A, 0, i, &minor);
      if (answer == OK) {
        answer = s21_determinant(&minor, &tmp);
      }
      if (answer == OK) {
        result_minor += tmp * A->matrix[0][i] * (i % 2 == 0 ? 1 : -1);
        s21_remove_matrix(&minor);
      }
      if (answer != OK) break;
    }
    *result = result_minor;
  }
  return answer;
}

int create_minor(matrix_t* A, int k, int m, matrix_t* result) {
  int answer = OK;
  if (!A) answer = INCORRECT;
  if (answer == OK) {
    if (!A->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  if (answer == OK) {
    answer = s21_create_matrix(A->rows - 1, A->columns - 1, result);
  }
  if (answer == OK) {
    for (int i = 0; i < result->rows; i++) {
      for (int j = 0; j < result->columns; j++) {
        if (i >= k && j >= m) {
          result->matrix[i][j] = A->matrix[i + 1][j + 1];
        } else if (i >= k && j < m) {
          result->matrix[i][j] = A->matrix[i + 1][j];
        } else if (i < k && j >= m) {
          result->matrix[i][j] = A->matrix[i][j + 1];
        } else {
          result->matrix[i][j] = A->matrix[i][j];
        }
      }
    }
  }
  return answer;
}