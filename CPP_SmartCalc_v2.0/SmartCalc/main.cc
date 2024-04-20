#include <QApplication>
#include <QLocale>

#include "view/view.h"

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  setlocale(LC_NUMERIC, "en_US.UTF8");
  QLocale::setDefault(QLocale("en_US.UTF8"));
  s21::View w(nullptr);
  w.show();
  return a.exec();
}
