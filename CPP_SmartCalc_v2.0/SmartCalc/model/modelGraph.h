/*!
\file
\brief Header file of graph model
*/
#ifndef SMARTCALC_MODEL_MODELGRAPH_H_
#define SMARTCALC_MODEL_MODELGRAPH_H_

#include <utility>
#include <vector>

#include "modelCalc.h"

namespace s21 {
/*!
\brief Class with calculating points to draw graph of expression, using RPN
*/
class GraphCalc : public SmartCalc {
 public:
  /// @brief inherited constructor with additional fields x axis and
  /// pointsquantity
  /// @param input the input string
  GraphCalc(std::string input) : SmartCalc(input){};
  void SetPointsQuantity(uint32_t q) noexcept;
  void SetXMin(double x) noexcept;
  void SetXMax(double x) noexcept;
  /// @brief method for count coordinates x and y in cycle
  /// @param vector for storage of coordinates
  void CountPoints(std::vector<std::pair<double, double>>& result);

 private:
  double xMin_ = -10.;
  double xMax_ = 10.;
  uint32_t pointsQuantity_ = 10000;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MODELGRAPH_H_
