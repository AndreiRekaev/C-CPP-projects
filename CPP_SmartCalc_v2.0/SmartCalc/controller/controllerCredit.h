/*!
\file
\brief Header file with realisation of Credit Calculator Controller
*/
#ifndef SRC_CONTROLLER_CONTROLLERCREDIT_H_
#define SRC_CONTROLLER_CONTROLLERCREDIT_H_

#include "../model/modelCredit.h"

namespace s21 {
/*!
\brief Class of controller for Credit calculator
*/
class ControllerCredit {
 public:
  /*!
  \brief Setter for amount of credit
  \param[in] a Transfering value
  */
  void SetAmount(double a) noexcept { calc_.SetAmount(a); }

  /*!
  \brief Setter for duration of credit
  \param[in] d Transfering value
  */
  void SetDuration(uint32_t d) noexcept { calc_.SetDuration(d); }

  /*!
  \brief Setter for rate of credit
  \param[in] r Transfering value
  */
  void SetRate(double r) noexcept { calc_.SetRate(r); }

  /*!
  \brief Function for calculation annuity credit
  \param[out] monthlyPayment Amount of monthly payment
  \param[out] interestCharges Amount of overpay for the credit
  \param[out] totalPayment Sum of total cash
  */
  void CountAnnuityCredit(double& monthlyPayment, double& interestCharges,
                          double& totalPayment) noexcept {
    calc_.AnnuityCredit(monthlyPayment, interestCharges, totalPayment);
  }

  /*!
  \brief Function for calculation differentive credit
  \param[out] firstPayment Amount of payment in first month
  \param[out] lastPayment Amount of payment in last month
  \param[out] interestCharges Amount of overpay for the credit
  \param[out] totalPayment Sum of total cash
  */
  void CountDiffCredit(double& firstPayment, double& lastPayment,
                       double& interestCharges, double& totalPayment) noexcept {
    calc_.DiffCredit(firstPayment, lastPayment, interestCharges, totalPayment);
  }

 private:
  CreditCalc calc_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLERCREDIT_H_
