/**
 * @file s21_calc.h
 */

#ifndef SRC_PROJECT_S21_CALC_H_
#define SRC_PROJECT_S21_CALC_H_

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 255
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

/**
 * @brief This function calc mathematical expression
 *
 * @param input is a mathematical expression whose data type is a
 * character array
 */

double calc(char* input);

/**
 * @brief This function create_input_change change the mathematical expression
 *
 * @param input is a not parsed mathematical expression whose data type
 * is a character array
 */

char* create_input_change(char* input);

/**
 * @brief This function create_polish_notation create polish notation
 *
 * @param input_change is a mathematical expression whose data type is a
 * character array
 * @param sign_st is a stack of sign
 */

char* create_polish_notation(char* input_change, Stack_sign sign_st);

/**
 * @brief This function create_output create output
 *
 * @param pol_notation is a polish notation
 * @param sign_st is a stack of signs
 * @param digit_st is a stack of digits
 */

double create_output(char* pol_notation, Stack_sign sign_st,
                     Stack_digit digit_st);

/**
 * @brief Create a EmptyStack of digit
 *
 * @param stack is a stack of digits
 */

void createEmptyStack_digit(Stack_digit* stack);

/**
 * @brief This function push on top of the stack
 *
 * @param stack is a stack of digits
 * @param newitem is a value to add to the stack
 */

void push_digit(Stack_digit* stack, double newitem);

/**
 * @brief This function pop the top val of the stack
 *
 * @param stack is a stack of digits
 */

double pop_digit(Stack_digit* stack);

/**
 * @brief This print Stack_digit
 *
 * @param stack is a stack of digits
 */

void printStack_digit(Stack_digit* stack);

/**
 * @brief This function createEmptyStack_sign create empty stack of signs
 *
 * @param stack is a stack of signs
 */

void createEmptyStack_sign(Stack_sign* stack);

/**
 * @brief This function check if stack is empty
 *
 * @param stack is a stack of signs
 */

int isempty_sign(Stack_sign* stack);

/**
 * @brief Push on top of the stack
 *
 * @param stack is a stack of signs
 * @param value is a value to add to the stack
 */

void push_sign(Stack_sign* stack, char value);

/**
 * @brief Pop the top val of the stack
 *
 * @param stack is a stack of signs
 */

char pop_sign(Stack_sign* stack);

/**
 * @brief destroyes the stack
 *
 * @param stack is a stack of signs
 */

char peek_sign(Stack_sign* stack);

/**
 * @brief This print Stack_sign
 *
 * @param stack is a stack of signs
 */

void printStack_sign(Stack_sign* stack);

/**
 * @brief This function create_lexem create lexem
 *
 * @param input is a mathematical expression whose data type is a
 * character array
 */

char* create_lexem(char* input);

/**
 * @brief This function distribution_lexem distribute lexem
 *
 * @param input is a mathematical expression whose data type is a
 * character array
 * @param sign_st is a stack of signs
 * @param pol_notation is a polish notation
 */

void distribution_lexem(char* lexem, Stack_sign* sign_st, char* pol_notation);

/**
 * @brief This function distribution priotity sign
 *
 * @param sign is a stack of signs
 */

int priority(char sign);

/**
 * @brief Get the operation object
 *
 * @param digit_st is a stack of digits
 * @param sign_st is a stack of signs
 */

double get_operation(Stack_digit* digit_st, Stack_sign* sign_st);

/**
 * @brief Get the operation unary object
 *
 * @param digit_st is a stack of digits
 * @param sign_st is a stack of signs
 */

double get_operation_unary(Stack_digit* digit_st, Stack_sign* sign_st);

/**
 * @brief This function does mathematical operation
 *
 * @param num1 Value
 * @param num2 Value
 * @param sign is a stack of signs
 */

double math(double num1, double num2, char sign);

/**
 * @brief This function does mathematical operation
 *
 * @param num1 Value
 * @param sign is a stack of signs
 */

double math_unary(double num1, char sign);

/**
 * @brief This function parsing polish notation
 *
 * @param lexem is a lexem
 * @param sign_st is a stack of signs
 * @param digit_st is a stack of digits
 */

void parsing_pol_notation(char* lexem, Stack_sign* sign_st,
                          Stack_digit* digit_st);

/**
 * @brief Checks if the string only has allowed characters
 *
 * @param input_str Given string
 */

int validation(char* input_str);

/**
 * @brief Create a graphic object
 *
 * @param input Given string
 * @param sign_st is a stack of signs
 * @param x X value
 */

double create_graphic(char* input, Stack_sign sign_st, double x);

/**
 * @brief Create a output xy object
 *
 * @param polish_notation
 * @param sign_st is a stack of signs
 * @param digit_st is a stack of digits
 * @param x X value
 */

double create_output_xy(char* polish_notation, Stack_sign* sign_st,
                        Stack_digit* digit_st, double x);

/**
 * @brief This function parsing polish notation
 *
 * @param lexem is a lexem
 * @param sign_st is a stack of signs
 * @param digit_st is a stack of digits
 * @param x X value
 */

void parsing_pol_notation_xy(char* lexem, Stack_sign* sign_st,
                             Stack_digit* digit_st, double x);

#endif  // SRC_PROJECT_S21_CALC_H_
