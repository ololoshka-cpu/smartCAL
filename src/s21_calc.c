#include "s21_calc.h"

/**
 * @file s21_calc.c
 * @brief Main file for basic calculation.
 */

/**
 * @brief Basic function for calculate expression
 *
 * Included parsing, validation and error processing
 *
 * @param src The expression string (May contain 'x' symbol)
 * @param x The string of x expresion if exist, else NULL
 *
 * @return string of calculated expresion
 * @return ERROR_CALCULATE
 * @return ERROR_OPERATION
 * @return ERROR_BRACKETS
 */
char *calculate_expression(char *src, char *x) {
  char *result;
  if (validate_brackets(src)) {
    char *tokenize =
        (char *)calloc(strlen(src) * ((x ? strlen(x) : 10) + 1), sizeof(char));
    int res = tokenize_expression(src, tokenize, x);
    char *rewrited_tokenize =
        (char *)calloc(strlen(tokenize) + 1, sizeof(char));
    res *= rewrite_tokenize(tokenize, rewrited_tokenize);
    free(tokenize);
    if (res && check_tokenize(rewrited_tokenize)) {
      char *polish =
          (char *)calloc(strlen(rewrited_tokenize) + 1, sizeof(char));
      if (expression_to_polish(rewrited_tokenize, polish)) {
        result = calculate_polish(polish, x);
      } else {
        result = (char *)calloc(strlen(ERROR_CALCULATE) + 1, sizeof(char));
        strcat(result, ERROR_CALCULATE);
      }
      free(polish);
    } else {
      result = (char *)calloc(strlen(ERROR_OPERATION) + 1, sizeof(char));
      strcat(result, ERROR_OPERATION);
    }
    free(rewrited_tokenize);
  } else {
    result = (char *)calloc(strlen(ERROR_BRACKETS) + 1, sizeof(char));
    strcat(result, ERROR_BRACKETS);
  }
  return result;
}

/**
 * @brief Calculation result
 *
 * Calculation result of expression, writed in reverse polish notation
 *
 * @param str expression in reverse polish notation
 * @param x x-value, if exist, else NULL
 *
 * @return result number of string format
 * @return ERROR_CALCULATE
 */
char *calculate_polish(char *src, char *x) {
  s21_stack *stack = create_stack();
  char token[TOKEN_SIZE] = {'\0'};
  int res = 1;
  int i = 0;
  while (res && read_lexem(src, &i, token)) {
    if (isdigit(token[0])) {
      push(stack, token);
    } else if (token[0] == 'x') {
      push(stack, x);
    } else if (token[0] == '~' ||
               (isoper(token) && token[0] == '-' && stack->size == 1)) {
      unary_minus(stack);
    } else if (isoper(token) && stack->size > 1) {
      res = oper_stack(stack, token);
    } else if (is_func(token)) {
      res = func_stack(stack, token);
    } else if (isoper(token) && token[0] != '+' && stack->size == 1) {
      res = 0;
    }
    clear_buff(token);
  }
  clear_buff(token);
  char *answer;
  if (res) {
    answer = pop(stack);
  } else {
    answer = (char *)calloc(strlen(ERROR_CALCULATE), sizeof(char));
    strcat(answer, ERROR_CALCULATE);
  }
  remove_stack(stack);

  return answer;
}

/**
 * @brief Find errors in expression
 *
 * Check hidden multiple and functions with empty brackets
 *
 * @param src expression broken to tokens
 *
 * @return 1: OK
 * @return 0: some error
 */
int check_tokenize(const char *src) {
  int res = 1;
  int i = 0;
  char token[31] = {'\0'};
  char prev_token[31] = {'\0'};
  read_lexem(src, &i, prev_token);
  while (read_lexem(src, &i, token)) {
    if (((isdigit(token[0]) || token[0] == 'x') &&
         (isdigit(prev_token[0]) || prev_token[0] == 'x')) ||
        (isoper(token) && isoper(prev_token)) ||
        (is_func(token) && is_func(prev_token)) ||
        (token[0] == '(' && (isdigit(prev_token[0]) || prev_token[0] == 'x')) ||
        ((isdigit(token[0]) || token[0] == 'x') && prev_token[0] == ')') ||
        (isoper(prev_token) && (token[0] == ')' || !strlen(token)))) {
      res = 0;
    }
    if (prev_token[0] == '(' && (token[0] == ')' || token[0] == '*' ||
                                 token[0] == '/' || token[0] == '^')) {
      res = 0;
    }
    clear_buff(prev_token);
    strcat(prev_token, token);
  }
  if (strstr(src, "sin ( )") || strstr(src, "cos ( )") ||
      strstr(src, "tan ( )") || strstr(src, "asin ( )") ||
      strstr(src, "acos ( )") || strstr(src, "atan ( )") ||
      strstr(src, "sqrt ( )") || strstr(src, "log ( )") ||
      strstr(src, "ln ( )")) {
    res = 0;
  }
  if (!strlen(token) && isoper(prev_token)) res = 0;
  return res;
}

/**
 * @brief Check unary signs
 *
 * Rewrited tokenized expression and replce '-+' and '+-' to '-'
 *
 * @param src Input tokenized expression
 * @param output Output tokenized expression
 */

int rewrite_tokenize(const char *src, char *output) {
  int i = 0;
  int res = 1;
  char token[31] = {'\0'};
  char prev_token[31] = {'\0'};
  read_lexem(src, &i, prev_token);
  int oper_count = isoper(prev_token) ? 1 : 0;
  int can_two_oper = 1;
  while (res && read_lexem(src, &i, token)) {
    oper_count = isoper(token) ? oper_count + 1 : 0;
    if (token[0] == '(') can_two_oper = 1;
    if (oper_count > 2) {
      res = 0;
    } else if (oper_count == 2) {
      if (can_two_oper && ((prev_token[0] == '-' && token[0] == '+') ||
                           (prev_token[0] == '+' && token[0] == '-'))) {
        token[0] = '-';
        clear_buff(prev_token);
        can_two_oper = 0;
      } else {
        res = 0;
      }
    }
    strcat(output, prev_token);
    strcat(output, " ");
    clear_buff(prev_token);
    strcat(prev_token, token);
  }
  strcat(output, prev_token);
  return res;
}

/**
 * @brief Split line expression by tokens
 *
 * Parce expression by tokens and insert space between there
 *
 * @param src expression
 * @param output tokenized expresion
 * @param x x value if exist, else NULL
 *
 * @return 1: OK
 * @return 0: error
 */

int tokenize_expression(const char *src, char *output, char *x) {
  int res = 1;
  char *buffer = (char *)calloc(strlen(src), sizeof(char));
  for (int i = 0; res && *(src + i);) {
    if (isdigit(*(src + i))) {
      read_number(src, &i, output, buffer);
    } else if (is_right_symbol(*(src + i))) {
      read_symbol(src, &i, output, x);
    } else if (*(src + i) == ' ') {
      i++;
    } else if (isfunc(src, buffer, &i)) {
      strcat(output, buffer);
      add_char(output, ' ');
      clear_buff(buffer);
    } else {
      res = 0;
    }
  }
  free(buffer);
  return res;
}

/**
 * @brief Parce and read number
 *
 * Parce number in types: integer, floating, scientific
 *
 * @param src expression
 * @param index start parce index
 * @param output output number
 * @param buffer auxilairy buffer
 */

void read_number(const char *src, int *index, char *output, char *buffer) {
  int i = *index;
  read_int(src, &i, buffer);
  if (*(src + i) == '.' && isdigit(*(src + i + 1))) {
    add_char(buffer, '.');
    i++;
    read_int(src, &i, buffer);
  }
  if (*(src + i) == 'e' || *(src + i) == 'E') {
    i++;
    read_exp_number(src, &i, buffer);
  }
  strcat(output, buffer);
  add_char(output, ' ');
  *index = i;
  clear_buff(buffer);
}

/**
 * @brief Symbols processing
 *
 * Processing current symbol, if it is Eiler number, replace it
 *
 * @param src expression
 * @param index current index
 * @param output symbol or token
 * @param x current symbol
 */

void read_symbol(const char *src, int *index, char *output, char *x) {
  int i = *index;
  if (*(src + i) == 'e') {
    strcat(output, "2.7182818");
  } else if (*(src + i) == 'x' && x) {
    add_char(output, 'x');
  } else {
    add_char(output, *(src + i));
  }
  add_char(output, ' ');
  *index = i + 1;
}

/**
 * @brief read scientific number
 *
 * Read number in scientific format if exist dot after digit
 *
 * @param src expression
 * @param index current index
 * @param buffer auxilairy buffer
 */

void read_exp_number(const char *src, int *index, char *buffer) {
  int i = *index;
  int sign = 0;
  int exp;
  if (*(src + i) == '-' || *(src + i) == '+') {
    sign = (*(src + i) == '-' ? 1 : 0);
    i++;
  }
  if (isdigit(*(src + i))) {
    double temp;
    sscanf(buffer, "%lf", &temp);
    clear_buff(buffer);
    read_int(src, &i, buffer);
    sscanf(buffer, "%d", &exp);
    clear_buff(buffer);
    if (sign) exp = -exp;
    temp = temp * pow(10, exp);
    sprintf(buffer, "%.7lf", temp);
  }
  *index = i;
}

/**
 * @brief read integer number
 *
 * @param src expression
 * @param index current index
 * @param buffer auxilairy buffer
 */

void read_int(const char *src, int *index, char *buffer) {
  int i = *index;
  char a = *(src + i++);
  while (isdigit(a)) {
    add_char(buffer, a);
    a = *(src + i++);
  }
  *index = i - 1;
}

/**
 * @brief Check have function
 *
 * Processing current position by function or Pi number
 *
 * @param src expression
 * @param buffer auxilairy buffer
 * @param index current index
 */

int isfunc(const char *src, char *buffer, int *index) {
  int res = 0;
  int i = *index;
  add_char(buffer, *(src + i++));
  add_char(buffer, *(src + i++));
  if (buffer[0] == -49 && buffer[1] == -128) {
    res = 1;
    clear_buff(buffer);
    sprintf(buffer, "%.7f", 3.1415927);
  } else if (!strcmp(buffer, "ln")) {
    res = 1;
  } else {
    add_char(buffer, *(src + i++));
    if (!strcmp(buffer, "cos") || !strcmp(buffer, "sin") ||
        !strcmp(buffer, "tan") || !strcmp(buffer, "log") ||
        !strcmp(buffer, "mod")) {
      res = 1;
    } else {
      add_char(buffer, *(src + i++));
      if (!strcmp(buffer, "acos") || !strcmp(buffer, "asin") ||
          !strcmp(buffer, "atan") || !strcmp(buffer, "sqrt")) {
        res = 1;
      }
    }
  }
  if (res) {
    *index = i;
  } else {
    clear_buff(buffer);
  }
  return res;
}

/**
 * @brief Check current symbol
 *
 * Check current symbol by correct (not digit)
 *
 * @param symbol symbol
 *
 * @return 1: right symbol
 * @return 0: else
 */

int is_right_symbol(char symbol) {
  int res = 0;
  if (symbol == '(') {
    res = 1;
  } else if (symbol == ')') {
    res = 1;
  } else if (symbol == '+') {
    res = 1;
  } else if (symbol == '-') {
    res = 1;
  } else if (symbol == '*') {
    res = 1;
  } else if (symbol == '/') {
    res = 1;
  } else if (symbol == '^') {
    res = 1;
  } else if (symbol == 'e') {
    res = 1;
  } else if (symbol == 'x') {
    res = 1;
  }
  return res;
}

/**
 * @brief Concatenate char to string
 */

void add_char(char *dest, char a) {
  int i = 0;
  while (*(dest + i)) {
    i++;
  }
  *(dest + i) = a;
  *(dest + i + 1) = '\0';
}

/**
 * @brief crear input string
 *
 * Fill the input string by symbl '\0'
 *
 * @param buffer line to be cleared
 */

void clear_buff(char *buffer) {
  int k = strlen(buffer);
  for (int i = 0; i < k; i++) {
    buffer[i] = '\0';
  }
}

/**
 * @brief Calculation function
 *
 * Calculate result of function by value on top on the stack
 *
 * @param stack stack of numbers
 * @param token current function
 *
 * @return 1: OK
 * @return 0: domain error
 */

int func_stack(s21_stack *stack, char *token) {
  int res = 1;
  double tmp;
  char *operand = pop(stack);
  char lexem[TOKEN_SIZE] = {'\0'};
  strcat(lexem, operand);
  free(operand);
  sscanf(lexem, "%lf", &tmp);
  if (!strcmp(token, "ln") && tmp > 0) {
    tmp = log(tmp);
  } else if (!strcmp(token, "log") && tmp > 0) {
    tmp = log10(tmp);
  } else if (!strcmp(token, "sin")) {
    tmp = sin(tmp);
  } else if (!strcmp(token, "cos")) {
    tmp = cos(tmp);
  } else if (!strcmp(token, "tan")) {
    tmp = tan(tmp);
  } else if (!strcmp(token, "asin") && fabs(tmp) <= 1) {
    tmp = asin(tmp);
  } else if (!strcmp(token, "acos") && fabs(tmp) <= 1) {
    tmp = acos(tmp);
  } else if (!strcmp(token, "atan")) {
    tmp = atan(tmp);
  } else if (!strcmp(token, "sqrt") && tmp >= 0) {
    tmp = sqrt(tmp);
  } else {
    res = 0;
  }
  clear_buff(lexem);
  sprintf(lexem, "%.7f", tmp);
  push(stack, lexem);
  return res;
}

/**
 * @brief translate expression line to expression in RPN
 *
 * @param src original line
 * @param output result line
 *
 * @return 1: OK
 * @return 0: some error
 */

int expression_to_polish(const char *src, char *output) {
  int result = 1;
  int i = 0;
  char lexem[31] = {'\0'};
  char prev_lexem[31] = {'\0'};
  int start = 1;
  s21_stack *stack = create_stack();
  while (result && read_lexem(src, &i, lexem)) {
    if ((isdigit(lexem[0]) && isdigit(prev_lexem[0])) ||
        (is_func(lexem) && prev_lexem[0] == ')') ||
        (isoper(lexem) && isoper(prev_lexem))) {
      result = 0;
    } else if (isdigit(lexem[0]) || lexem[0] == 'x') {
      num_token(lexem, output);
    } else if ((isalpha(lexem[0]) || lexem[0] == '(') && lexem[0] != 'm') {
      lexem_to_stack(stack, lexem);
    } else if (isoper(lexem)) {
      result = create_oper(prev_lexem, lexem, start);
      if (stack->size) pop_opers(stack, lexem, output);
      push(stack, lexem);
    } else if (lexem[0] == ')') {
      result = delete_opers(stack, output);
    }
    start = 0;
    clear_buff(prev_lexem);
    strcat(prev_lexem, lexem);
  }
  while (result && stack->size) {
    char *oper = stack->Head->data;
    if (oper[0] == '(' || oper[0] == ')') {
      result = 0;
    } else {
      write_oper(oper, output);
      pop(stack);
      free(oper);
    }
  }
  remove_stack(stack);
  return result;
}

/**
 * @brief step of sorting station algorythm
 *
 * shifts of operations on top on the stack before there priority below then
 * current
 *
 * @param stack current stack
 * @param output ouput line
 *
 * @return 0 : OK
 * @return 1 : some error
 */

int delete_opers(s21_stack *stack, char *output) {
  int res = 0;
  char *oper = stack->Head->data;
  while (stack->size > 1 && oper[0] != '(') {
    write_oper(oper, output);
    pop(stack);
    free(oper);
    oper = stack->Head->data;
  }
  if (oper[0] == '(') {
    pop(stack);
    free(oper);
    if (stack->size && stack->Head->data[0] != 'o' &&
        strlen(stack->Head->data) > 1) {
      strcat(output, stack->Head->data);
      add_char(output, ' ');
      oper = pop(stack);
      free(oper);
    }
    res = 1;
  }
  return res;
}

/**
 * @brief Create lexem of operation
 *
 * @param oper current operation
 * @param output output lexem
 */

void write_oper(char *oper, char *output) {
  add_char(output, oper[2]);
  add_char(output, ' ');
}

/**
 * @brief remove operations on top of the stack
 *
 * @param stack current stack
 * @param oper1 current operation
 * @param output output line
 */

void pop_opers(s21_stack *stack, char *oper1, char *output) {
  char *oper2 = stack->Head->data;
  if (oper1[2] == '^' && oper2[2] == '^') {
    return;
  }
  while (stack->size && oper2[0] == 'o' && (oper2[1] >= oper1[1])) {
    write_oper(oper2, output);
    pop(stack);
    free(oper2);
    oper2 = stack->Head->data;
  }
}

/**
 * @brief write number token to the RPN line
 *
 * @param token current number
 * @param output output line
 */
void num_token(char *token, char *output) {
  strcat(output, token);
  add_char(output, ' ');
}

/**
 * @brief push lexem to stack
 *
 * @param stack current stack
 * @param token current lexem
 */

void lexem_to_stack(s21_stack *stack, char *token) { push(stack, token); }

/**
 * @brief calculate unary minus
 *
 * @param stack current tstack
 */

void unary_minus(s21_stack *stack) {
  char token[TOKEN_SIZE] = {'\0'};
  char *lexem = pop(stack);
  double tmp;
  strcat(token, lexem);
  free(lexem);
  sscanf(token, "%lf", &tmp);
  tmp = -tmp;
  clear_buff(token);
  sprintf(token, "%.7f", tmp);
  push(stack, token);
}

/**
 * @brief calculate result of operation by numbers on top of the stack
 *
 * @param stack current stack
 * @param token current operation
 *
 * @return 1: OK
 * @return 0: error
 */

int oper_stack(s21_stack *stack, char *token) {
  int output = 1;
  double operand1;
  double operand2;
  long double res = 0;
  char *op2 = pop(stack);
  char *op1 = pop(stack);
  char lex1[TOKEN_SIZE] = {'\0'};
  char lex2[TOKEN_SIZE] = {'\0'};
  strcat(lex1, op1);
  strcat(lex2, op2);
  free(op1);
  free(op2);
  sscanf(lex1, "%lf", &operand1);
  sscanf(lex2, "%lf", &operand2);
  if (token[0] == '+') {
    res = operand1 + operand2;
  } else if (token[0] == '-') {
    res = operand1 - operand2;
  } else if (token[0] == '*') {
    res = operand1 * operand2;
  } else if (token[0] == '/') {
    if (fabs(operand2) > 1e-6) {
      res = operand1 / operand2;
    } else {
      output = 0;
    }
  } else if (token[0] == '^') {
    res = pow(operand1, operand2);
  } else if (token[0] == 'm') {
    res = fmod(operand1, operand2);
  }
  char result[TOKEN_SIZE] = {'\0'};
  sprintf(result, "%.7Lf", res);
  push(stack, result);
  return output;
}

/**
 * @brief create special lexem of operation
 *
 * @param prev_lexem previos lexem of current
 * @param oper current operation
 * @param start flag of start original line
 *
 * @return 1: OK
 * @return 0: error
 */

int create_oper(char *prev_lexem, char *oper, int start) {
  int res = 1;
  char new_oper[7] = {'\0'};
  add_char(new_oper, 'o');
  if (oper[0] == '+' || oper[0] == '-') {
    add_char(new_oper, '1');
  } else if (oper[0] == '*' || oper[0] == '/' || oper[0] == 'm') {
    add_char(new_oper, '2');
  } else {
    add_char(new_oper, '3');
  }
  if ((oper[0] == '-' && (prev_lexem[0] == '(' || start))) {
    add_char(new_oper, '~');
  } else {
    add_char(new_oper, oper[0]);
  }
  clear_buff(oper);
  strcat(oper, new_oper);
  return res;
}

/**
 * @brief read current lexem
 *
 * @param src original line
 * @param index current index
 * @param lexem string to write to lexem
 *
 * @return length of lexem
 */

int read_lexem(const char *src, int *index, char *lexem) {
  int i = *(src + *index) == ' ' ? *index + 1 : *index;
  clear_buff(lexem);
  while (*(src + i) == ' ') i++;
  while (*(src + i) != '\0' && *(src + i) != ' ') {
    add_char(lexem, *(src + i++));
  }
  *index = i;
  return strlen(lexem);
}

/**
 * @brief check current char to operation
 *
 * @param token current operation token
 *
 * @return 1: token is operation
 * @return 0: else
 */

int isoper(char *token) {
  char a = token[0];
  return a == '+' || a == '-' || a == '*' || a == '/' || a == '^' || a == 'm';
}

/**
 * @brief check current char to function
 *
 * @param token current function token
 *
 * @return 1: token is function
 * @return 0: else
 */

int is_func(char *token) {
  char a = token[0];
  return a == 's' || a == 'c' || a == 't' || a == 'a' || a == 'l';
}

/**
 * @brief validate right brackets
 *
 * @param src input line
 *
 * @return 1: brackets right
 * @return 0: error
 */

int validate_brackets(const char *src) {
  int brackets = 0;
  char *str = (char *)src;
  while (*str != '\0' && brackets >= 0) {
    if (*str == '(') {
      brackets++;
    } else if (*str == ')') {
      brackets--;
    }
    str++;
  }
  return brackets == 0;
}