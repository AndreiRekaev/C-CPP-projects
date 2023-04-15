#ifndef SRC_S21_MATRIX_H_
#define SRC_S21_MATRIX_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1
#define FAILURE 0
#define S21_NULL (void*)0

enum ERRORS { OK, INCORRECT, CALC_ERROR };

typedef struct matrix_struct {
  double** matrix;
  int rows;
  int columns;
} matrix_t;

int s21_create_matrix(int rows, int columns, matrix_t* result);
void s21_remove_matrix(matrix_t* A);
int s21_eq_matrix(matrix_t* A, matrix_t* B);
int s21_sum_matrix(matrix_t* A, matrix_t* B,
                   matrix_t* result);  // Matrix must be of the same sizes
int s21_sub_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int s21_mult_number(matrix_t* A, double number,
                    matrix_t* result);  // mult matrix on number
int s21_mult_matrix(matrix_t* A, matrix_t* B,
                    matrix_t* result);  // first matrix multiply by second
int s21_transpose(matrix_t* A, matrix_t* result);
int s21_calc_complements(matrix_t* A,
                         matrix_t* result);  // matrix of calc complements
                                             // (algebraic additions) and minor
int s21_determinant(matrix_t* A, double* result);
int s21_inverse_matrix(matrix_t* A, matrix_t* result);

/*
    Helper functions
*/
int matrix_compare(matrix_t* A, matrix_t* B);
int significant_values_7_compare(double a, double b);
int number_compare(double* a, double* b);
int check_correct_matrix(matrix_t* A, matrix_t* B, matrix_t* result);
int create_minor(matrix_t* A, int k, int m, matrix_t* result);

#endif  // SRC_S21_MATRIX_H_