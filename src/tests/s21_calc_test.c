#include "test.h"

START_TEST(calc_test_1) {
  char src[] = "+1-1";
  char real_res[] = "0.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_2) {
  char src[] = "(1 + (1)";
  char real_res[] = ERROR_BRACKETS;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_3) {
  char src[] = "1+-*3";
  char real_res[] = ERROR_OPERATION;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_4) {
  char src[] = "+1-1*";
  char real_res[] = ERROR_OPERATION;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_5) {
  char src[] = "log(-1)";
  char real_res[] = ERROR_CALCULATE;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_6) {
  char src[] = "sin(0) sin(1)";
  char real_res[] = ERROR_CALCULATE;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_7) {
  char src[] = "sin(1) + ln(e) * log(100) ^ (-tan(x))";
  char real_res[] = "1.9453228";
  char *answer = calculate_expression(src, "3");
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_8) {
  char src[] = "sin(1)";
  char real_res[] = "0.8414710";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_9) {
  char src[] = "ln(e)";
  char real_res[] = "1.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_10) {
  char src[] = "log(100)";
  char real_res[] = "2.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_11) {
  char src[] = "-tan(3)";
  char real_res[] = "0.1425465";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_12) {
  char src[] = "sin(4) ^ 2 + cos(4) ^ 2";
  char real_res[] = "1.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_13) {
  char src[] = "asin(-1) + acos(-1) * atan(3)";
  char real_res[] = "2.3531969";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_14) {
  char src[] = "sqrt(-3)";
  char real_res[] = ERROR_CALCULATE;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_15) {
  char src[] = "sqrt(9)";
  char real_res[] = "3.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_16) {
  char src[] = "sqrt()";
  char real_res[] = ERROR_OPERATION;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_17) {
  char src[] = "3 + a";
  char real_res[] = ERROR_OPERATION;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_18) {
  char src[] = "1e3 + 3";
  char real_res[] = "1003.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_19) {
  char src[] = "1.001e3 - 1.1";
  char real_res[] = "999.9000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_20) {
  char src[] = "1001e-3 - 1e-3";
  char real_res[] = "1.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_21) {
  char src[] = "123 / 10";
  char real_res[] = "12.3000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_22) {
  char src[] = "54 mod 7";
  char real_res[] = "5.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_23) {
  char src[] = "cos(π)";
  char real_res[] = "-1.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_24) {
  char src[] = "-1^(-1)";
  char real_res[] = "-1.0000000";
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(calc_test_25) {
  char src[] = "1/0";
  char real_res[] = ERROR_CALCULATE;
  char *answer = calculate_expression(src, NULL);
  ck_assert_str_eq(answer, real_res);
  free(answer);
}
END_TEST

START_TEST(annuity_credit_test) {
  int real_res = 1;
  double overpayment, total, mounthly;
  int res = annuityCredit(1000000, 3, 12.5, 2, &mounthly, &overpayment, &total);
  ck_assert_double_eq(overpayment, 20905.31000000005587935448);
  ck_assert_double_eq(total, 1020905.31);
  ck_assert_double_eq(mounthly, 340301.77);
  ck_assert_int_eq(res, real_res);
  res = annuityCredit(1000000, 3, 12.5, 0, &mounthly, &overpayment, &total);
  ck_assert_int_eq(res, 0);
}
END_TEST

START_TEST(differential_credit_test) {
  double real_res = 10616.44;
  double res = differentialPayment(1000000, 12.5, 365, 31);
  ck_assert_double_eq(real_res, res);
}
END_TEST

START_TEST(deposit_test_1) {
  double real_res = 342.47;
  double res = depositProfitForDay(1000000, 12.5, 365);
  ck_assert_double_eq(res, real_res);
}
END_TEST

START_TEST(deposit_test_2) {
  double real_res = 1950;
  double sum = 100000;
  double res = calculateTax(&sum, 8.5);
  ck_assert_double_eq(res, real_res);
}

Suite *s21_calc_suite() {
  Suite *calc_suite = suite_create("CALC SUITE");
  TCase *calc_tcase = tcase_create("CALC TCASE");
  tcase_add_test(calc_tcase, calc_test_1);
  tcase_add_test(calc_tcase, calc_test_2);
  tcase_add_test(calc_tcase, calc_test_3);
  tcase_add_test(calc_tcase, calc_test_4);
  tcase_add_test(calc_tcase, calc_test_5);
  tcase_add_test(calc_tcase, calc_test_6);
  tcase_add_test(calc_tcase, calc_test_7);
  tcase_add_test(calc_tcase, calc_test_8);
  tcase_add_test(calc_tcase, calc_test_9);
  tcase_add_test(calc_tcase, calc_test_10);
  tcase_add_test(calc_tcase, calc_test_11);
  tcase_add_test(calc_tcase, calc_test_12);
  tcase_add_test(calc_tcase, calc_test_13);
  tcase_add_test(calc_tcase, calc_test_14);
  tcase_add_test(calc_tcase, calc_test_15);
  tcase_add_test(calc_tcase, calc_test_16);
  tcase_add_test(calc_tcase, calc_test_17);
  tcase_add_test(calc_tcase, calc_test_18);
  tcase_add_test(calc_tcase, calc_test_19);
  tcase_add_test(calc_tcase, calc_test_20);
  tcase_add_test(calc_tcase, calc_test_21);
  tcase_add_test(calc_tcase, calc_test_22);
  tcase_add_test(calc_tcase, calc_test_23);
  tcase_add_test(calc_tcase, calc_test_24);
  tcase_add_test(calc_tcase, calc_test_25);
  tcase_add_test(calc_tcase, annuity_credit_test);
  tcase_add_test(calc_tcase, differential_credit_test);
  tcase_add_test(calc_tcase, deposit_test_1);
  tcase_add_test(calc_tcase, deposit_test_2);
  suite_add_tcase(calc_suite, calc_tcase);
  return calc_suite;
}