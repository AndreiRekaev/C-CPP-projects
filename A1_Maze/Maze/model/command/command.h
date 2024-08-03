#ifndef _MAZE_MODEL_COMMAND_COMMAND_H_
#define _MAZE_MODEL_COMMAND_COMMAND_H_

#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <random>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

namespace s21 {
struct not_open {};
struct bad_file {};
enum Wall {
  kRight = 1,
  kBot,
  kVertTop = 4,
  kVertBot = 8,
  kHorRight = 16,
  kHorLeft = 32
};
enum Direction { UP, DOWN, LEFT, RIGHT };

struct Cell {
  bool visited = false;
  bool walls[4] = {true, true, true, true};
};

class Command {
 public:
  virtual ~Command(){};
  virtual void Execute(std::vector<std::vector<int>> &data) = 0;
};

class OpenCommand : public Command {
 public:
  OpenCommand(std::string str);
  ~OpenCommand();
  void Execute(std::vector<std::vector<int>> &data) override;

 private:
  std::string file_;
};

class SaveCommand : public Command {
 public:
  SaveCommand(std::string str);
  ~SaveCommand();
  void Execute(std::vector<std::vector<int>> &data) override;

 private:
  std::string file_;
};

// Generation maze
class GenCommand : public Command {
 public:
  GenCommand(int r = 1, int col = 1);
  ~GenCommand();
  void Execute(std::vector<std::vector<int>> &data) override;

 private:
  void Fill(std::vector<int> &line, std::vector<int> &set);
  int GetSet(std::vector<int> &set);
  void RightWall(int row, std::vector<int> &line, std::vector<int> &set,
                 std::vector<std::vector<int>> &maze);
  void BotWall(int row, std::vector<int> &line, std::vector<int> &set,
               std::vector<std::vector<int>> &maze);
  void EndWall(int row, std::vector<int> &line,
               std::vector<std::vector<int>> &maze);
  void MergeSet(int from, int to, std::vector<int> &line);

 private:
  int row_, col_;
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> distrib;
};

// Generation2 maze
class GenCommandS : public Command {
 public:
  GenCommandS(int r = 1, int c = 1);
  ~GenCommandS();
  void Execute(std::vector<std::vector<int>> &data) override;

 private:
  bool isValid(int x, int y);
  void removeWall(int x1, int y1, int x2, int y2);

 private:
  int row_, col_;
  std::vector<std::vector<Cell>> maze;
  std::random_device rd;
  std::mt19937 gen;
  std::uniform_int_distribution<> distrib;
};

// Solve maze
class SolveCommand : public Command {
 public:
  SolveCommand(int sr = 1, int sc = 1, int er = 1, int ec = 1);
  ~SolveCommand();
  void Execute(std::vector<std::vector<int>> &data) override;
  std::vector<std::vector<int>> &GetSolve();

 private:
  void AddPath(std::unordered_map<int, int> &parent, int b);

 private:
  int sr_, sc_, er_, ec_;
  std::vector<std::vector<int>> solve_;
};

class AgentCommand : public Command {
 public:
  AgentCommand(int sr, int sc, int er, int ec,
               std::vector<std::vector<double>> &table);
  ~AgentCommand();
  void Execute(std::vector<std::vector<int>> &data) override;
  std::vector<std::vector<int>> &GetSolve();

 private:
  int GetMax(int state);

 private:
  int sr_, sc_, er_, ec_;
  std::vector<std::vector<int>> maze_;
  std::vector<std::vector<double>> qtable_;
};
}  // end namespace s21
#endif  //_MAZE_MODEL_COMMAND_COMMAND_H_
