#include <gtest/gtest.h>

#include <cmath>
#include <iostream>
#include <string>

#include "../modelCalc.h"

TEST(CalcTest, Basic1) {
  s21::SmartCalc calc("1+1 - 12 * (5^3) ");
  EXPECT_EQ(calc.Calculate(0), -1498.0);
}

TEST(CalcTest, Basic2) {
  s21::SmartCalc calc1("1e-2");
  EXPECT_EQ(calc1.Calculate(), 0.01);
}

TEST(CalcTest, Basic3) {
  s21::SmartCalc calc1("1-(2-(3-(4/8)*(-1-7))-3) ");
  EXPECT_EQ(calc1.Calculate(),
            1.0 - (2.0 - (3.0 - (4.0 / 8.0) * (-1.0 - 7.0)) - 3.0));
}

TEST(CalcTest, Basic4) {
  s21::SmartCalc calc1("1+1 - 12 * (5^3) ");
  EXPECT_EQ(calc1.Calculate(0), -1498.0);
}

TEST(CalcTest, TrigFunctions) {
  s21::SmartCalc calc("sin(x)+cos(x)-tan(x)");
  double expected = sin(2) + cos(2) - tan(2);
  EXPECT_DOUBLE_EQ(calc.Calculate(2), expected);
}

TEST(CalcTest, Exponentiation) {
  s21::SmartCalc calc("x^2");
  EXPECT_DOUBLE_EQ(calc.Calculate(3), 9);
}

TEST(CalcTest, SquareRoot) {
  s21::SmartCalc calc("sqrt(x)");
  EXPECT_DOUBLE_EQ(calc.Calculate(4), 2);
}

TEST(CalcTest, Logarithm) {
  s21::SmartCalc calc("log(x)");
  EXPECT_DOUBLE_EQ(calc.Calculate(100), 2);
}

TEST(CalcTest, Mod) {
  s21::SmartCalc calc("10 mod 2");
  EXPECT_DOUBLE_EQ(calc.Calculate(), fmod(10, 2));
}

TEST(CalcTest, PowerFunctions) {
  s21::SmartCalc calc("x^2 + sqrt(x)");
  double expected = pow(3.5, 2) + sqrt(3.5);
  EXPECT_DOUBLE_EQ(calc.Calculate(3.5), expected);
}

TEST(CalcTest, LogarithmicFunctions) {
  s21::SmartCalc calc("ln(x) + log(x)");
  double expected = log(2.7) + log10(2.7);
  EXPECT_DOUBLE_EQ(calc.Calculate(2.7), expected);
}

TEST(CalcTest, DivisionByZero) {
  s21::SmartCalc calc("1 / (x - 2)");
  EXPECT_TRUE(std::isnan(calc.Calculate(2)));
}

TEST(CalcTest, NegativeRoot) {
  s21::SmartCalc calc("sqrt(-1)");
  EXPECT_TRUE(std::isnan(calc.Calculate()));
}

TEST(CalcTest, InvalidExpression) {
  EXPECT_THROW(s21::SmartCalc calc("1 + unknown(x)"), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression1) {
  EXPECT_THROW(s21::SmartCalc calc("1+1)"), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression2) {
  EXPECT_THROW(s21::SmartCalc calc(")1+1 - 12 * (5^3) "),
               std::invalid_argument);
}

TEST(CalcTest, InvalidExpression3) {
  EXPECT_THROW(s21::SmartCalc calc("(23_32-3)"), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression4) {
  EXPECT_THROW(s21::SmartCalc calc(")1+2("), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression5) {
  EXPECT_THROW(s21::SmartCalc calc("1.1.1+1"), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression6) {
  EXPECT_THROW(s21::SmartCalc calc("1+1-12*(5^3"), std::invalid_argument);
}

TEST(CalcTest, InvalidExpression7) {
  EXPECT_THROW(s21::SmartCalc calc("(12))+(12"), std::invalid_argument);
}

TEST(CalcTest, Additional) {
  EXPECT_ANY_THROW(s21::SmartCalc calc("(1+2"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("13 13"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("sin(x)) - f"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("(1+2))2"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("s i n (x))"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("12+3))"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("1+(2+(-3)"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("cossinp"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("1-(2-(3.3.3)-4)"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("sin(X^(cos(x))"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("1e3.4"));
  EXPECT_ANY_THROW(s21::SmartCalc calc("sinnnn"));
}

TEST(CalcTest, OneOperator) {
  double a = 13.14;
  double b = 45.01;
  double result = 0., expected_result = 0.;
  std::string lexeme;
  char buff[255];

  std::snprintf(buff, sizeof(buff), "%lf+%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = a + b;
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "%lf-%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result = a - b;
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "%lf*%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result = a * b;
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "%lf/%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate();
  expected_result = a / b;
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "%lfmod%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc5(lexeme);
  result = calc5.Calculate();
  expected_result = std::fmod(a, b);
  EXPECT_DOUBLE_EQ(result, expected_result);

  a = 2, b = 2;
  std::snprintf(buff, sizeof(buff), "%lf^%lf", a, b);
  lexeme = buff;
  s21::SmartCalc calc6(lexeme);
  result = calc6.Calculate();
  expected_result = std::pow(a, b);
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, OneFunction) {
  double a = 0.18;
  double result = 0., expected_result = 0.;
  std::string lexeme;
  char buff[255];

  std::snprintf(buff, sizeof(buff), "sin(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = sin(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "cos(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result = cos(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "tan(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result = tan(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "asin(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate();
  expected_result = asin(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "acos(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc5(lexeme);
  result = calc5.Calculate();
  expected_result = acos(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "atan(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc6(lexeme);
  result = calc6.Calculate();
  expected_result = atan(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "sqrt(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc7(lexeme);
  result = calc7.Calculate();
  expected_result = sqrt(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "ln(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc8(lexeme);
  result = calc8.Calculate();
  expected_result = log(a);
  EXPECT_DOUBLE_EQ(result, expected_result);

  std::snprintf(buff, sizeof(buff), "log(%lf)", a);
  lexeme = buff;
  s21::SmartCalc calc9(lexeme);
  result = calc9.Calculate();
  expected_result = log10(a);
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, SeveralOperators) {
  std::string lexeme = "1+2-3.2*7.008/2*2-2.5";
  double result = 0., expected_result = 0.;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = 1 + 2 - 3.2 * 7.008 / 2 * 2 - 2.5;
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "1.0001*29999.555-456/1.23456789+5*9/9*9+6-7";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result =
      1.0001 * 29999.555 - 456 / 1.23456789 + 5 * 9 / 9 * 9 + 6 - 7;
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "1.+1+1+1+1+1+1+1-1-1./11*1-1/1-11-1*1/1*1/1-1/1*1+1-1/1*1";
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result = 1. + 1 + 1 + 1 + 1 + 1 + 1 + 1 - 1 - 1. / 11 * 1 - 1 / 1 -
                    11 - 1 * 1 / 1 * 1 / 1 - 1 / 1 * 1 + 1 - 1 / 1 * 1;
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme =
      "0.0001*12345.6789*12345.921-568.3245687+78.1234567*0.0000001/0.020201";
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate();
  expected_result = 0.0001 * 12345.6789 * 12345.921 - 568.3245687 +
                    78.1234567 * 0.0000001 / 0.020201;
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, UnaryPlusMinus) {
  std::string lexeme = "(-3.2)*7.008";
  double result = 0., expected_result = 0.;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = -3.2 * 7.008;
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "(-1.0001)*(+29999.555)/(+1.23456789)";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result = (-1.0001) * (+29999.555) / (+1.23456789);
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "1.0001*29999.555-456/1.23456789";
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result = 1.0001 * 29999.555 - 456 / 1.23456789;
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "(-1.0001)*(-29999.555)-(-456)/(-1.234789)";
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate();
  expected_result = -1.0001 * (-29999.555) - (-456.) / (-1.234789);
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, Brackets) {
  std::string lexeme = "(((((((5+1)*2)*2)*2)*2)))";
  double result = 0., expected_result = 0.;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = (((((((5 + 1) * 2) * 2) * 2) * 2)));
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "(((((((5.+1.)*2.)*2.)*2.)*2.)))*((1.+2.)-1)-(((((1)))))";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result =
      (((((((5. + 1.) * 2.) * 2.) * 2.) * 2.))) * ((1. + 2.) - 1) - (((((1)))));
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "(-(-(-(-(-(-(5.+1.)*2.)*2.)*2.)*2.)))*((1.+2.)-1)-(((((1)))))";
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result =
      (-(-(-(-(-(-(5. + 1.) * 2.) * 2.) * 2.) * 2.))) * ((1. + 2.) - 1) -
      (((((1)))));
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, SeveralTrigonometricPow) {
  std::string lexeme = "sin(cos(tan(0.0001)))";
  double result = 0., expected_result = 0.;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result = sin(cos(tan(0.0001)));
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "sin(cos(tan(0.0001)))*tan(sin(-1.*0.2))+cos(atan(0.98/2-0.0001))";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result = sin(cos(tan(0.0001))) * tan(sin(-1. * 0.2)) +
                    cos(atan(0.98 / 2 - 0.0001));
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme =
      "sin(cos(tan(0.0001)))*tan(sin(-1.*0.2))+cos(atan(0.98/"
      "2-0.0001))+sin(0)+acos(1)+asin(0.000003)";
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate();
  expected_result = sin(cos(tan(0.0001))) * tan(sin(-1. * 0.2)) +
                    cos(atan(0.98 / 2 - 0.0001)) + sin(0) + acos(1) +
                    asin(0.000003);
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme =
      "2.^(sin(cos(tan(0.0001)))*tan(sin(-1.*0.2)))+0.2^(cos(atan(0.98/"
      "2-0.0001))+sin(0)+acos(1)+asin(0.000003))";
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate();
  expected_result = pow(2., (sin(cos(tan(0.0001))) * tan(sin(-1. * 0.2)))) +
                    pow(0.2, (cos(atan(0.98 / 2 - 0.0001)) + sin(0) + acos(1) +
                              asin(0.000003)));
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, SeveralAnotherFunctions) {
  std::string lexeme = "ln(1.2mod0.00345+sqrt(3.1415*(-log(0.12300001))))";
  double result = 0., expected_result = 0.;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate();
  expected_result =
      log(fmod(1.2, 0.00345) + sqrt(3.1415 * (-log10(0.12300001))));
  EXPECT_DOUBLE_EQ(result, expected_result);

  lexeme = "(-ln(1.2mod(sin(0.005)*0.00345)+sqrt(3.1415*(-log(0.12300001)))))";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate();
  expected_result = -log(fmod(1.2, sin(0.005) * 0.00345) +
                         sqrt(3.1415 * (-log10(0.12300001))));
  EXPECT_DOUBLE_EQ(result, expected_result);
}

TEST(CalcTest, HardWithArg) {
  std::string lexeme =
      "(-sin(-0.2365*x/"
      "atan(1.002)+acos(0.141528)^(3.1415))+(-log(10*cos(-sqrt(2.3-3.7/"
      "89)+1415.)))/ln(3.321+atan(-3mod4)))";
  double result = 0., expected_result = 0.;
  double x = 0.1346;

  s21::SmartCalc calc(lexeme);
  result = calc.Calculate(x);
  expected_result =
      -sin(-0.2365 * x / atan(1.002) + pow(acos(0.141528), 3.1415)) +
      (-log10(10 * cos(-sqrt(2.3 - 3.7 / 89) + 1415.))) /
          log(3.321 + atan(fmod(-3., 4.)));
  EXPECT_NEAR(result, expected_result, 1e-10);

  x = -0.000001;
  lexeme =
      "(-sin(-0.2365*x/atan(1.002)+acos(0.141528)^(3.1415))+x-x*x/"
      "(-log(10*cos(-sqrt(2.3-3.7/89)+1415.)))/ln(3.321+atan(-3mod4)))";
  s21::SmartCalc calc2(lexeme);
  result = calc2.Calculate(x);
  expected_result =
      -sin(-0.2365 * x / atan(1.002) + pow(acos(0.141528), 3.1415)) + x -
      x * x / (-log10(10 * cos(-sqrt(2.3 - 3.7 / 89) + 1415.))) /
          log(3.321 + atan(fmod(-3., 4.)));
  EXPECT_NEAR(result, expected_result, 1e-10);

  x = 0.0000005;
  lexeme =
      "(-sin(-0.2365*x/atan(1.002)+acos(0.141528)^(3.1415))+x-x*x/"
      "(-log(10*cos(-sqrt(2.3-3.7/89)+1415.)))/ln(3.321+atan(-3mod4)))";
  s21::SmartCalc calc3(lexeme);
  result = calc3.Calculate(x);
  expected_result =
      -sin(-0.2365 * x / atan(1.002) + pow(acos(0.141528), 3.1415)) + x -
      x * x / (-log10(10 * cos(-sqrt(2.3 - 3.7 / 89) + 1415.))) /
          log(3.321 + atan(fmod(-3., 4.)));
  EXPECT_NEAR(result, expected_result, 1e-10);

  x = 4815.162342;
  lexeme =
      "(-sin(-0.2365*x/atan(1.002)+acos(0.141528)^(3.1415))+x-x*x/"
      "(-log(10*cos(-sqrt(2.3-3.7/89)+1415.)))/ln(3.321+atan(-3mod4)))";
  s21::SmartCalc calc4(lexeme);
  result = calc4.Calculate(x);
  expected_result =
      -sin(-0.2365 * x / atan(1.002) + pow(acos(0.141528), 3.1415)) + x -
      x * x / (-log10(10 * cos(-sqrt(2.3 - 3.7 / 89) + 1415.))) /
          log(3.321 + atan(fmod(-3., 4.)));
  EXPECT_NEAR(result, expected_result, 1e-6);

  x = 0.;
  lexeme =
      "(-sin(-0.2365*x/atan(1.002)+acos(0.141528)^(3.1415))+x-x*x/"
      "(-log(10*cos(-sqrt(2.3-3.7/89)+1415.)))/ln(3.321+atan(-3mod4)))";
  s21::SmartCalc calc5(lexeme);
  result = calc5.Calculate(x);
  expected_result =
      -sin(-0.2365 * x / atan(1.002) + pow(acos(0.141528), 3.1415)) + x -
      x * x / (-log10(10 * cos(-sqrt(2.3 - 3.7 / 89) + 1415.))) /
          log(3.321 + atan(fmod(-3., 4.)));
  EXPECT_NEAR(result, expected_result, 1e-10);
}
