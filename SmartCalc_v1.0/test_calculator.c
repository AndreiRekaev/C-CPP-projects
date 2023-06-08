#include <check.h>

#include "SmartCalc/s21_smartcalc.h"

//----------------------------------------------------------------------------------------------//

START_TEST(addition_1) {
  char start_string[256] = {"5^4+3*2*1.1/(3*2)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 115.68, 7);
}
END_TEST

START_TEST(addition_2) {
  char start_string[256] = {"21*cos(123)-100"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -118.64, 7);
}
END_TEST

START_TEST(addition_3) {
  char start_string[256] = {"0+0"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(addition_4) {
  char start_string[256] = {"-1*(-5)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 5.0, 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(subtraction_1) {
  char start_string[256] = {"10-5"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 5.0, 7);
}
END_TEST

START_TEST(subtraction_2) {
  char start_string[256] = {"0-1000"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -1000.0, 7);
}
END_TEST

START_TEST(subtraction_3) {
  char start_string[256] = {"32-32"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(subtraction_4) {
  char start_string[256] = {"999-99-500-25-75-200-93-7-499"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -499.0, 7);
}
END_TEST

START_TEST(subtraction_5) {
  char start_string[256] = {"999-99-500+25-75-200+93-7-499"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -263.0, 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(multiplication_1) {
  char start_string[256] = {"10*5"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 50.0, 7);
}
END_TEST

START_TEST(multiplication_2) {
  char start_string[256] = {"-0*1000"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(multiplication_3) {
  char start_string[256] = {"32*2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 64.0, 7);
}
END_TEST

START_TEST(multiplication_4) {
  char start_string[256] = {"2*2*2*8"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 64.0, 7);
}
END_TEST

START_TEST(multiplication_5) {
  char start_string[256] = {"-7*6"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -42.0, 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(division_1) {
  char start_string[256] = {"10/2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 5.0, 7);
}
END_TEST

START_TEST(division_2) {
  char start_string[256] = {"0/4567"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(division_3) {
  char start_string[256] = {"31/2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 15.5, 7);
}
END_TEST

START_TEST(division_4) {
  char start_string[256] = {"100/2/2/5/5"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 1.0, 7);
}
END_TEST

START_TEST(division_5) {
  char start_string[256] = {"-999/9"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -111.0, 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(power_1) {
  char start_string[256] = {"10^2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 100.0, 7);
}
END_TEST

START_TEST(power_2) {
  char start_string[256] = {"1^43"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 1.0, 7);
}
END_TEST

START_TEST(power_3) {
  char start_string[256] = {"3^2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 9.0, 7);
}
END_TEST

START_TEST(power_4) {
  char start_string[256] = {"0^0"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(power_5) {
  char start_string[256] = {"-1^3"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -1.0, 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(cosine_1) {
  char start_string[256] = {"cos(0)-100"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(0) - 100, 7);
}
END_TEST

START_TEST(cosine_2) {
  char start_string[256] = {"cos(1)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(1), 7);
}
END_TEST

START_TEST(cosine_3) {
  char start_string[256] = {"cos(-5)"};  // добавить проверку унарного минуса
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(-5), 7);
}
END_TEST

START_TEST(cosine_4) {
  char start_string[256] = {"cos(5)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(5), 7);
}
END_TEST

START_TEST(cosine_5) {
  char start_string[256] = {"cos(0.30)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(0.30), 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(sine_1) {
  char start_string[256] = {"sin(45)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, sin(45), 7);
}
END_TEST

START_TEST(tan_1) {
  char start_string[256] = {"tan(3-2)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, tan(3 - 2), 7);
}
END_TEST

START_TEST(acosine_1) {
  char start_string[256] = {"acos(-0.5)"};  // добавить проверку унарного минуса
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, acos(-0.5), 7);
}
END_TEST

START_TEST(asine_1) {
  char start_string[256] = {"asin(-1)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, asin(-1), 7);
}
END_TEST

START_TEST(atan_1) {
  char start_string[256] = {"atan(0)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, atan(0), 7);
}
END_TEST

START_TEST(square_root_1) {
  char start_string[256] = {"sqrt(256)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, sqrt(256), 7);
}
END_TEST

START_TEST(nat_log_1) {
  char start_string[256] = {"ln(1)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, log(10), 7);
}
END_TEST

START_TEST(dec_log_1) {
  char start_string[256] = {"lg(1000)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, log10(1000), 7);
}
END_TEST

START_TEST(unar_minus_1) {
  char start_string[256] = {"0--2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 2, 7);
}
END_TEST

START_TEST(add_x_1) {
  char start_string[256] = {"9*x"};
  long double x_value = 3.0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 27, 7);
}
END_TEST

START_TEST(many_spaces_1) {
  char start_string[256] = {"cos(   1)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, cos(1), 7);
}
END_TEST

START_TEST(sine_with_power_1) {
  char start_string[256] = {"sin(2^(2-4))"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, sin(0.25), 7);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(mix_1) {
  char start_string[256] = {"(1+2)*3+5*4"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 29.0, 7);
}
END_TEST

START_TEST(mix_2) {
  char start_string[256] = {"(((1+2)))*3"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 9.0, 7);
}
END_TEST

START_TEST(mix_3) {
  char start_string[256] = {"(((1+2)))*3"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 9.0, 7);
}
END_TEST

START_TEST(mix_4) {
  char start_string[256] = {"(((1*2)))-3"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -1.0, 7);
}
END_TEST

START_TEST(mix_5) {
  char start_string[256] = {"1+2+3*(0-1)+(-1)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -1.0, 7);
}
END_TEST

// START_TEST(mix_7) {
//   char start_string[256] = {"2+3^(2*1+1)"};
//   long double x_value = 0;
//   long double result = 0.0;
//   QT_processing(start_string, x_value, &result);
//   ck_assert_double_eq_tol(result, 27.0, 7);
// }
// END_TEST

START_TEST(mix_8) {
  char start_string[256] = {"3+5*2/(6-4)^2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 5.5, 7);
}
END_TEST

// START_TEST(mix_9) {
//   char start_string[256] = {"(3+4*2)/((2+0)^(3^1)*100)"};
//   long double x_value = 0;
//   long double result = 0.0;
//   QT_processing(start_string, x_value, &result);
//   ck_assert_double_eq_tol(result, 103.0, 7);
// }
// END_TEST

START_TEST(mix_10) {
  char start_string[256] = {"11+(7^2)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 60.0, 7);
}
END_TEST

START_TEST(mix_11) {
  char start_string[256] = {"11+7^2"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 60.0, 7);
}
END_TEST

// -----------------------------------------------

START_TEST(mix_14) {
  char start_string[256] = {"32mod(32-30)"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 0.0, 7);
}
END_TEST

START_TEST(mix_16) {
  char start_string[256] = {"2^3^2-100"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, -36.0, 7);
}
END_TEST

START_TEST(mix_17) {
  char start_string[256] = {"2^(3)+10"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 18.0, 7);
}
END_TEST

START_TEST(mix_19) {
  char start_string[256] = {"512/(3^2)+3"};
  long double x_value = 0;
  long double result = 0.0;
  QT_processing(start_string, x_value, &result);
  ck_assert_double_eq_tol(result, 59.88, 7);
}
END_TEST
//-----------------------annu_credit_calc------------------------------------------//

START_TEST(annu_credit_1) {
  double result[3] = {0.0};
  double credit = 10000.0, period = 12.0, interest_rate = 7.0;
  annu_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 865.27, 2);
  ck_assert_double_eq_tol(result[2], 383.24, 2);
  ck_assert_double_eq_tol(result[1], 10383.24, 2);
}
END_TEST

START_TEST(annu_credit_2) {
  double result[3] = {0.0};
  double credit = 150000.0, period = 15., interest_rate = 9.0;
  annu_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 10610.46, 2);
  ck_assert_double_eq_tol(result[2], 9156.90, 2);
  ck_assert_double_eq_tol(result[1], 159156.9, 2);
}
END_TEST

START_TEST(annu_credit_3) {
  double result[3] = {0.0};
  double credit = 1500000.0, period = 18, interest_rate = 6.0;
  annu_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 87347.6, 2);
  ck_assert_double_eq_tol(result[2], 72256.8, 2);
  ck_assert_double_eq_tol(result[1], 1572256.8, 2);
}
END_TEST

//----------------------diff_credit_calc-------------------------------------//

START_TEST(diff_credit_1) {
  double result[4] = {0.0};
  double credit = 10000.0, period = 12.0, interest_rate = 7.0;
  diff_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 891.67, 2);
  ck_assert_double_eq_tol(result[3], 838.19, 2);
  ck_assert_double_eq_tol(result[2], 379.17, 2);
  ck_assert_double_eq_tol(result[1], 10379.17, 2);
}
END_TEST

START_TEST(diff_credit_2) {
  double result[4] = {0.0};
  double credit = 150000.0, period = 15.0, interest_rate = 9.0;
  diff_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 11125, 2);
  ck_assert_double_eq_tol(result[3], 10075, 2);
  ck_assert_double_eq_tol(result[2], 9000.0, 2);
  ck_assert_double_eq_tol(result[1], 159000.0, 2);
}
END_TEST

START_TEST(diff_credit_3) {
  double result[4] = {0.0};
  double credit = 1500000.0, period = 18, interest_rate = 6.0;
  diff_credit_calc(result, credit, interest_rate, period);
  ck_assert_double_eq_tol(result[0], 90833.33, 2);
  ck_assert_double_eq_tol(result[3], 83750, 2);
  ck_assert_double_eq_tol(result[2], 71250.0, 2);
  ck_assert_double_eq_tol(result[1], 1571250.0, 2);
}
END_TEST

//-------------------------deposit_calc----------------------------------//

START_TEST(deposit_calc_1_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 8.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 500.0, count_replenishment = 5.0,
         count_withdrawal = 2.0, minimum_balance = 0.0;
  int period = 24, type_dep_calc = 0, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 33746.66, 2);  // 33748.80 calcus.ru
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 288000.00, 2);
}
END_TEST

START_TEST(deposit_calc_1_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 8.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 500.0, count_replenishment = 5.0,
         count_withdrawal = 2.0, minimum_balance = 0.0;
  int period = 24, type_dep_calc = 1, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 36039.62, 2);
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 324039.62, 2);
}
END_TEST

START_TEST(deposit_calc_2_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 4.25,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 15, type_dep_calc = 0, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 8750.0, 2);  // 8740.38 calcus.ru
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 100000.0, 2);
}
END_TEST

START_TEST(deposit_calc_2_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 4.25,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 15, type_dep_calc = 1, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 9116.48, 2);  // 9106.4 calcus.ru
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 109116.48, 2);  // 109106.04 calcus.ru
}
END_TEST

START_TEST(deposit_calc_3_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 4.25,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 40, type_dep_calc = 0, type_period = 4.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 23333.33, 2);  // 23301.38 calcus.ru
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 100000, 2);
}
END_TEST

START_TEST(deposit_calc_3_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 4.25,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 40, type_dep_calc = 1, type_period = 4.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 26029.86, 2);  // 25990.14 calcus.ru
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 126029.86, 2);  // 125990.14 calcus.ru
}
END_TEST

START_TEST(deposit_calc_4_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 1.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 6998.35, 2);  //
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 100000, 2);  //
}
END_TEST

START_TEST(deposit_calc_4_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 1.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 7250.1, 2);  // 7247.44
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 107250.1, 2);  //
}
END_TEST

START_TEST(deposit_calc_5_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 0, type_period = 1.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11660.3, 2);  //
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 100000, 2);  //
}
END_TEST

START_TEST(deposit_calc_5_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 1, type_period = 1.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 12366, 2);  //
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 112366, 2);  //
}
END_TEST

START_TEST(deposit_calc_6_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 0, type_period = 2.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11666.7, 2);  // 11645.24
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 100000, 2);  //
}
END_TEST

START_TEST(deposit_calc_6_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 1, type_period = 2.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 12364.9, 2);  // 12341.52
  ck_assert_double_eq_tol(result[1], 0.0, 2);
  ck_assert_double_eq_tol(result[2], 112364.9, 2);  //
}
END_TEST

START_TEST(deposit_calc_7_without_cap) {
  double result[3] = {0};
  double depozit = 1000000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 5.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 70000.0, 2);    //
  ck_assert_double_eq_tol(result[1], 0.0, 2);        //
  ck_assert_double_eq_tol(result[2], 1000000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_7_with_cap) {
  double result[3] = {0};
  double depozit = 1000000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 5.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 71224.99, 2);    //
  ck_assert_double_eq_tol(result[1], 0.0, 2);         //
  ck_assert_double_eq_tol(result[2], 1071224.99, 2);  //
}
END_TEST

START_TEST(deposit_calc_8_without_cap) {
  double result[3] = {0};
  double depozit = 1000000.0, interest_rate = 20.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 6.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 200000.0, 2);   //
  ck_assert_double_eq_tol(result[1], 16250.0, 2);    //
  ck_assert_double_eq_tol(result[2], 1000000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_8_with_cap) {
  double result[3] = {0};
  double depozit = 1000000.0, interest_rate = 20.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 6.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 200000.0, 2);   //
  ck_assert_double_eq_tol(result[1], 16250.0, 2);    //
  ck_assert_double_eq_tol(result[2], 1200000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_9_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 0, type_period = 5.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11667, 2);     // 11668.24
  ck_assert_double_eq_tol(result[1], 0.0, 2);       //
  ck_assert_double_eq_tol(result[2], 100000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_9_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 1, type_period = 5.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 12169, 2);   // 12166.99
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 112169, 2);  // 112166.99
}
END_TEST

START_TEST(deposit_calc_10_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 0, type_period = 6.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11667, 2);     // 11668.24
  ck_assert_double_eq_tol(result[1], 0.0, 2);       //
  ck_assert_double_eq_tol(result[2], 100000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_10_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 1, type_period = 6.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 12096, 2);   // 11995.02
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 112096, 2);  // 111995.02
}
END_TEST

START_TEST(deposit_calc_11_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 0, type_period = 7.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11667, 2);     // 11668.24
  ck_assert_double_eq_tol(result[1], 0.0, 2);       //
  ck_assert_double_eq_tol(result[2], 100000.0, 2);  //
}
END_TEST

START_TEST(deposit_calc_11_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 0.0, withdrawal = 0.0, count_replenishment = 0.0,
         count_withdrawal = 0.0, minimum_balance = 0.0;
  int period = 20, type_dep_calc = 1, type_period = 7.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 11667, 2);   // 11668.24
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 111667, 2);  // 111995.02
}
END_TEST

START_TEST(deposit_calc_12_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 1.0, count_withdrawal = 1.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 9887, 2);    // 9882.45
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 145000, 2);  // 145000
}
END_TEST

START_TEST(deposit_calc_12_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 2.0, count_withdrawal = 5.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 26380, 2);   // 26404.65
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 716380, 2);  // 716404.65
}
END_TEST

START_TEST(deposit_calc_13_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 3.0, count_withdrawal = 3.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 16450, 2);   // 16467.25
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 370000, 2);  // 370000
}
END_TEST

START_TEST(deposit_calc_13_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 4.0, count_withdrawal = 4.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 14200, 2);   // 14210.20
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 294200, 2);  // 294210.20
}
END_TEST

START_TEST(deposit_calc_14_without_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 6.0, count_withdrawal = 3.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 0, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 9158, 2);    // 9150.82
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 120000, 2);  // 120000.0
}
END_TEST

START_TEST(deposit_calc_14_with_cap) {
  double result[3] = {0};
  double depozit = 100000.0, interest_rate = 7.0, tax = 0.0,
         replenishment = 50000.0, withdrawal = 5000.0,
         count_replenishment = 4.0, count_withdrawal = 6.0,
         minimum_balance = 0.0;
  int period = 12, type_dep_calc = 1, type_period = 3.0;
  deposit_calc(result, &depozit, period, interest_rate, tax, replenishment,
               withdrawal, &count_replenishment, &count_withdrawal,
               &minimum_balance, type_period, type_dep_calc);
  ck_assert_double_eq_tol(result[0], 14644, 2);   // 14656.12
  ck_assert_double_eq_tol(result[1], 0.0, 2);     //
  ck_assert_double_eq_tol(result[2], 309644, 2);  // 309656.12
}
END_TEST

//-------------------------style_addition----------------------------------//

START_TEST(style_addition_1) {
  char start_string[256] = {")1+2"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_addition_2) {
  char start_string[256] = {"0+10.5("};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_addition_3) {
  char start_string[256] = {")))0+0((("};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_addition_4) {
  char start_string[256] = {"0+0"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_addition_5) {
  char start_string[256] = {"-100+c21)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(style_subtraction_1) {
  char start_string[256] = {"10-5*c/3)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_subtraction_2) {
  char start_string[256] = {"-0-100*(0)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_subtraction_3) {
  char start_string[256] = {"32+(-32)"};  // !!!
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_subtraction_4) {
  char start_string[256] = {"999-99-500-25-*75-200-93-7-499"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(style_multiplication_1) {
  char start_string[256] = {"10**5"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_multiplication_2) {
  char start_string[256] = {"-0***1000"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_multiplication_3) {
  char start_string[256] = {"32*2"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_multiplication_4) {
  char start_string[256] = {"2*2*2*8"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_multiplication_5) {
  char start_string[256] = {"(-7)*6"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(style_division_1) {
  char start_string[256] = {"10/(+2)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_division_2) {
  char start_string[256] = {"0/456..7"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_division_3) {
  char start_string[256] = {".31/2"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_division_4) {
  char start_string[256] = {"100./2./2./5/5."};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_division_5) {
  char start_string[256] = {"-999/9"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(style_power_1) {
  char start_string[256] = {"10^2)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_power_2) {
  char start_string[256] = {"1^.43"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_power_3) {
  char start_string[256] = {"3.^2"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_power_4) {
  char start_string[256] = {"0^0)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_power_5) {
  char start_string[256] = {"-1^*3"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

//----------------------------------------------------------------------------------------------//

START_TEST(style_cosine_1) {
  char start_string[256] = {"cos0-)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_cosine_2) {
  char start_string[256] = {"cos1+1.34)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_cosine_3) {
  char start_string[256] = {"tan(-5)"};  // добавить проверку унарного минуса
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_cosine_4) {
  char start_string[256] = {"L5)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_cosine_5) {
  char start_string[256] = {"c0.3.0)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 1);
}
END_TEST

START_TEST(style_mix_1) {
  char start_string[256] = {"((1+2)*((3+5)*4))"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_mix_2) {
  char start_string[256] = {"(((1+2)))*3"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_mix_3) {
  char start_string[256] = {"(((1+2)))*3"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

START_TEST(style_mix_4) {
  char start_string[256] = {"(((1*(2)))-3)"};
  long double x_value = 0;
  long double result = 0.0;
  int string_status = QT_processing(start_string, x_value, &result);
  ck_assert_int_eq(string_status, 0);
}
END_TEST

int main(void) {
  Suite *s1 = suite_create("Core");
  TCase *tc1_1 = tcase_create("Core");
  SRunner *sr = srunner_create(s1);
  int tc = 0;
  suite_add_tcase(s1, tc1_1);

  tcase_add_test(tc1_1, addition_1);
  tcase_add_test(tc1_1, addition_2);
  tcase_add_test(tc1_1, addition_3);
  tcase_add_test(tc1_1, addition_4);

  tcase_add_test(tc1_1, subtraction_1);
  tcase_add_test(tc1_1, subtraction_2);
  tcase_add_test(tc1_1, subtraction_3);
  tcase_add_test(tc1_1, subtraction_4);
  tcase_add_test(tc1_1, subtraction_5);

  tcase_add_test(tc1_1, multiplication_1);
  tcase_add_test(tc1_1, multiplication_2);
  tcase_add_test(tc1_1, multiplication_3);
  tcase_add_test(tc1_1, multiplication_4);
  tcase_add_test(tc1_1, multiplication_5);

  tcase_add_test(tc1_1, division_1);
  tcase_add_test(tc1_1, division_2);
  tcase_add_test(tc1_1, division_3);
  tcase_add_test(tc1_1, division_4);
  tcase_add_test(tc1_1, division_5);

  tcase_add_test(tc1_1, power_1);
  tcase_add_test(tc1_1, power_2);
  tcase_add_test(tc1_1, power_3);
  tcase_add_test(tc1_1, power_4);
  tcase_add_test(tc1_1, power_5);

  tcase_add_test(tc1_1, cosine_1);
  tcase_add_test(tc1_1, cosine_2);
  tcase_add_test(tc1_1, cosine_3);
  tcase_add_test(tc1_1, cosine_4);
  tcase_add_test(tc1_1, cosine_5);

  tcase_add_test(tc1_1, sine_1);
  tcase_add_test(tc1_1, tan_1);
  tcase_add_test(tc1_1, acosine_1);
  tcase_add_test(tc1_1, asine_1);
  tcase_add_test(tc1_1, atan_1);
  tcase_add_test(tc1_1, square_root_1);
  tcase_add_test(tc1_1, nat_log_1);
  tcase_add_test(tc1_1, dec_log_1);
  tcase_add_test(tc1_1, unar_minus_1);
  tcase_add_test(tc1_1, add_x_1);
  tcase_add_test(tc1_1, many_spaces_1);
  tcase_add_test(tc1_1, sine_with_power_1);

  tcase_add_test(tc1_1, mix_1);
  tcase_add_test(tc1_1, mix_2);
  tcase_add_test(tc1_1, mix_3);
  tcase_add_test(tc1_1, mix_4);
  tcase_add_test(tc1_1, mix_5);
  tcase_add_test(tc1_1, mix_8);
  tcase_add_test(tc1_1, mix_10);
  tcase_add_test(tc1_1, mix_11);
  tcase_add_test(tc1_1, mix_14);
  tcase_add_test(tc1_1, mix_16);
  tcase_add_test(tc1_1, mix_17);
  tcase_add_test(tc1_1, mix_19);

  tcase_add_test(tc1_1, annu_credit_1);
  tcase_add_test(tc1_1, annu_credit_2);
  tcase_add_test(tc1_1, annu_credit_3);

  tcase_add_test(tc1_1, diff_credit_1);
  tcase_add_test(tc1_1, diff_credit_2);
  tcase_add_test(tc1_1, diff_credit_3);

  tcase_add_test(tc1_1, deposit_calc_1_without_cap);
  tcase_add_test(tc1_1, deposit_calc_1_with_cap);
  tcase_add_test(tc1_1, deposit_calc_2_without_cap);
  tcase_add_test(tc1_1, deposit_calc_2_with_cap);
  tcase_add_test(tc1_1, deposit_calc_3_without_cap);
  tcase_add_test(tc1_1, deposit_calc_3_with_cap);
  tcase_add_test(tc1_1, deposit_calc_4_without_cap);
  tcase_add_test(tc1_1, deposit_calc_4_with_cap);
  tcase_add_test(tc1_1, deposit_calc_5_without_cap);
  tcase_add_test(tc1_1, deposit_calc_5_with_cap);
  tcase_add_test(tc1_1, deposit_calc_6_without_cap);
  tcase_add_test(tc1_1, deposit_calc_6_with_cap);
  tcase_add_test(tc1_1, deposit_calc_7_without_cap);
  tcase_add_test(tc1_1, deposit_calc_7_with_cap);
  tcase_add_test(tc1_1, deposit_calc_8_without_cap);
  tcase_add_test(tc1_1, deposit_calc_8_with_cap);
  tcase_add_test(tc1_1, deposit_calc_9_without_cap);
  tcase_add_test(tc1_1, deposit_calc_9_with_cap);
  tcase_add_test(tc1_1, deposit_calc_10_without_cap);
  tcase_add_test(tc1_1, deposit_calc_10_with_cap);
  tcase_add_test(tc1_1, deposit_calc_11_without_cap);
  tcase_add_test(tc1_1, deposit_calc_11_with_cap);
  tcase_add_test(tc1_1, deposit_calc_12_without_cap);
  tcase_add_test(tc1_1, deposit_calc_12_with_cap);
  tcase_add_test(tc1_1, deposit_calc_13_without_cap);
  tcase_add_test(tc1_1, deposit_calc_13_with_cap);
  tcase_add_test(tc1_1, deposit_calc_14_without_cap);
  tcase_add_test(tc1_1, deposit_calc_14_with_cap);

  tcase_add_test(tc1_1, style_addition_1);
  tcase_add_test(tc1_1, style_addition_2);
  tcase_add_test(tc1_1, style_addition_3);
  tcase_add_test(tc1_1, style_addition_4);
  tcase_add_test(tc1_1, style_addition_5);

  tcase_add_test(tc1_1, style_subtraction_1);
  tcase_add_test(tc1_1, style_subtraction_2);
  tcase_add_test(tc1_1, style_subtraction_3);
  tcase_add_test(tc1_1, style_subtraction_4);

  tcase_add_test(tc1_1, style_multiplication_1);
  tcase_add_test(tc1_1, style_multiplication_2);
  tcase_add_test(tc1_1, style_multiplication_3);
  tcase_add_test(tc1_1, style_multiplication_4);
  tcase_add_test(tc1_1, style_multiplication_5);

  tcase_add_test(tc1_1, style_division_1);
  tcase_add_test(tc1_1, style_division_2);
  tcase_add_test(tc1_1, style_division_3);
  tcase_add_test(tc1_1, style_division_4);
  tcase_add_test(tc1_1, style_division_5);

  tcase_add_test(tc1_1, style_power_1);
  tcase_add_test(tc1_1, style_power_2);
  tcase_add_test(tc1_1, style_power_3);
  tcase_add_test(tc1_1, style_power_4);
  tcase_add_test(tc1_1, style_power_5);

  tcase_add_test(tc1_1, style_cosine_1);
  tcase_add_test(tc1_1, style_cosine_2);
  tcase_add_test(tc1_1, style_cosine_3);
  tcase_add_test(tc1_1, style_cosine_4);
  tcase_add_test(tc1_1, style_cosine_5);

  tcase_add_test(tc1_1, style_mix_1);
  tcase_add_test(tc1_1, style_mix_2);
  tcase_add_test(tc1_1, style_mix_3);
  tcase_add_test(tc1_1, style_mix_4);

  srunner_run_all(sr, CK_ENV);
  tc = srunner_ntests_failed(sr);
  srunner_free(sr);

  return tc == 0 ? 0 : 1;
}
