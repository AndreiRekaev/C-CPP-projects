#ifndef _MAZE_VIEW_CAVE_GEN_GENCAVE_H_
#define _MAZE_VIEW_CAVE_GEN_GENCAVE_H_

#include <random>
#include <vector>

namespace s21 {
class GenCave {
 public:
  GenCave();
  std::vector<std::vector<int>> Generation(int row, int col, int chance);
};
}  // end namespace s21

#endif  // _MAZE_VIEW_CAVE_GEN_GENCAVE_H_
