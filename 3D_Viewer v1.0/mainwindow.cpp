#include "mainwindow.h"

#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::MainWindow),
      my_settings("DreamTeam", "3DViewer") {
  ui->setupUi(this);
  readSettings();
  connect(ui->pushButton_open, SIGNAL(clicked()), SLOT(pushButton_open()));
  connect(ui->openGLWidget, SIGNAL(osig(int)), this, SLOT(changeName(int)));
}

MainWindow::~MainWindow() {
  writeSettings();
  delete ui;
}

void MainWindow::pushButton_open() {
  QFileDialog *file = new QFileDialog();
  QString name = file->getOpenFileName(
      0, "Open file", QCoreApplication::applicationDirPath(), "");
  delete file;
  if (name != "") {
    ui->openGLWidget->deleteBuffers();
    clean_rt();
    std::string str = name.toUtf8().constData();
    const char *input = str.c_str();
    if (ui->openGLWidget->V && ui->openGLWidget->V->matrix)
      remove_matrix(ui->openGLWidget->V);
    int res = parse(input, ui->openGLWidget->V);
    if (!res) {
      center();
      ui->openGLWidget->paintGL();
      count_edge();
    }
    info(name);
  }
}
void MainWindow::center() {
  if (ui->openGLWidget->V && ui->openGLWidget->V->matrix) {
    matrix_t *ptr = ui->openGLWidget->V;
    double x = (ptr->minmax[1] - ptr->minmax[0]) / 2;
    double y = (ptr->minmax[3] - ptr->minmax[2]) / 2;
    translation_x(ptr, -(ptr->minmax[1] - x));
    translation_y(ptr, -(ptr->minmax[3] - y));
  }
}
void MainWindow::info(QString path) {
  ui->info->setText("");
  if (ui->openGLWidget->V && path != "") {
    QFileInfo fname(path);
    QString name = fname.fileName();
    ui->info->setText(
        "Название файла: " + name +
        "\nКолличество вершин: " + QString::number(ui->openGLWidget->V->rows) +
        "\nКолличество ребер: " + QString::number(ui->openGLWidget->V->count));
  }
}

// возможно ненужный подсчет уникальных ребер, дает тормоза при загрузе файла
void MainWindow::count_edge() {
  if (ui->openGLWidget->V && ui->openGLWidget->V->element_array) {
    QSet<long int> edge;
    edge.reserve(ui->openGLWidget->V->avip / 2);
    int *ptr = ui->openGLWidget->V->element_array;
    for (int i = 0; i < ui->openGLWidget->V->avip; i += 2) {
      if (i) ptr++;
      long int temp = 0, x = *ptr++, y = *ptr;
      if (x < y) {
        temp = (x << 32) + y;
        edge.insert(temp);
      } else if (x > y) {
        temp = (y << 32) + x;
        edge.insert(temp);
      }
    }
    ui->openGLWidget->V->count = edge.size();
  }
}
// clean spinBox for translate and rotation
void MainWindow::clean_rt() {
  ui->rotation_x->setValue(0);
  ui->rotation_y->setValue(0);
  ui->rotation_z->setValue(0);
  ui->translate_x->setValue(0);
  ui->translate_y->setValue(0);
  ui->translate_z->setValue(0);
  ui->zoom->setValue(1);
}

// color back, vertexes and edge
void MainWindow::on_pushButton_back_clicked() {
  QColor temp = QColorDialog::getColor(Qt::white);
  if (temp.isValid()) {
    ui->openGLWidget->color_back.setRgb(temp.rgb());
    ui->openGLWidget->update();
  }
}
void MainWindow::on_pushButton_vert_clicked() {
  QColor temp = QColorDialog::getColor(Qt::white);
  if (temp.isValid()) {
    ui->openGLWidget->color_vert.setRgb(temp.rgb());
    ui->openGLWidget->update();
  }
}
void MainWindow::on_pushButton_edge_clicked() {
  QColor temp = QColorDialog::getColor(Qt::white);
  if (temp.isValid()) {
    ui->openGLWidget->color_edge.setRgb(temp.rgb());
    ui->openGLWidget->update();
  }
}

// width points and edge, patter edge
void MainWindow::on_spinBox_vertex_valueChanged(int arg1) {
  ui->openGLWidget->vertex_size = arg1;
  ui->openGLWidget->update();
}
void MainWindow::on_doubleSpinBox_edge_valueChanged(double arg1) {
  ui->openGLWidget->line_size = arg1;
  ui->openGLWidget->update();
}

void MainWindow::on_stipple_stateChanged(int arg1) {
  ui->openGLWidget->pattern = arg1;
  ui->openGLWidget->update();
}

// form vertexes
void MainWindow::on_comboBox_form_currentIndexChanged(int index) {
  ui->openGLWidget->vertex_shape = index;
  ui->openGLWidget->update();
}

// change proection
void MainWindow::on_radioButton_frustum_clicked() {
  ui->openGLWidget->proection = 1;
  ui->openGLWidget->update();
}
void MainWindow::on_radioButton_ortho_clicked() {
  ui->openGLWidget->proection = 0;
  ui->openGLWidget->update();
}
// zoom
void MainWindow::on_zoom_plus_clicked() {
  double &x = ui->openGLWidget->scale, old = x, step = ui->zoom->singleStep();
  if (x + step <= 1024) {
    x += step;
  } else {
    x = 1024;
  }
  if (old != x) {
    int res = zoom(ui->openGLWidget->V, x / old);
    if (!res) ui->openGLWidget->update();
    display_value();
  }
}
void MainWindow::on_zoom_minus_clicked() {
  double &x = ui->openGLWidget->scale, old = x, step = ui->zoom->singleStep();
  if (x - step >= 0.015625) {
    x -= step;
  } else {
    x = 0.015625;
  }
  if (old != x) {
    int res = zoom(ui->openGLWidget->V, x / old);
    if (!res) ui->openGLWidget->update();
    display_value();
  }
}
void MainWindow::on_zoom_valueChanged(double arg1) {
  double zoom_ratio = arg1 / ui->openGLWidget->scale;
  if (zoom_ratio != 1) {
    ui->openGLWidget->scale = arg1;
    int res = zoom(ui->openGLWidget->V, zoom_ratio);
    if (!res) ui->openGLWidget->update();
    display_value();
  }
}
void MainWindow::display_value() {
  double &x = ui->openGLWidget->scale;
  ui->zoom->setValue(x);
}
// rotation
// around x
void MainWindow::on_pushButton_xr_clicked() {
  double angle = ui->rotation_x->singleStep() * M_RAD;
  if (angle) {
    int res = around_x(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_x_editingFinished();
}
void MainWindow::on_pushButton_xl_clicked() {
  double angle = ui->rotation_x->singleStep() * M_RAD;
  if (angle) {
    int res = around_x(ui->openGLWidget->V, -angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_x_editingFinished();
}
void MainWindow::on_rotation_x_valueChanged(double arg1) {
  double x = arg1 - ui->openGLWidget->rot_x;
  ui->openGLWidget->rot_x = fmod(arg1, 360);
  ui->rotation_x->setValue(ui->openGLWidget->rot_x);
  double angle = x * M_RAD;
  if (x) {
    int res = around_x(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
}

void MainWindow::on_rotation_x_editingFinished() {
  ui->openGLWidget->rot_x = 0;
  ui->rotation_x->setValue(0);
}
// around y
void MainWindow::on_pushButton_7_clicked() {
  double angle = ui->rotation_y->singleStep() * M_RAD;
  if (angle) {
    int res = around_y(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_y_editingFinished();
}
void MainWindow::on_pushButton_8_clicked() {
  double angle = ui->rotation_y->singleStep() * M_RAD;
  if (angle) {
    int res = around_y(ui->openGLWidget->V, -angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_y_editingFinished();
}
void MainWindow::on_rotation_y_valueChanged(double arg1) {
  double y = arg1 - ui->openGLWidget->rot_y;
  ui->openGLWidget->rot_y = fmod(arg1, 360);
  ui->rotation_y->setValue(ui->openGLWidget->rot_y);
  double angle = y * M_RAD;
  if (y) {
    int res = around_y(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
}

void MainWindow::on_rotation_y_editingFinished() {
  ui->openGLWidget->rot_y = 0;
  ui->rotation_y->setValue(0);
}
// around z
void MainWindow::on_pushButton_9_clicked() {
  double angle = ui->rotation_z->singleStep() * M_RAD;
  if (angle) {
    int res = around_z(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_z_editingFinished();
}
void MainWindow::on_pushButton_10_clicked() {
  double angle = ui->rotation_z->singleStep() * M_RAD;
  if (angle) {
    int res = around_z(ui->openGLWidget->V, -angle);
    if (!res) ui->openGLWidget->update();
  }
  on_rotation_z_editingFinished();
}
void MainWindow::on_rotation_z_valueChanged(double arg1) {
  double z = arg1 - ui->openGLWidget->rot_z;
  ui->openGLWidget->rot_z = fmod(arg1, 360);
  ui->rotation_z->setValue(ui->openGLWidget->rot_z);
  double angle = z * M_RAD;
  if (z) {
    int res = around_z(ui->openGLWidget->V, angle);
    if (!res) ui->openGLWidget->update();
  }
}
void MainWindow::on_rotation_z_editingFinished() {
  ui->openGLWidget->rot_z = 0;
  ui->rotation_z->setValue(0);
}

// translation
// along x
void MainWindow::on_translate_x_right_clicked() {
  ui->translate_x->setValue(ui->translate_x->value() +
                            ui->translate_x->singleStep());
}
void MainWindow::on_translate_x_left_clicked() {
  ui->translate_x->setValue(ui->translate_x->value() -
                            ui->translate_x->singleStep());
}
void MainWindow::on_translate_x_valueChanged(double arg1) {
  double x = arg1 - ui->openGLWidget->pos_x;
  ui->openGLWidget->pos_x = arg1;
  if (x) {
    int res = translation_x(ui->openGLWidget->V, x);
    if (!res) ui->openGLWidget->update();
  }
}

// along y
void MainWindow::on_translate_y_right_clicked() {
  ui->translate_y->setValue(ui->translate_y->value() +
                            ui->translate_y->singleStep());
}
void MainWindow::on_translate_y_left_clicked() {
  ui->translate_y->setValue(ui->translate_y->value() -
                            ui->translate_y->singleStep());
}
void MainWindow::on_translate_y_valueChanged(double arg1) {
  double y = arg1 - ui->openGLWidget->pos_y;
  ui->openGLWidget->pos_y = arg1;
  if (y) {
    int res = translation_y(ui->openGLWidget->V, y);
    if (!res) ui->openGLWidget->update();
  }
}

// along z
void MainWindow::on_translate_z_right_clicked() {
  ui->translate_z->setValue(ui->translate_z->value() +
                            ui->translate_z->singleStep());
}
void MainWindow::on_translate_z_left_clicked() {
  ui->translate_z->setValue(ui->translate_z->value() -
                            ui->translate_z->singleStep());
}
void MainWindow::on_translate_z_valueChanged(double arg1) {
  double z = arg1 - ui->openGLWidget->pos_z;
  ui->openGLWidget->pos_z = arg1;
  if (z) {
    int res = translation_z(ui->openGLWidget->V, z);
    if (!res) ui->openGLWidget->update();
  }
}

// change step
void MainWindow::on_rotation_x_step_valueChanged(double arg1) {
  ui->rotation_x->setSingleStep(arg1);
}
void MainWindow::on_rotation_y_step_valueChanged(double arg1) {
  ui->rotation_y->setSingleStep(arg1);
}
void MainWindow::on_rotation_z_step_valueChanged(double arg1) {
  ui->rotation_z->setSingleStep(arg1);
}
void MainWindow::on_translate_x_step_valueChanged(double arg1) {
  ui->translate_x->setSingleStep(arg1);
}
void MainWindow::on_translate_y_step_valueChanged(double arg1) {
  ui->translate_y->setSingleStep(arg1);
}
void MainWindow::on_translate_z_step_valueChanged(double arg1) {
  ui->translate_z->setSingleStep(arg1);
}
void MainWindow::on_zoom_step_valueChanged(double arg1) {
  ui->zoom->setSingleStep(arg1);
}

// Settings
void MainWindow::writeSettings() {
  my_settings.beginGroup("/Settings");
  my_settings.setValue("/vertex_shape", ui->openGLWidget->vertex_shape);
  my_settings.setValue("/vertex_size", ui->openGLWidget->vertex_size);
  my_settings.setValue("/vertex_color", ui->openGLWidget->color_vert.name());
  my_settings.setValue("/edge_color", ui->openGLWidget->color_edge.name());
  my_settings.setValue("/back_color", ui->openGLWidget->color_back.name());
  my_settings.setValue("/edge_width", ui->openGLWidget->line_size);
  my_settings.setValue("/edge_pattern", ui->openGLWidget->pattern);
  my_settings.setValue("/proection", ui->openGLWidget->proection);
  my_settings.endGroup();
}

void MainWindow::readSettings() {
  my_settings.beginGroup("/Settings");
  ui->openGLWidget->vertex_shape =
      my_settings.value("/vertex_shape", "0").toInt();
  ui->openGLWidget->vertex_size =
      my_settings.value("/vertex_size", "5").toInt();
  ui->openGLWidget->line_size =
      my_settings.value("/edge_width", "1").toDouble();
  ui->openGLWidget->pattern = my_settings.value("/edge_pattern", "0").toInt();
  ui->openGLWidget->proection = my_settings.value("/proection", "0").toInt();
  ui->openGLWidget->color_vert.setRgb(
      QColor((my_settings.value("/vertex_color", "#ff0000").toString())).rgb());
  ui->openGLWidget->color_edge.setRgb(
      QColor((my_settings.value("/edge_color", "#0000ff").toString())).rgb());
  ui->openGLWidget->color_back.setRgb(
      QColor((my_settings.value("/back_color", "#ffffff").toString())).rgb());

  ui->comboBox_form->setCurrentIndex(ui->openGLWidget->vertex_shape);
  ui->spinBox_vertex->setValue(ui->openGLWidget->vertex_size);
  ui->doubleSpinBox_edge->setValue(ui->openGLWidget->line_size);
  ui->stipple->setChecked(ui->openGLWidget->pattern);
  if (ui->openGLWidget->proection) ui->radioButton_frustum->setChecked(true);
  my_settings.endGroup();
}

void MainWindow::on_pushButton_save_clicked() { ui->openGLWidget->save_pic(); }

void MainWindow::on_pushButton_gif_clicked() { ui->openGLWidget->gif(); }

void MainWindow::changeName(int x) {
  if (x) ui->saving->setText("запись");
  if (!x) ui->saving->setText("");
}
