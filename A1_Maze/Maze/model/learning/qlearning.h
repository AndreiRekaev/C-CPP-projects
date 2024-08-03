#ifndef _MAZE_MODEL_LEARNING_QLEARNING_H_
#define _MAZE_MODEL_LEARNING_QLEARNING_H_

#include <iostream>
#include <random>
#include <vector>

#include "../command/command.h"

namespace s21 {
class QLearning {
 public:
  QLearning(int r, int c, std::vector<std::vector<int>> &data);
  ~QLearning();
  void Training();
  std::vector<std::vector<double>> Get();

 private:
  double GetMax(int state);
  int EgreedyPolicy(int state, std::vector<int> &v, int e = 10);
  int GetReward(int state, int action, int &next_state);
  bool IsPosibleAction(int state, int action, int &next_state);
  void print();
  void InitQTable();
  std::vector<int> PossiblePath(int next_state);

 private:
  int row_, col_, sr_, sc_, fin;
  double alfa, gamma;
  std::vector<std::vector<int>> maze_;
  std::vector<std::vector<double>> q_table_;
};
}  // end namespace s21
#endif  // _MAZE_MODEL_LEARNING_QLEARNING_H_
