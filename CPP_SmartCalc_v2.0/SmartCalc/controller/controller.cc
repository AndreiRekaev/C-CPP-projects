#include "controllerCalc.h"

double s21::ControllerCalc::Proccess(std::string input, double x) {
  try {
    SmartCalc SmartCalc(input);
    return SmartCalc.Calculate(x);
  } catch (...) {
    return std::numeric_limits<double>::quiet_NaN();
  }
}
