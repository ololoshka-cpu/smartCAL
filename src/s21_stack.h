#ifndef SRC_S21_STACK_H_
#define SRC_S21_STACK_H_

#include <math.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct s21_node {
  char *data;
  struct s21_node *next;
} s21_node;

typedef struct s21_stack {
  s21_node *Head;
  size_t size;
} s21_stack;

s21_stack *create_stack();
int push(s21_stack *, char *);
char *pop(s21_stack *);
void remove_stack(s21_stack *);

#ifdef __cplusplus
}
#endif  //  extern "C"

#endif  //  SRC_S21_STACK_H_
