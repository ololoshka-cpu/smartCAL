#include <stdio.h>

#include "s21_calc.h"
#include "s21_stack.h"

int main(void) {
  printf("%s\n", calculate_expression("1/0", NULL));
  return 0;
}