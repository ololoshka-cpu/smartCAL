#ifndef SRC_CALC_H_
#define SRC_CALC_H_

#include <ctype.h>
#include <stdio.h>

#include "s21_stack.h"

#define TOKEN_SIZE 31
#define ERROR_CALCULATE "error in calculate polish"
#define ERROR_OPERATION "operation or funtion error!"
#define ERROR_BRACKETS "brackets error!"

#ifdef __cplusplus
extern "C" {
#endif

void add_char(char *dest, char a);
void clear_buff(char *buffer);
void num_token(char *token, char *output);
void lexem_to_stack(s21_stack *stack, char *lexem);
void pop_opers(s21_stack *stack, char *oper1, char *output);
void read_int(const char *src, int *index, char *buffer);
void read_number(const char *src, int *index, char *output, char *buffer);
void read_symbol(const char *src, int *index, char *output, char *x);
void read_exp_number(const char *src, int *index, char *buffer);
void write_oper(char *oper, char *output);
void unary_minus(s21_stack *stack);

int rewrite_tokenize(const char *src, char *output);
int func_stack(s21_stack *stack, char *token);
int tokenize_expression(const char *src, char *output, char *x);
int create_oper(char *prev_lexem, char *lexem, int start);
int delete_opers(s21_stack *stack, char *output);
int read_lexem(const char *src, int *index, char *lexem);
int isfunc(const char *src, char *buffer, int *index);
int is_func(char *token);
int is_right_symbol(char symbol);
int isoper(char *token);
int check_tokenize(const char *src);
int expression_to_polish(const char *src, char *output);
int validate_brackets(const char *src);
int oper_stack(s21_stack *stack, char *token);

char *calculate_expression(char *src, char *x);
char *calculate_polish(char *src, char *x);

int annuityCredit(int total_sum, int month, double rate, int type,
                  double *monthly, double *overpayment, double *total);
double differentialPayment(double credit, double rate, int days_in_year,
                           int days_in_month);
double depositProfitForDay(double deposit, double rate, int days_in_year);
double calculateTax(double *sum, double rate);
#ifdef __cplusplus
}
#endif  //  extern "C"

#endif  //  SRC_CALC_H_
