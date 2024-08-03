#ifndef _MAZE_VIEW_DRAW_DRAW_H_
#define _MAZE_VIEW_DRAW_DRAW_H_

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

#include "../../model/command/command.h"

namespace s21 {

class Draw : public QWidget {
  Q_OBJECT
 public:
  explicit Draw(QWidget *parent = nullptr);
  void pass(std::vector<std::vector<int>> &);
 signals:
 protected:
  void paintEvent(QPaintEvent *even) override;

 private:
  std::vector<std::vector<int>> data_;
};

}  // namespace s21

#endif  // _MAZE_VIEW_DRAW_DRAW_H_
