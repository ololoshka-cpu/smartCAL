#include "s21_calc.h"

/**
 * @file s21_deposit.c
 * @brief functions for calculate deposit percents
 */

/**
 * @brief profit for curent day
 *
 * @param deposit current remainder in deposit
 * @param rate deposit rate
 * @param days_in_yeay count of days in current year
 *
 * @return percents for current day
 */

double depositProfitForDay(double deposit, double rate, int days_in_year) {
  return round(deposit * rate / days_in_year) / 100;
}

/**
 * @brief calculate tax for current year
 *
 * @param sum total profit for year
 * @param rate rate of central bank
 *
 * @return total tax per current year
 */

double calculateTax(double *sum, double rate) {
  double border = 10000 * rate;
  double res = 0;
  if (*sum > border) {
    res = round((*sum - border) * 13) / 100;
  }
  *sum = 0;
  return res;
}