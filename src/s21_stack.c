#include "s21_stack.h"

#include <stdio.h>

/**
 * @file s21_stack.c
 * @brief implementation of stack for calculator
 */

/**
 * @brief init stask
 *
 * @return stack
 */

s21_stack *create_stack() {
  s21_stack *res = (s21_stack *)calloc(1, sizeof(s21_stack));
  if (res != NULL) {
    res->size = 0;
    res->Head = NULL;
  }
  return res;
}

/**
 * @brief init node
 *
 * @return node
 */

s21_node *create_node() {
  s21_node *res = (s21_node *)calloc(1, sizeof(s21_node));
  if (res != NULL) {
    res->next = NULL;
    res->data = NULL;
  }
  return res;
}

/**
 * @brief push operation
 *
 * Add current element to top of the stack
 *
 * @param stack current stack
 * @param data value
 *
 * @return 1: OK
 * @return 0: error
 */

int push(s21_stack *stack, char *data) {
  s21_node *node = create_node();
  if (node != NULL) {
    node->data = (char *)calloc(strlen(data) + 1, sizeof(char));
    if (node->data) {
      strcpy(node->data, data);
      node->next = stack->Head;
      stack->Head = node;
      stack->size++;
    }
  }
  return (node || node->data);
}

/**
 * @brief remove top element of stack
 *
 * @param stack current stack
 *
 * @return poped element
 */
char *pop(s21_stack *stack) {
  char *res = NULL;
  if (!stack || stack->size > 0) {
    if (stack->size == 1) {
      res = stack->Head->data;
      free(stack->Head);
      stack->size = 0;
    } else {
      s21_node *tmp = stack->Head;
      res = tmp->data;
      stack->Head = stack->Head->next;
      free(tmp);
      stack->size--;
    }
  }
  return res;
}

/**
 * @brief remove stack
 *
 * @param stack current stack
 */
void remove_stack(s21_stack *stack) {
  if (stack) {
    while (stack->size) {
      free(pop(stack));
    }
    free(stack);
  }
}
