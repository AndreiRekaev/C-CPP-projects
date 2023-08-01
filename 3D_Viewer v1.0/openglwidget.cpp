#include "openglwidget.h"

#include "ui_openglwidget.h"

OpenGLWidget::OpenGLWidget(QWidget *parent)
    : QOpenGLWidget(parent), ui(new Ui::OpenGLWidget) {
  ui->setupUi(this);
  V = new matrix_t;
  V->matrix = NULL;
  V->element_array = NULL;
  vbo = 0;
  ebo = 0;
  pos_x = 0;
  pos_y = 0;
  pos_z = 0;
  rot_x = 0;
  rot_y = 0;
  rot_z = 0;
  scale = 1;
}

OpenGLWidget::~OpenGLWidget() {
  deleteBuffers();
  remove_matrix(V);
  delete V;
  delete ui;
}

void OpenGLWidget::initializeGL() {
  QOpenGLFunctions *pFunc = QOpenGLContext::currentContext()->functions();
  pFunc->glClearColor(1.0f, 1.0f, 1.0f, 0.0f);
  glClearDepth(1.0);
  pFunc->glEnable(GL_DEPTH_TEST);
}

void OpenGLWidget::resizeGL(int w, int h) {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glViewport(0, 0, (GLint)w, (GLint)h);
  // qDebug() << w << h;
}

void OpenGLWidget::paintGL() {
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
  projection();
  glClearColor(color_back.redF(), color_back.greenF(), color_back.blueF(),
               color_back.alphaF());
  glClearDepth(1.0);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  glPointSize(vertex_size);
  glLineWidth(line_size);
  glShadeModel(GL_FLAT);

  if (V && V->matrix) draw();
}

void OpenGLWidget::projection() {
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  int width = (V->minmax[1] - V->minmax[0]) + 1;
  int height = (V->minmax[3] - V->minmax[2]) + 1;
  int depth = (V->minmax[5] - V->minmax[4]) + 1;
  if (width < height) width = height;
  if (width < depth) width = depth;
  int w = this->width(), h = this->height();
  double ratio = (w > h) ? (double)w / h : (double)h / w;
  if (!proection) {
    if (w > h)
      glOrtho(-width * ratio, width * ratio, -width, width, -width * 2,
              width * 2);
    if (h >= w)
      glOrtho(-width, width, -width * ratio, width * ratio, -width * 2,
              width * 2);
  }
  if (proection) {
    if (w > h) glFrustum(-1 * ratio, 1 * ratio, -1, 1, 1, width * 3 + 1);
    if (h >= w) glFrustum(-1, 1, -1 * ratio, 1 * ratio, 1, width * 3 + 1);
    glTranslated(0, 0, -width);
  }
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}
void OpenGLWidget::draw() {
  glVertexPointer(3, GL_DOUBLE, 0, V->matrix[0]);
  glEnableClientState(GL_VERTEX_ARRAY);
  if (vbo == 0 || ebo == 0) {
    glGenBuffers(1, &vbo);
    glGenBuffers(1, &ebo);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, V->avip * sizeof(int),
                 V->element_array, GL_STATIC_DRAW);
  }
  glBindBuffer(GL_ARRAY_BUFFER, vbo);
  glBufferData(GL_ARRAY_BUFFER, V->rows * V->columns * sizeof(double),
               V->matrix[0], GL_DYNAMIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);

  // glVertexAttribPointer(0, 3, GL_DOUBLE, GL_FALSE, 0, (void *)0);

  glColor3f(color_vert.redF(), color_vert.greenF(), color_vert.blueF());
  if (vertex_shape) {
    if (vertex_shape == 1) glEnable(GL_POINT_SMOOTH);
    glDrawArrays(GL_POINTS, 0, V->rows);
    if (vertex_shape == 1) glDisable(GL_POINT_SMOOTH);
  }
  // polygons пунктирная
  if (pattern) glEnable(GL_LINE_STIPPLE);
  glLineStipple(2, 0x00FF);

  glColor3f(color_edge.redF(), color_edge.greenF(), color_edge.blueF());
  glDrawElements(GL_LINES, V->avip, GL_UNSIGNED_INT, (void *)0);
  glDisable(GL_LINE_STIPPLE);

  // glDisableVertexAttribArray(0);
  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
  glDisableClientState(GL_VERTEX_ARRAY);
  glFlush();
}

void OpenGLWidget::save_pic() {
  QFileDialog fileDialog;
  fileDialog.setAcceptMode(QFileDialog::AcceptSave);
  QString name = fileDialog.getSaveFileName(
      this, QString("сохранить картинку"),
      QCoreApplication::applicationDirPath(), "BMP (*.bmp);; JPEG(*.jpeg)");
  if (name != "") {
    QImage img = this->grabFramebuffer();
    img.save(name, NULL, 100);
  }
}

void OpenGLWidget::gif() {
  QFileDialog fileDialog;
  fileDialog.setAcceptMode(QFileDialog::AcceptSave);
  QString name = fileDialog.getSaveFileName(
      this, QString("сохранить гифку"), QCoreApplication::applicationDirPath(),
      "*.gif");
  if (name != "") {
    int w = this->width() * 2, h = this->height() * 2, delay = 100;
    QGifImage *gif = new QGifImage(QSize(w, h));
    gif->setDefaultDelay(delay);
    QTest::qWait(delay);
    emit osig(1);
    for (int i = 0; i < 50; ++i) {
      QImage img = this->grabFramebuffer();
      // img = img.scaled(640, 480, Qt::IgnoreAspectRatio,
      // Qt::FastTransformation);
      gif->addFrame(img, QPoint(0, 0));
      QTest::qWait(delay);
    }
    emit osig(0);
    gif->save(name);
    delete gif;
  }
}
void OpenGLWidget::deleteBuffers() {
  if (vbo) glDeleteBuffersARB(1, &vbo);
  if (ebo) glDeleteBuffersARB(1, &ebo);
  vbo = 0;
  ebo = 0;
}
