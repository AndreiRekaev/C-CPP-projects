#include "s21_matrix.h"

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int answer = OK;
  if (rows <= 0 || columns <= 0) answer = INCORRECT;
  if (answer == OK) {
    result->rows = rows;
    result->columns = columns;
    result->matrix = (double **)malloc(rows * sizeof(double *));
    if (result->matrix != S21_NULL) {
      for (int i = 0; i < rows; i++) {
        result->matrix[i] = (double *)malloc(columns * sizeof(double));
        if (!result->matrix[i]) {
          s21_remove_matrix(result);
          answer = INCORRECT;
        }
      }
    }
  }
  if (answer == OK) {
    // init zero
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < columns; j++) {
        result->matrix[i][j] = 0.;
      }
    }
  }
  return answer;
}
