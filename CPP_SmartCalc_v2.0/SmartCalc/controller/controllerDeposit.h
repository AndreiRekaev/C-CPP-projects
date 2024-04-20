/*!
\file
\brief Header file with realisation of Deposit Calculator Controller
*/
#ifndef SRC_CONTROLLER_CONTROLLERDEPOSIT_H_
#define SRC_CONTROLLER_CONTROLLERDEPOSIT_H_

#include "../model/modelDeposit.h"

namespace s21 {
/*!
\brief Class of controller for Deposit calculator
*/
class ControllerDeposit {
 public:
  /*!
  \brief Setter for amount of deposit
  \param[in] a Transfering value
  */
  void SetAmount(double a) noexcept { calc_.SetAmount(a); }

  /*!
  \brief Setter for duration of deposit
  \param[in] d Transfering value
  */
  void SetDuration(uint32_t d) noexcept { calc_.SetDuration(d); }
  /*!
  \brief Setter for rate of deposit
  \param[in] r Transfering value
  */
  void SetRate(double r) noexcept { calc_.SetRate(r); }

  /*!
  \brief Setter for taxrate of deposit
  \param[in] t Transfering value
  */
  void SetTaxRate(double t) noexcept { calc_.SetTaxRate(t); }

  /*!
  \brief Setter for partial replanishment (if has)
  \param[in] r Transfering value
  */
  void SetReplanishment(uint32_t r) noexcept { calc_.SetReplanishment(r); }

  /*!
  \brief Setter for amount of partial replanishment (if has)
  \param[in] r Transfering value
  */
  void SetReplanishmentAmount(double r) noexcept {
    calc_.SetReplanishmentAmount(r);
  }

  /*!
  \brief Setter for partiol withdrawal (if has)
  \param[in] w Transfering value
  */
  void SetWithdrawal(uint32_t w) noexcept { calc_.SetWithdrawal(w); }

  /*!
  \brief Setter for amount of partial withdrawal (if has)
  \param[in] w Transfering value
  */
  void SetWithdrawalAmount(double w) noexcept { calc_.SetWithdrawalAmount(w); }

  /*!
  \brief Setter for capitalization
  \param[in] c Transfering value (has or no)
  */
  void SetCapitalization(bool c) noexcept { calc_.SetCapitalization(c); }

  /*!
  \brief Setter for payment frequency to client (if ==0 -> in the end)
  \param[in] p Transfering value
  */
  void SetPaymentPeriod(uint32_t p) noexcept { calc_.SetPaymentPeriod(p); }

  /*!
  \brief Function for calculation deposit parameters
  \param[out] interestCharges Amount of accumulated gain
  \param[out] taxAmount Amount of tax to pay
  \param[out] depAmount Amount tottal money at the end
  */
  void CountDeposit(double& interestCharges, double& taxAmount,
                  double& depAmount) noexcept {
    return calc_.CountDeposit(interestCharges, taxAmount, depAmount);
  }

 private:
  DepositCalc calc_;
};
}  // namespace s21

#endif  // SRC_CONTROLLER_CONTROLLERDEPOSIT_H_
