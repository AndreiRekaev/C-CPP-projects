#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QColorDialog>
#include <QFileDialog>
#include <QFileInfo>
#include <QMainWindow>
#include <QPalette>
#include <QPixmap>
#include <QScrollArea>
#include <QSettings>
#include <QString>
#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <iostream>

#include "3DViewer.h"
#include "openglwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

/**
 * @brief The MainWindow class Главное окно, содержит панель настроек и область
 * вывода изображения.
 */
class MainWindow : public QMainWindow {
  Q_OBJECT

  QSettings my_settings;

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();
  /**
   * @brief writeSettings запись настроек
   */
  void writeSettings();
  /**
   * @brief readSettings считывание настроек
   */
  void readSettings();

 private slots:
  void info(QString name);
  void count_edge();
  void clean_rt();
  void pushButton_open();
  void center();
  // color back, vertex and edge
  void on_pushButton_back_clicked();
  void on_pushButton_vert_clicked();
  void on_pushButton_edge_clicked();

  // width point and edge, edge pattern
  void on_spinBox_vertex_valueChanged(int arg1);
  void on_doubleSpinBox_edge_valueChanged(double arg1);
  void on_stipple_stateChanged(int arg1);

  // form vertexes
  void on_comboBox_form_currentIndexChanged(int index);

  // change proection
  void on_radioButton_frustum_clicked();
  void on_radioButton_ortho_clicked();

  // zoom
  void on_zoom_plus_clicked();
  void on_zoom_minus_clicked();
  void on_zoom_valueChanged(double arg1);
  void display_value();

  // translate x
  void on_translate_x_right_clicked();
  void on_translate_x_left_clicked();
  void on_translate_x_valueChanged(double arg1);
  // translate y
  void on_translate_y_right_clicked();
  void on_translate_y_left_clicked();
  void on_translate_y_valueChanged(double arg1);
  // translate z
  void on_translate_z_right_clicked();
  void on_translate_z_left_clicked();
  void on_translate_z_valueChanged(double arg1);

  // rotatin x
  void on_pushButton_xr_clicked();
  void on_pushButton_xl_clicked();
  void on_rotation_x_valueChanged(double arg1);
  // rotation y
  void on_pushButton_7_clicked();
  void on_pushButton_8_clicked();
  void on_rotation_y_valueChanged(double arg1);
  // rotation z
  void on_pushButton_9_clicked();
  void on_pushButton_10_clicked();
  void on_rotation_z_valueChanged(double arg1);

  // change step in doubleSpinBox
  void on_rotation_x_step_valueChanged(double arg1);
  void on_rotation_y_step_valueChanged(double arg1);
  void on_rotation_z_step_valueChanged(double arg1);
  void on_translate_x_step_valueChanged(double arg1);
  void on_translate_y_step_valueChanged(double arg1);
  void on_translate_z_step_valueChanged(double arg1);
  void on_zoom_step_valueChanged(double arg1);

  // save picture and gif
  void on_pushButton_save_clicked();
  void on_pushButton_gif_clicked();
  void changeName(int x);

  void on_rotation_x_editingFinished();

  void on_rotation_y_editingFinished();

  void on_rotation_z_editingFinished();

 private:
  Ui::MainWindow *ui;
  OpenGLWidget *open;
};
#endif  // MAINWINDOW_H
