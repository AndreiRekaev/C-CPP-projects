/*!
\file
\brief Header file of Graph Window of our application
*/
#ifndef SMARTCALC_VIEW_GRAPHVIEW_H
#define SMARTCALC_VIEW_GRAPHVIEW_H

#include <QDialog>
#include <memory>
#include <string>
#include <utility>
#include <vector>

#include "../controller/controllerGraph.h"
#include "../qcustomplot.h"

namespace Ui {
class GraphView;
}

namespace s21 {
/*!
\brief Class for UI (GraphWindow of the application)
*/
class GraphView : public QDialog {
  Q_OBJECT

 public:
  /// @brief main class for graph logic
  /// @param lexeme the input string
  explicit GraphView(std::string &lexeme, QWidget *parent = nullptr);
  ~GraphView();

 private slots:
  /*!
  \brief Recalculate points of the graph for newly set scale
  */
  void on_button_count_clicked();

 private:
  const uint32_t kPointsQuantity = 10000.;

  /*!
  \brief Function sets validators for all lineEdits in the UI
  */
  void SetValidators();

  /*!
  \brief Gives oll nessesary values to the controller and gets the result vector
  from it with calculated points
  */
  void InitCalc();

  /*!
  \brief Some magic with QCustomPlot Library to draw pretty graph
  */
  void PrintGraph();

  Ui::GraphView *ui;
  std::vector<std::pair<double, double>> result;
  std::string lexeme_;
  ControllerGraph contGraph_;
  double xMin_ = -10., xMax_ = 10., yMin_ = -10., yMax_ = 10.;

  std::unique_ptr<QRegularExpressionValidator> validateDouble_;
};

}  // namespace s21

#endif  // SMARTCALC_VIEW_GRAPHVIEW_H
