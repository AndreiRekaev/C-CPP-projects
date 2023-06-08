#include "s21_smartcalc.h"

void annu_credit_calc(double *result, double credit, double interest_rate,
                      double period) {
  double interest_period = 0.0, monthly_interest_rate = 0.0,
         monthly_payment = 0.0, total_payment = 0.0, overpayment = 0.0;
  interest_period = period * (-1);
  monthly_interest_rate = interest_rate / (100 * 12);
  monthly_payment =
      credit * (monthly_interest_rate /
                (1 - pow((1 + monthly_interest_rate), interest_period)));
  total_payment = monthly_payment * period;
  overpayment = total_payment - credit;
  result[0] = monthly_payment;
  result[1] = total_payment;
  result[2] = overpayment;
}

void diff_credit_calc(double *result, double credit, double interest_rate,
                      double period) {
  double monthly_interest_rate = 0.0, monthly_payment_h = 0.0,
         monthly_overpayment = 0.0, monthly_payment = 0.0,
         monthly_payment1 = 0.0, total_payment = 0.0, overpayment = 0.0;
  monthly_payment_h = credit / period;
  monthly_interest_rate = interest_rate / (100 * 12);
  double balance = credit;
  double count_period = period;
  while (count_period) {
    monthly_overpayment = balance * monthly_interest_rate;
    if (count_period == period) {
      monthly_payment = monthly_payment_h + monthly_overpayment;
    } else if (count_period == 1) {
      monthly_payment1 = monthly_payment_h + monthly_overpayment;
    }
    overpayment += monthly_overpayment;
    balance -= monthly_payment_h;
    count_period--;
  }
  total_payment = credit + overpayment;
  result[0] = monthly_payment;
  result[1] = total_payment;
  result[2] = overpayment;
  result[3] = monthly_payment1;
}
