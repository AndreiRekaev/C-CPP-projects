#ifndef OPENGLWIDGET_H
#define OPENGLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QBitmap>
#include <QFile>
#include <QFileDialog>
#include <QPoint>
#include <QString>
#include <QTest>
#include <QWidget>
#include <QtOpenGL>
#include <QtOpenGLWidgets/QOpenGLWidget>
#include <iostream>

#include "3DViewer.h"
#include "qgifimage.h"

namespace Ui {
class OpenGLWidget;
}

class OpenGLWidget : public QOpenGLWidget {
  Q_OBJECT

 signals:
  void osig(int x);

 public:
  explicit OpenGLWidget(QWidget *parent = nullptr);
  ~OpenGLWidget();
  /**
   * @brief V указатель на структуру matrix_t
   */
  matrix_t *V;

  QColor color_back, /**< цвет фона */
      color_vert,    /**< цвет вершин*/
      color_edge;    /**< цвет ребер */
  int vertex_size,   /**< размер вершин */
      vertex_shape, /**< форма вершин (0-нет, 1-круг, 2-квадрат) */
      proection, /**< вид проекции (0-ортогональная, 1-перспективная) */
      pattern; /**< форма ребер (0-сплошная, 1-пунктирная) */
  double line_size; /**< толщина ребер*/
  double rot_x, rot_y, rot_z, pos_x, pos_y, pos_z, scale;

  // protected:
  /**
   * @brief initializeGL Эта функция должна настроить все необходимые ресурсы
   * OpenGL.
   */
  virtual void initializeGL();

  /**
   * @brief resizeGL Эта виртуальная функция вызывается всякий раз, когда
   * изменяется размер виджета
   * @param w ширина
   * @param h высота
   */
  virtual void resizeGL(int w, int h);

  /**
   * @brief paintGL функция вызывается всякий раз, когда виджет необходимо
   * отрисовать
   */
  virtual void paintGL();

  /**
   * @brief projection Выбор проекции отображения
   */
  void projection();

  /**
   * @brief draw отрисовка точек и полигонов
   */
  void draw();

  /**
   * @brief save_pic Сохранение данных из фреймбуфера на диск в формате bmp или
   * jpeg
   */
  void save_pic();

  /**
   * @brief gif Сохранение 5 секундной гифки на диск
   */
  void gif();

  /**
   * @brief deleteBuffers Удаление буферов хранения данных
   */
  void deleteBuffers();

 private:
  Ui::OpenGLWidget *ui;
  GLuint vbo, ebo;
};

#endif  // OPENGLWIDGET_H
