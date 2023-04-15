#include "s21_matrix.h"

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int answer = OK;
  if (!A) answer = INCORRECT;
  if (answer == OK) {
    if (!A->matrix) answer = INCORRECT;
  }
  if (answer == OK) {
    if (!result) answer = INCORRECT;
  }
  if (answer == OK) {
    if (A->rows < 1 || A->columns < 1) answer = INCORRECT;
  }
  if (answer == OK) {
    if (A->rows != A->columns) answer = CALC_ERROR;
  }
  if (answer == OK) {
    answer = s21_create_matrix(A->rows, A->columns, result);
  }
  if (answer == OK) {
    if (A->rows == 1) {
      result->matrix[0][0] = 1;
    } else {
      matrix_t minor = {S21_NULL, 0, 0};
      for (int i = 0; i < result->rows; i++) {
        for (int j = 0; j < result->columns; j++) {
          answer = create_minor(A, i, j, &minor);
          double result_minor_det = 0.;
          answer = answer == OK ? s21_determinant(&minor, &result_minor_det)
                                : answer;
          result->matrix[i][j] =
              answer == OK
                  ? ((i + j) % 2 == 0 ? result_minor_det : -result_minor_det)
                  : 0.;
          s21_remove_matrix(&minor);
          if (answer != OK) break;
        }
      }
    }
  }
  return answer;
}
