#include "s21_matrix.h"

int s21_eq_matrix(matrix_t* A, matrix_t* B) {
  int answer = SUCCESS;
  if (!A || !B) {
    answer = FAILURE;
  } else {
    if (A->columns != B->columns || A->rows != B->rows || !(A->matrix) ||
        !(B->matrix)) {
      answer = FAILURE;
    } else {
      answer = matrix_compare(A, B);
    }
  }
  return answer;
}

int matrix_compare(matrix_t* A, matrix_t* B) {
  int result = SUCCESS;
  for (int i = 0; i < A->rows; i++) {
    for (int j = 0; j < A->columns; j++) {
      result = significant_values_7_compare(A->matrix[i][j], B->matrix[i][j]);
      if (result == FAILURE) break;
    }
    if (result == FAILURE) break;
  }
  return result;
}

int significant_values_7_compare(double a, double b) {
  int result = SUCCESS;
  int exp = 0;

  while (a >= 1.) {
    a /= 10.;
    b /= 10.;
    exp++;
  }
  if (exp > 0) {
    while (exp != -1 && result == SUCCESS) {
      result = number_compare(&a, &b);
      exp--;
    }
    if (exp == -1) exp++;
  }
  while (exp < 7 && result == SUCCESS) {
    result = number_compare(&a, &b);
    exp++;
  }
  return result;
}

int number_compare(double* a, double* b) {
  int result = SUCCESS;
  (*a) *= 10.;
  (*b) *= 10.;
  if ((int)(*a) == (int)(*b)) {
    (*a) -= (int)(*a);
    (*b) -= (int)(*b);
  } else {
    result = FAILURE;
  }
  return result;
}
