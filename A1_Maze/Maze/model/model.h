#ifndef _MAZE_MODEL_MODEL_H
#define _MAZE_MODEL_MODEL_H

#include <vector>

#include "./command/command.h"
#include "./learning/qlearning.h"

namespace s21 {

class Model {
 public:
  Model();
  ~Model();

  void Run(Command *c);
  void Train(int row, int col);
  std::vector<std::vector<int>> &Get();
  std::vector<std::vector<double>> &GetTable();

 private:
  std::vector<std::vector<int>> data_;
  std::vector<std::vector<double>> q_table_;
};

}  // end namespace s21
#endif  // _MAZE_MODEL_MODEL_H
