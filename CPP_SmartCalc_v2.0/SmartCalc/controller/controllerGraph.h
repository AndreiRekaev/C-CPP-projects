/*!
\file
\brief Header file with realisation of Graph Controller
*/
#ifndef SRC_CONTROLLER_CONTROLLERGRAPH_H_
#define SRC_CONTROLLER_CONTROLLERGRAPH_H_

#include <string>
#include <utility>
#include <vector>

#include "../model/modelGraph.h"

namespace s21 {
/*!
\brief Class of controller for Graph calculator
*/
class ControllerGraph {
 public:
  /// @brief preffered constructor with parameters for create graph
  /// @param lexeme the input string
  ControllerGraph(std::string lexeme) : _graph(lexeme){};
  ControllerGraph() = default;
  ~ControllerGraph(){};
  void SetXMin(double x) { _graph.SetXMin(x); }
  void SetXMax(double x) { _graph.SetXMax(x); }
  void SetPointsQuantity(uint32_t q) { _graph.SetPointsQuantity(q); }
  void ProcessGraph(std::vector<std::pair<double, double>>& result) {
    _graph.CountPoints(result);
  }

 private:
  GraphCalc _graph;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLERGRAPH_H_
