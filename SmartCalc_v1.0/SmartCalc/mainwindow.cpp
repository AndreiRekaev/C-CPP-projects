#include "mainwindow.h"

#include "./ui_mainwindow.h"
using namespace std;

#ifndef HAVE_STRLCAT
/*
 * '_cups_strlcat()' - Safely concatenate two strings.
 */

size_t                   /* O - Length of string */
strlcat(char *dst,       /* O - Destination string */
        const char *src, /* I - Source string */
        size_t size)     /* I - Size of destination string buffer */
{
  size_t srclen; /* Length of source string */
  size_t dstlen; /* Length of destination string */

  /*
   * Figure out how much room is left...
   */

  dstlen = strlen(dst);
  size -= dstlen + 1;

  if (!size) return (dstlen); /* No room, return immediately... */

  /*
   * Figure out how much room is needed...
   */

  srclen = strlen(src);

  /*
   * Copy the appropriate amount...
   */

  if (srclen > size) srclen = size;

  memcpy(dst + dstlen, src, srclen);
  dst[dstlen + srclen] = '\0';

  return (dstlen + srclen);
}
#endif /* !HAVE_STRLCAT */

#ifndef HAVE_STRLCPY
/*
 * '_cups_strlcpy()' - Safely copy two strings.
 */

size_t                   /* O - Length of string */
strlcpy(char *dst,       /* O - Destination string */
        const char *src, /* I - Source string */
        size_t size)     /* I - Size of destination string buffer */
{
  size_t srclen; /* Length of source string */

  /*
   * Figure out how much room is needed...
   */

  size--;

  srclen = strlen(src);

  /*
   * Copy the appropriate amount...
   */

  if (srclen > size) srclen = size;

  memcpy(dst, src, srclen);
  dst[srclen] = '\0';

  return (srclen);
}
#endif /* !HAVE_STRLCPY */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  ui->stackedWidget->setCurrentIndex(0);
  ui->page_1lb->setChecked(true);

  ui->graphic->setInteraction(QCP::iRangeZoom, true);
  ui->graphic->setInteraction(QCP::iRangeDrag, true);

  connect(ui->pushButton_0, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_1, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_2, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_3, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_4, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_5, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_6, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_7, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_8, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->pushButton_9, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->add_x, SIGNAL(clicked()), this, SLOT(input_numbers()));
  connect(ui->right_bracket, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->left_bracket, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->sqrt, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->plus, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->minus, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->multiplication, SIGNAL(clicked()), this,
          SLOT(input_operations()));
  connect(ui->division, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->exp, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->mod, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->sin, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->cos, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->tan, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->asin, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->acos, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->atan, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->ln, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->lg, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->dot, SIGNAL(clicked()), this, SLOT(input_operations()));
  connect(ui->AC, SIGNAL(clicked()), this, SLOT(all_clean()));
  connect(ui->one_delete, SIGNAL(clicked()), this, SLOT(one_delete()));
  connect(ui->equals, SIGNAL(clicked()), this, SLOT(result_after_equals()));

  connect(ui->make_graphic, SIGNAL(clicked()), this, SLOT(make_graphic()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::keyPressEvent(QKeyEvent *e) {
  if (e->key() == Qt::Key_Enter || e->key() == Qt::Key_Return) {
    result_after_equals();
  } else if (e->key() == Qt::Key_Escape) {
    this->close();
  }
}

void MainWindow::input_operations() {
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = (ui->result_show->text() + button->text());
  ui->result_show->setText(string);
}

void MainWindow::input_numbers() {
  QPushButton *button = (QPushButton *)sender();
  QString string;
  string = (ui->result_show->text() + button->text());
  ui->result_show->setText(string);
}

void MainWindow::one_delete() {
  QString text = ui->result_show->text();
  text.chop(1);
  if (text.isEmpty()) {
    text = "";
  }
  ui->result_show->setText(text);
}

void MainWindow::all_clean() { ui->result_show->setText(""); }

void MainWindow::result_after_equals() {
  QString input_expression = ui->result_show->text();
  QByteArray bytes_expression = input_expression.toLocal8Bit();
  char input_string[256];
  strlcpy(input_string, bytes_expression.data(), 256);

  QString value_x = ui->added_x->text();
  QByteArray bytes_value_x = value_x.toLocal8Bit();
  char input_x[256];
  strlcpy(input_x, bytes_value_x.data(), 256);

  if (validation(input_string) == 0) {
    s21_stack *one = NULL, *one_rev = NULL, *two = NULL, *three = NULL,
              *rpn_s = NULL, *rpn_n = NULL;
    double x_value = atof(input_x);
    if (!parser(input_string, &one, x_value)) {
      reverse_stack(&one, &one_rev);
      rev_polish_notation(&one_rev, &rpn_n, &rpn_s);
      reverse_stack(&rpn_n, &two);
      calculator(&two, &three);
      QString value = QString::number((double)three->value, 'f', 7);
      ui->result_show->setText(value);
      pop(&three);
    } else {
      QString new_label = "Invalid input expression";
      ui->result_show->setText(new_label);
    }
  } else {
    QString new_label = "Invalid input expression";
    ui->result_show->setText(new_label);
  }
}

void MainWindow::make_graphic() {
  double x1 = std::atof(ui->value_x1->text().toLocal8Bit().data());
  double x2 = std::atof(ui->value_x2->text().toLocal8Bit().data());

  QString input_expression = ui->function->text();
  QByteArray bytes_expression = input_expression.toLocal8Bit();
  char input_x[256];
  strlcpy(input_x, bytes_expression.data(), 256);
  axis_x_y(x1, x2);
  s21_stack *one = NULL, *one_rev = NULL, *two = NULL, *three = NULL,
            *rpn_s = NULL, *rpn_n = NULL;
  // char string[256] = {'1'};
  if (validation(input_x) == 0) {
    double h = std::atof(ui->step->text().toLocal8Bit().data());
    if (!h) {
      h = 0.1;
    }
    while (x1 <= x2) {
      X.push_back(x1);
      if (!parser(input_x, &one, x1)) {
        reverse_stack(&one, &one_rev);
        rev_polish_notation(&one_rev, &rpn_n, &rpn_s);
        reverse_stack(&rpn_n, &two);
        calculator(&two, &three);
        double y = (double)three->value;
        Y.push_back(y);
        pop(&three);
        x1 += h;
      } else {
        ui->function->setText("invalid values");
      }
      ui->graphic->addGraph();
      ui->graphic->graph(0)->addData(X, Y);
      ui->graphic->graph(0)->setPen(QPen(QColor(153, 168, 77)));
      ui->graphic->replot();
    }
  }
}

void MainWindow::axis_x_y(double x1, double x2) {
  minX = std::atof(ui->min_x->text().toLocal8Bit().data());
  maxX = std::atof(ui->max_x->text().toLocal8Bit().data());
  minY = std::atof(ui->min_y->text().toLocal8Bit().data());
  maxY = std::atof(ui->max_y->text().toLocal8Bit().data());
  if (minX != 0 && !minX) {
    minX = x1;
  } else if (maxX != 0 && !maxX) {
    maxX = x2;
  } else if (minY != 0 && !minY) {
    minY = x1;
  } else if (maxY != 0 && !maxY) {
    maxY = x2;
  } else if (!minX && !maxX && !minY && !maxY) {
    minX = x1;
    maxX = x2;
    minY = x1;
    maxY = x2;
  }
  ui->graphic->xAxis->setRange(minX, maxX);
  ui->graphic->yAxis->setRange(minY, maxY);
}

void MainWindow::on_calculate_credit_clicked() {
  double credit = std::atof(ui->credit->text().toLocal8Bit().data());
  double interest_rate =
      std::atof(ui->interest_rate->text().toLocal8Bit().data());
  int period = std::atof(ui->period->text().toLocal8Bit().data());

  double res_credit[4] = {0};

  if (credit <= 0 || interest_rate <= 0 || period <= 0) {
    ui->monthly_payment->setText("invalid values");
    ui->overpayment->setText("invalid values");
    ui->total_payment->setText("invalid values");
  } else {
    if (ui->annu->isChecked()) {
      annu_credit_calc(res_credit, credit, interest_rate, period);
      QString monthly_payment = QString::number(res_credit[0], 'f', 7);
      ui->monthly_payment->setText(monthly_payment);
    } else if (ui->diff->isChecked()) {
      diff_credit_calc(res_credit, credit, interest_rate, period);
      QString monthly_payment_first = QString::number(res_credit[0], 'f', 7);
      QString monthly_payment_end = QString::number(res_credit[3], 'f', 7);
      QString text =
          QString("%1 %2 %3")
              .arg(monthly_payment_first, "...", monthly_payment_end);
      ui->monthly_payment->setText(text);
    }
    QString overpayment = QString::number(res_credit[2], 'f', 7);
    QString total_payment = QString::number(res_credit[1], 'f', 7);
    ui->overpayment->setText(overpayment);
    ui->total_payment->setText(total_payment);
  }
}

void MainWindow::on_calculate_depozit_clicked() {
  double depozit = std::atof(ui->depozit->text().toLocal8Bit().data());
  double interest_rate =
      std::atof(ui->interest_rate_dep->text().toLocal8Bit().data());
  double tax = std::atof(ui->tax->text().toLocal8Bit().data());
  int period = std::atof(ui->period_dep->text().toLocal8Bit().data());
  double minimum_balance =
      std::atof(ui->minimum_balance->text().toLocal8Bit().data());
  double replenishment =
      std::atof(ui->replenishment->text().toLocal8Bit().data());
  double withdrawal = std::atof(ui->withdrawal->text().toLocal8Bit().data());

  int type_period = 0;
  if (ui->type_period->currentIndex() == 0) type_period = 1;
  if (ui->type_period->currentIndex() == 1) type_period = 2;
  if (ui->type_period->currentIndex() == 2) type_period = 3;
  if (ui->type_period->currentIndex() == 3) type_period = 4;
  if (ui->type_period->currentIndex() == 4) type_period = 5;
  if (ui->type_period->currentIndex() == 5) type_period = 6;
  if (ui->type_period->currentIndex() == 6) type_period = 7;

  double count_replenishment = 0;
  if (ui->checkBox_replenishment->isChecked()) {
    if (ui->count_replenishment->currentIndex() == 0) count_replenishment = 1;
    if (ui->count_replenishment->currentIndex() == 1) count_replenishment = 2;
    if (ui->count_replenishment->currentIndex() == 2) count_replenishment = 3;
    if (ui->count_replenishment->currentIndex() == 3) count_replenishment = 4;
    if (ui->count_replenishment->currentIndex() == 4) count_replenishment = 5;
    if (ui->count_replenishment->currentIndex() == 5) count_replenishment = 6;
  }

  double count_withdrawal = 0;
  if (ui->checkBox_withdrawal->isChecked()) {
    if (ui->count_withdrawal->currentIndex() == 0) count_withdrawal = 1;
    if (ui->count_withdrawal->currentIndex() == 1) count_withdrawal = 2;
    if (ui->count_withdrawal->currentIndex() == 2) count_withdrawal = 3;
    if (ui->count_withdrawal->currentIndex() == 3) count_withdrawal = 4;
    if (ui->count_withdrawal->currentIndex() == 4) count_withdrawal = 5;
    if (ui->count_withdrawal->currentIndex() == 5) count_withdrawal = 6;
  }

  int type_dep_calc = ui->type_dep_calc->isChecked();

  double result[3] = {0};

  if (depozit <= 0 || interest_rate <= 0 || tax < 0 || period <= 0 ||
      minimum_balance < 0 || withdrawal < 0 || replenishment < 0) {
    ui->interest_charges->setText("invalid values");
    ui->tax_amount->setText("invalid values");
    ui->depozit_amount->setText("invalid values");
  } else {
    deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
                 withdrawal, &count_replenishment, &count_withdrawal,
                 &minimum_balance, type_period, type_dep_calc);
    QString interest_charges = QString::number(result[0], 'f', 7);
    QString tax_amount = QString::number(result[1], 'f', 7);
    QString depozit_amount = QString::number(result[2], 'f', 7);
    ui->interest_charges->setText(interest_charges);
    ui->tax_amount->setText(tax_amount);
    ui->depozit_amount->setText(depozit_amount);
  }
}

void MainWindow::on_clear_graphic_clicked() {
  X.clear();
  Y.clear();
  ui->graphic->graph(0)->data()->clear();
  ui->function->setText("");
  ui->value_x1->setText("");
  ui->value_x2->setText("");
  ui->min_x->setText("");
  ui->min_y->setText("");
  ui->max_x->setText("");
  ui->max_y->setText("");
  ui->step->setText("");
}

void MainWindow::on_clear_credit_clicked() {
  ui->credit->setText("");
  ui->interest_rate->setText("");
  ui->period->setText("");
  ui->monthly_payment->setText("");
  ui->overpayment->setText("");
  ui->total_payment->setText("");
}

void MainWindow::on_clear_depozit_clicked() {
  ui->depozit->setText("");
  ui->interest_rate_dep->setText("");
  ui->period_dep->setText("");
  ui->tax->setText("");
  ui->replenishment->setText("");
  ui->withdrawal->setText("");
  ui->minimum_balance->setText("");
  ui->interest_charges->setText("");
  ui->tax_amount->setText("");
  ui->depozit_amount->setText("");
}

void MainWindow::on_page_1lb_clicked(bool checked) {
  if (checked) {
    ui->stackedWidget->setCurrentIndex(0);
  }
}

void MainWindow::on_page_2lb_clicked(bool checked) {
  if (checked) {
    ui->stackedWidget->setCurrentIndex(1);
  }
}

void MainWindow::on_page_3lb_clicked(bool checked) {
  if (checked) {
    ui->stackedWidget->setCurrentIndex(2);
  }
}

void MainWindow::on_page_4lb_clicked(bool checked) {
  if (checked) {
    ui->stackedWidget->setCurrentIndex(3);
  }
}

void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize) {}
