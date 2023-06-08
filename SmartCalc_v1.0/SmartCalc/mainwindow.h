#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <qcustomplot.h>

#include <QKeyEvent>
#include <QMainWindow>
#include <QTimer>
#include <QVector>
#include <QtMath>
#include <iostream>

extern "C" {
#include "s21_smartcalc.h"
}
QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private:
  Ui::MainWindow *ui;
  QVector<double> X, Y;
  double minX = 0.0, maxX = 0.0, minY = 0.0, maxY = 0.0;

 private slots:
  void input_operations();
  void input_numbers();
  void result_after_equals();
  void all_clean();
  void one_delete();
  void on_page_1lb_clicked(bool checked);
  void on_page_2lb_clicked(bool checked);
  void on_page_3lb_clicked(bool checked);
  void on_page_4lb_clicked(bool checked);
  void make_graphic();
  void keyPressEvent(QKeyEvent *e);
  void axis_x_y(double x1, double x2);
  void on_calculate_credit_clicked();
  void on_clear_graphic_clicked();
  void on_clear_credit_clicked();
  void on_calculate_depozit_clicked();
  void on_clear_depozit_clicked();
  void on_MainWindow_iconSizeChanged(const QSize &iconSize);
};
#endif  // MAINWINDOW_H
