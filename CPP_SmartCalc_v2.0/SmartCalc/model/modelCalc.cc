#include "modelCalc.h"

// model recieve a string, parse it to a stack and translate it to reverse
// polish notation then calculate the result
s21::SmartCalc::SmartCalc(std::string input) {
  const char* input_c = input.c_str();
  if (parseString(input_c) == false) {
    throw std::invalid_argument("Invalid expression");
  }
  reversedPolish();
}
