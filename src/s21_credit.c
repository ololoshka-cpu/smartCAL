#include "s21_calc.h"
/**
 * @file s21_credit.c
 * @brief functions for calculate credit percents
 */

/**
 * Calculate monthly payment, total payment and overpayment for annuitial credit
 *
 * @param total_sum sum of credit
 * @param term in month
 * @param rate rate
 * @param mode mode
 * @param monthly result of mmonthly payment
 * @param overpayment result of overpayment
 * @param total result of total payment
 *
 * @return 1: OK
 * @return 0: error
 */

int annuityCredit(int total_sum, int month, double rate, int mode,
                  double *monthly, double *overpayment, double *total) {
  int res = 1;
  if (mode == 2) {
    *monthly = round(total_sum * (rate / 1200) /
                     (1 - pow(1 + rate / 1200, -month)) * 100) /
               100;
    *total = *monthly * month;
    *overpayment = *total - total_sum;
  } else {
    res = 0;
  }
  return res;
}

/**
 * Calculate monthly payment differential credit
 *
 * @param credit remainder of credit sum
 * @param rate rate
 * @param days_in_year count of days in current year
 * @param days_in_month count of days in current month
 *
 * @return current mounth payment
 */

double differentialPayment(double credit, double rate, int days_in_year,
                           int days_in_month) {
  return round(credit * rate * days_in_month / days_in_year) / 100;
}