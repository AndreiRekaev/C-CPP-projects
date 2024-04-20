/*!
\file
\brief Header file of deposit calculator
*/
#ifndef SMARTCALC_MODEL_MODELDEPOSIT_H_
#define SMARTCALC_MODEL_MODELDEPOSIT_H_

#include <cstdint>
#include <utility>

namespace s21 {
/*!
\brief Class for deposit calculation
*/
class DepositCalc {
 public:
  void SetAmount(double a) noexcept;
  void SetDuration(uint32_t d) noexcept;
  void SetRate(double r) noexcept;
  void SetTaxRate(double t) noexcept;
  void SetReplanishment(uint32_t r) noexcept;
  void SetReplanishmentAmount(double r) noexcept;
  void SetWithdrawal(uint32_t w) noexcept;
  void SetWithdrawalAmount(double w) noexcept;
  void SetCapitalization(bool c) noexcept;
  void SetPaymentPeriod(uint32_t p) noexcept;

  void CountDeposit(double& interestCharges, double& taxAmount,
                    double& depAmount) const noexcept;

 private:
  double amount_ = 0;
  uint32_t duration_ = 0;
  double rate_ = 0;
  double taxRate_ = 0;
  uint32_t replanishment_ = 0;
  double replanishmentAmount_ = 0;
  uint32_t withdrawal_ = 0;
  double withdrawalAmount_ = 0;
  bool capitalization_ = false;
  uint32_t paymentPeriod_ = 0;
};

}  // namespace s21

#endif  // SMARTCALC_MODEL_MODELDEPOSIT_H_
