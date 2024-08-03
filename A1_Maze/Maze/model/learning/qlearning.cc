#include "qlearning.h"
namespace s21 {
QLearning::QLearning(int r, int c, std::vector<std::vector<int>> &data)
    : row_(r),
      col_(c),
      sr_(data.size()),
      sc_(data[0].size()),
      fin((r - 1) * sc_ + c - 1),
      alfa(0.75),
      gamma(0.9),
      maze_(data) {
  q_table_ =
      std::vector(data.size() * data[0].size(), std::vector<double>(4, 0));
}
QLearning::~QLearning() {}

void QLearning::Training() {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution distrib;
  int state = 0;  //, prev_state = -1;
  InitQTable();
  int e = 99;
  for (int i = 0; i < 10 * sr_ * sc_; ++i) {
    int next_state = 0, step = 0;
    e *= 0.99;
    while ((state = distrib(gen) % (sr_ * sc_)) == fin) {
    };
    while (1) {
      step++;
      std::vector<int> pp = PossiblePath(state);
      if (pp.empty()) break;
      int next_action = EgreedyPolicy(state, pp);
      int reward = GetReward(state, next_action, next_state);
      double t =
          reward + gamma * GetMax(next_state) - q_table_[state][next_action];
      q_table_[state][next_action] += alfa * t;
      if (next_state == -2) {
        break;
      } else if (next_state == -1) {
      } else if (next_state >= 0) {
        // prev_state = state;
        state = next_state;
      }
      // if (step > sr_ * sc_ * 10) break;
    }
  }
}
// NB! Delete
void QLearning::print() {
  int len = q_table_.size();
  for (int i = 0; i < len; ++i) {
    std::cout << q_table_[i][0] << ':' << q_table_[i][1] << ':'
              << q_table_[i][2] << ':' << q_table_[i][3] << ' ';
    if (i && i % sc_ == sc_ - 1) std::cout << std::endl;
  }
}
void QLearning::InitQTable() {
  for (int i = 0; i < sr_; ++i) {
    for (int k = 0; k < sc_; ++k) {
      if (i == 0 || maze_[i - 1][k] & kBot) {
        q_table_[i * sc_ + k][UP] = -sr_ * sc_;
      }
      if (i == sr_ - 1 || maze_[i][k] & kBot) {
        q_table_[i * sc_ + k][DOWN] = -sr_ * sc_;
      }
      if (k == 0 || maze_[i][k - 1] & kRight) {
        q_table_[i * sc_ + k][LEFT] = -sr_ * sc_;
      }
      if (k == sc_ - 1 || maze_[i][k] & kRight) {
        q_table_[i * sc_ + k][RIGHT] = -sr_ * sc_;
      }
    }
  }
}
std::vector<int> QLearning::PossiblePath(int current_state) {
  int ns = 0;
  std::vector<int> res;
  for (int i = 0; i < 4; ++i) {
    if (IsPosibleAction(current_state, i, ns) /*&& ns != prev_state*/) {
      res.emplace_back(i);
    }
  }
  return res;
}

double QLearning::GetMax(int state) {
  if (state < 0) {
    return 0;
  } else {
    return std::max(std::max(q_table_[state][0], q_table_[state][1]),
                    std::max(q_table_[state][2], q_table_[state][3]));
  }
}
int QLearning::GetReward(int state, int action, int &next_state) {
  int r = -1;
  if (action == UP) {
    next_state = state - sc_;
  } else if (action == DOWN) {
    next_state = state + sc_;
  } else if (action == LEFT) {
    next_state = state - 1;
  } else if (action == RIGHT) {
    next_state = state + 1;
  }
  if (next_state == fin) {
    r = 50 * sc_;
    next_state = -2;
  }
  return r;
}
bool QLearning::IsPosibleAction(int state, int action, int &ns) {
  if (action == UP) {
    ns = state - sc_;
    if (ns < 0 || maze_[ns / sc_][ns % sc_] & kBot) return false;
  } else if (action == DOWN) {
    ns = state + sc_;
    if (maze_[state / sc_][state % sc_] & kBot) return false;
  } else if (action == LEFT) {
    ns = state - 1;
    if (ns < 0 || maze_[ns / sc_][ns % sc_] & kRight) return false;
  } else if (action == RIGHT) {
    ns = state + 1;
    if (maze_[state / sc_][state % sc_] & kRight) return false;
  }
  return true;
}
int QLearning::EgreedyPolicy(int state, std::vector<int> &v, int e) {
  std::random_device rd;
  std::mt19937 gen(rd());
  std::uniform_int_distribution distrib;
  if (distrib(gen) % 100 < e) {
    return v[distrib(gen) % v.size()];
  } else {
    int ind = 0;
    for (size_t i = 1; i < v.size(); ++i) {
      if (q_table_[state][v[i]] > q_table_[state][v[ind]]) ind = i;
    }
    return v[ind];
  }
}
std::vector<std::vector<double>> QLearning::Get() { return q_table_; }
}  // end namespace s21
