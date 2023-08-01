#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  MainWindow w;
  w.setWindowTitle("3DViewer v1.0");
  QPixmap pix(":/img/pic.png");
  QPalette pal;
  pal.setBrush(w.backgroundRole(), QBrush(pix));
  w.setPalette(pal);
  w.setAutoFillBackground(true);
  w.resize(1004, 580);
  w.show();
  return a.exec();
}
