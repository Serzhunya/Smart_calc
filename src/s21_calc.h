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

char* create_polish_notation(char* input, Stack_sign sign_st);
void createEmptyStack_sign(Stack_sign* stack);
char* create_lexem(char* input);
void distribution_lexem(char* lexem, Stack_sign* sign_st, char* pol_notation);
void push_sign(Stack_sign* stack, char value);
char pop_sign(Stack_sign* stack);
void printStack_sign(Stack_sign* stack);
double math(double num1, double num2, char sign);
int check_operator(char* res, Stack_sign* sign_st);
int priority(char sign);
char peek_sign(Stack_sign* stack);
int isempty_sign(Stack_sign* stack);
double create_output(char* pol_notation, Stack_sign sign_st,
                     Stack_digit digit_st);
void parsing_pol_notation(char* lexem, Stack_sign* sign_st,
                          Stack_digit* digit_st);
void push_digit(Stack_digit* stack, double newitem);
void printStack_digit(Stack_digit* stack);
void createEmptyStack_digit(Stack_digit* stack);
double pop_digit(Stack_digit* stack);
#endif  // SRC_S21_CALC_H_
