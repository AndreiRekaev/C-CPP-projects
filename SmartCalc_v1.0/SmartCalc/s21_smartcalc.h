#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <math.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCCESS 0
#define ERROR 1

typedef enum {
  XXX = 0,
  NUMBER = 1,
  PLUS = 2,
  SUB = 3,
  MULT = 4,
  DIV = 5,
  MOD = 6,
  POWER = 7,
  SIN = 8,
  COS = 9,
  TAN = 10,
  ACOS = 11,
  ASIN = 12,
  ATAN = 13,
  SQRT = 14,
  LN = 15,
  LOG = 16,
  LEFT_BR = 17,
  RIGHT_BR = 18
} operation;

typedef struct stack_struct {
  long double value;
  int priority;
  operation type;
  struct stack_struct *next;
} s21_stack;

/* STACK */

/// \brief Operations with stack
/// \param s21_stack
void push(s21_stack **head, long double value, int priority, operation op);
void pop(s21_stack **head);
void pop_twice(s21_stack **head);
void reverse_stack(s21_stack **src, s21_stack **dest);
void next_pop(s21_stack **head);

/* PRINT STACK*/
void print_stack(s21_stack *A);

/* VALIDATION */
/// \brief Validation for input string
/// \param char *IN
int validation(char *IN);
int trigonometry_validation(char *input, int i);
int sqrt_validation(char *input, int i);
int check_for_0(char *input, int i, int len);
int logarithm_validation(char *input, int i);
int mod_validation(char *input, int i);
int *delete_space(const char *input, char *out);

/* PARSER */
/// \brief Parse input expression
/// \param char *input
/// \param s21_stack structure
/// \param x_value value for x
int parser(char *input, s21_stack **INPUT, long double x_value);
int get_trigonometry_or_sqrt(char *input, int *i);
int get_log_ln(char *input, int *i);
double get_number(char *input, int *i);
int is_num(char ch);

/* SmartCalc functions */
/// \brief Main function with shunting yard algorythm (reverse polish notation)
/// and calculator for queue output processing
/// \param char *input
/// \param s21_stack stack
/// \param result result of calculations
int QT_processing(char *input, long double value, long double *result);
void rev_polish_notation(s21_stack **first, s21_stack **polish_num,
                         s21_stack **polish_support);
void calculator(s21_stack **queue, s21_stack **output);

// _______________________________________________________________________________
/// \brief Credit alculator
void annu_credit_calc(double *result, double credit, double interest_rate,
                      double period);
void diff_credit_calc(double *result, double credit, double interest_rate,
                      double period);

// _______________________________________________________________________________
/// \brief Deposit calculator
void deposit_calc(double *result, double *depozit, int period,
                  double interest_rate, double tax, double replenishment,
                  double withdrawal, double *count_replenishment,
                  double *count_withdrawal, double *minimum_balance,
                  int type_period, int type_dep_calc);
void calculation_deposit(int period_type, double *interest_charges,
                         double *tax_amount, double *depozit,
                         double interest_rate, double tax, double replenishment,
                         double withdrawal, double *count_replenishment,
                         double *count_withdrawal, double *minimum_balance,
                         int type_dep_calc, double upper_value,
                         double lower_value, int tax_period);
void calc_tax_amount(double *interest_charges, double tax, double *tax_amount,
                     int tax_period, int *status_tax);
void replenishment_op(double *depozit, double replenishment,
                      double *count_replenishment, int int_period);
void withdrawal_op(double *depozit, double withdrawal, double *count_withdrawal,
                   int int_period, double *minimum_balance);

#endif  // SRC_S21_SMARTCALC_H_