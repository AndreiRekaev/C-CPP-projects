/**
 * \mainpage
 * Basicly OOP Smart Calculator, using MVC pattern and some SOLID principles
 * with GUI realised on QT Creator with qcustomplot.h usage for graphics
 *
 * Calculating arbitrary bracketed arithmetic expressions in infix notation.
 *
 * Calculate arbitrary bracketed arithmetic expressions in infix notation with
 * substitution of the value of the variable x as a number.
 *
 * Plotting a graph of a function given by an expression in infix notation with
 * the variable x (with coordinate axes, mark of the used scale and an adaptive
 * grid)
 *
 * Credit and Deposit Calculator
 */

/*!
\file
\brief Header file of main calculation model
*/
#ifndef SMARTCALC_MODEL_MODELCALC_H_
#define SMARTCALC_MODEL_MODELCALC_H_

#include <string.h>

#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <limits>
#include <queue>
#include <stack>

/// @brief enum type_t contains all types of tokens
typedef enum type_t {
  NONE = 0,
  NUM = 1,
  X = 2,
  PLUS = 3,
  MINUS = 4,
  MUL = 5,
  DIV = 6,
  MOD = 7,
  EXP = 8,
  COS = 9,
  SIN = 10,
  TAN = 11,
  ACOS = 12,
  ASIN = 13,
  ATAN = 14,
  SQRT = 15,
  LN = 16,
  LOG = 17,
  BRACK_O = 18,
  BRACK_C = 19,
} type_t;

namespace s21 {
class SmartCalc {
 public:
  /// @brief parametric constructor, default constructor is private
  /// @param input the input string
  SmartCalc(std::string input);

  /// @brief method calculate return the result of the expression
  /// @return the result of the expression
  double Calculate();

  /// @brief method calculate recieve x and return the result of the expression
  /// @param x the value of x
  /// @return the result of the expression
  double Calculate(double x);

 private:
  SmartCalc();
  /// @brief method parseString parse the input string and store the result
  /// in _queue
  /// @param input the input string
  /// @return true if the input string is valid, false otherwise
  bool parseString(const char* input);
  /// @brief method checkString check the input string
  /// @return true if the input string is valid, false otherwise
  bool checkString();

  /// @brief method reversedPolish convert the infix expression to postfix
  void reversedPolish();
  /// @brief method getPriority return the priority of the operator
  /// @param op the operator
  /// @return the priority of the operator
  int getPriority(int op);

  std::queue<std::pair<type_t, double> > _queue;
  uint32_t pointsQuantity = 100000.;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MODELCALC_H_
