/*!
\file
\brief Header file with realisation of RPN Calculator Controller
*/
#ifndef SRC_CONTROLLER_CONTROLLERCALC_H_
#define SRC_CONTROLLER_CONTROLLERCALC_H_

#include <string>

#include "../model/modelCalc.h"

namespace s21 {
/*!
\brief Class controller contains all methods for bring information
/// from view to model and vice versa
*/
class ControllerCalc {
 public:
  /// @brief default constructor
  ControllerCalc() = default;

  /// @brief default destructor
  ~ControllerCalc(){};

  /// @brief method proccess recieve input string and return result
  /// @param input the input string
  /// @param x the value of x
  /// @return the result of the expression
  double Proccess(std::string input, double x);
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLERCALC_H_
