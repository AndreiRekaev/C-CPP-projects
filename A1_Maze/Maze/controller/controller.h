#ifndef _MAZE_CONTROLLER_CONTROLLER_H_
#define _MAZE_CONTROLLER_CONTROLLER_H_

#include "../model/model.h"

namespace s21 {
class Controller {
 public:
  Controller();
  ~Controller();

  void Run(Command* c);
  void Train(int row, int col);
  std::vector<std::vector<int>>& Get();
  std::vector<std::vector<double>>& GetTable();

 private:
  Model model_;
};

}  // end namespace s21
#endif  //_MAZE_CONTROLLER_CONTROLLER_H_
