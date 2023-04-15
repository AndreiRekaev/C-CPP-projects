#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int answer = OK;
  double determinant = 0.;
  answer = s21_determinant(A, &determinant);
  if (answer == OK) {
    if (determinant == 0 || fabs(determinant) <= 1e-07) answer = CALC_ERROR;
  }
  if (answer == OK) {
    matrix_t tmp = {S21_NULL, 0, 0};
    answer = s21_calc_complements(A, result);
    if (answer == OK) answer = s21_transpose(result, &tmp);
    s21_remove_matrix(result);
    if (answer == OK) answer = s21_mult_number(&tmp, 1 / determinant, result);
    s21_remove_matrix(&tmp);
  }
  return answer;
}