#include "s21_smartcalc.h"

const int days[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void deposit_calc(double *result, double *depozit, int period,
                  double interest_rate, double tax, double replenishment,
                  double withdrawal, double *count_replenishment,
                  double *count_withdrawal, double *minimum_balance,
                  int type_period, int type_dep_calc) {
  double interest_charges = 0.0, tax_amount = 0.0, depozit_amount = 0.0,
         upper_value = 0.0, lower_value = 0.0, upper_value_rem = 0.0,
         lower_value_rem = 0.0;
  int period_n = 0, period_rem = 0, tax_period = 0, tax_period_rem = 0;
  if (type_period == 1) {  // Каждый день
    for (int numbers = 0, count_years = 0; period > 0;
         period--, numbers++, count_years++) {
      if (count_years == 12) {
        count_years = 0;
        numbers = 0;
      }
      period_n += days[numbers];
    }
    tax_period = period_n / 365;
    upper_value = 1.0, lower_value = 365.0;  // по умолчанию в 1 месяце 30 дней
  } else if (type_period == 2) {  // Каждую неделю
    period_n = period * 4, upper_value = 1.0,
    lower_value = 48.0;  // общее количество месяцев, по умолчанию, в 1 месяце 4
                         // недели, в 1 году 48 недель
    tax_period = period_n / 48;
  } else if (type_period == 3) {  // Раз в месяц
    period_n = period, upper_value = 1.0, lower_value = 12.0;
    tax_period = period_n / 12;
  } else if (type_period == 4) {  // Раз в квартал
    period_n = period / 3, upper_value = 1.0, lower_value = 4.0;
    if (period % 3 != 0) {
      period_rem = period - (period_n * 3), upper_value_rem = 1.0,
      lower_value_rem = 12.0;
    }
    tax_period = period_n / 4;
  } else if (type_period == 5) {  // Раз в полгода
    period_n = period / 6, upper_value = 1.0, lower_value = 2.0;
    if (period % 6 != 0) {
      period_rem = period - (period_n * 6), upper_value_rem = 1.0,
      lower_value_rem = 12.0;
    }
    tax_period = period_n / 2;
  } else if (type_period == 6) {  // Раз в год
    period_n = period / 12, upper_value = 1.0, lower_value = 1.0;
    if (period % 12 != 0) {
      period_rem = period - (period_n * 12), upper_value_rem = 1.0,
      lower_value_rem = 12.0;
    }
    tax_period = period_n;
  } else if (type_period == 7) {  // В конце срока
    period_n = 1, upper_value = period, lower_value = 12.0;
    tax_period = period_n;
  }
  calculation_deposit(period_n, &interest_charges, &tax_amount, depozit,
                      interest_rate, tax, replenishment, withdrawal,
                      count_replenishment, count_withdrawal, minimum_balance,
                      type_dep_calc, upper_value, lower_value, tax_period);
  calculation_deposit(period_rem, &interest_charges, &tax_amount, depozit,
                      interest_rate, tax, replenishment, withdrawal,
                      count_replenishment, count_withdrawal, minimum_balance,
                      type_dep_calc, upper_value_rem, lower_value_rem,
                      tax_period_rem);
  if (type_dep_calc == 0) {
    depozit_amount = *depozit;
  } else if (type_dep_calc == 1) {
    depozit_amount = *depozit + interest_charges;
  }
  result[0] = interest_charges;
  result[1] = tax_amount;
  result[2] = depozit_amount;
}

void calculation_deposit(int period_type, double *interest_charges,
                         double *tax_amount, double *depozit,
                         double interest_rate, double tax, double replenishment,
                         double withdrawal, double *count_replenishment,
                         double *count_withdrawal, double *minimum_balance,
                         int type_dep_calc, double upper_value,
                         double lower_value, int tax_period) {
  double days_depozit = 0.0, sum_depozit = 0.0;
  int status_tax = 0;
  while (period_type) {
    if (*depozit > 0) {
      if (type_dep_calc == 0) {
        sum_depozit = *depozit;
      } else if (type_dep_calc == 1) {
        sum_depozit = *depozit + *interest_charges;
      }
      days_depozit =
          (sum_depozit * (interest_rate * 0.01 * upper_value / lower_value));
      *interest_charges += days_depozit;
      int int_period = period_type;
      replenishment_op(depozit, replenishment, count_replenishment, int_period);
      withdrawal_op(depozit, withdrawal, count_withdrawal, int_period,
                    minimum_balance);
    }
    period_type--;
  }
  if (tax_period >= 1 && status_tax == 0) {
    calc_tax_amount(interest_charges, tax, tax_amount, tax_period, &status_tax);
  }
}

void calc_tax_amount(double *interest_charges, double tax, double *tax_amount,
                     int tax_period, int *status_tax) {
  double tax_free_income = 0.0;
  if (!tax) {
    tax = 0.13;
  }
  tax_free_income =
      0.075 * 1000000;  // ключевая ставка ЦБ на 1ое января расчетного года 7.5%
  if (*interest_charges > tax_free_income) {
    for (double tax_year = 0.0; tax_period > 0; tax_period--) {
      tax_year = (*interest_charges - tax_free_income) * tax;
      *tax_amount += tax_year;
    }
  }
  *status_tax = 1;
}

void replenishment_op(double *depozit, double replenishment,
                      double *count_replenishment, int int_period) {
  if (*count_replenishment) {
    if (*count_replenishment == 1) {  // Разовое
      *depozit += replenishment;
      *count_replenishment = 0;
    }
    if (*count_replenishment == 2) {  // Раз в месяц
      *depozit += replenishment;
    }
    if (*count_replenishment == 3 && int_period % 2 == 0) {  // Раз в 2 месяца
      *depozit += replenishment;
    }
    if (*count_replenishment == 4 && int_period % 3 == 0) {  // Раз в квартал
      *depozit += replenishment;
    }
    if (*count_replenishment == 5 && int_period % 6 == 0) {  // Раз в полгода
      *depozit += replenishment;
    }
    if (*count_replenishment == 6 && int_period % 12 == 0) {  // Раз в год
      *depozit += replenishment;
    }
  }
}

void withdrawal_op(double *depozit, double withdrawal, double *count_withdrawal,
                   int int_period, double *minimum_balance) {
  if (*count_withdrawal && (*depozit - withdrawal) >= *minimum_balance) {
    if (*count_withdrawal == 1) {  // Разовое
      *depozit -= withdrawal;
      *count_withdrawal = 0;
    }
    if (*count_withdrawal == 2) {  // Раз в месяц
      *depozit -= withdrawal;
    }
    if (*count_withdrawal == 3 && int_period % 2 == 0) {  // Раз в 2 месяца
      *depozit -= withdrawal;
    }
    if (*count_withdrawal == 4 && int_period % 3 == 0) {  // Раз в квартал
      *depozit -= withdrawal;
    }
    if (*count_withdrawal == 5 && int_period % 6 == 0) {  // Раз в полгода
      *depozit -= withdrawal;
    }
    if (*count_withdrawal == 6 && int_period % 12 == 0) {  // Раз в год
      *depozit -= withdrawal;
    }
  }
}
