#ifndef SRC_S21_CALC_H_
#define SRC_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 500
#define STACK_OVERFLOW -100
#define STACK_UNDERFLOW -101

typedef struct Stack_tag {
  double data[STACK_MAX_SIZE];
  int top;
  int count;
} Stack_digit;

typedef struct Stack_t {
  char data[STACK_MAX_SIZE];
  int top;
  int count;
} Stack_sign;

void createEmptyStack_sign(Stack_sign* stack);
void createEmptyStack_digit(Stack_digit* stack);
char* create_lexem(char* input);
int distribution_res(char* res, Stack_digit* digit_st, Stack_sign* sign_st);
void push_digit(Stack_digit* stack, double value);
void push_sign(Stack_sign* stack, char value);
double pop_digit(Stack_digit* stack);
char pop_sign(Stack_sign* stack);
void printStack_digit(Stack_digit* stack);
void printStack_sign(Stack_sign* stack);
double math(double num1, double num2, char sign);
int check_operator(char* res, Stack_sign* sign_st);
int priority(char sign);
char peek_sign(Stack_sign* stack);
double get_operation(Stack_digit* digit_st, Stack_sign* sign_st);
double create_calc(char* input, Stack_digit digit_st, Stack_sign sign_st);
#endif  // SRC_S21_CALC_H_
