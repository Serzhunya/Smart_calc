#include "s21_calc.h"

char* create_lexem(char* input) {
  char* sign = "+-*/()^=";
  int index = strcspn(input, sign);
  char* lexem = calloc(1, sizeof(1000));
  if (index == 0) {
    lexem[index] = input[index];
  } else {
    for (int i = 0; i < index; i++) {
      lexem[i] = input[i];
    }
  }
  return lexem;
}

int distribution_res(char* res, Stack_digit* digit_st, Stack_sign* sign_st) {
  int err = 0;
  if (*res == 41) {
    err == 1;
  } else {
    if (*res >= 48 && *res <= 57) {
      double num = atof(res);
      printf("num:%f\n", num);
      push_digit(digit_st, num);
    } else {
      char sign = *res;
      push_sign(sign_st, sign);
      printf("sign:%c\n", sign);
    }
  }
  return err;
}

int check_operator(char* res, Stack_sign* sign_st) {
  int code = 1;
  if (*res >= 48 && *res <= 57) {
    code = 0;
  } else {
    if (*res == 41) {  // если закр скобка
      code = 2;
    } else if (*res == 40) {  // если откр скобка
      code = 3;
    } else {
      char sign = peek_sign(sign_st);
      if (priority(*res) <= priority(sign)) {
        code = 1;
      } else {
        code = 0;
      }
    }
  }
  return code;
}

int priority(char sign) {
  int prioritet = 0;
  switch (sign) {
    case '=':
      prioritet = 1;
      break;
    case '+':
    case '-':
      prioritet = 2;
      break;
    case '*':
    case '/':
      prioritet = 3;
      break;
    case '(':
    case ')':
      prioritet = 4;
      break;
  }
  return prioritet;
}

double get_operation(Stack_digit* digit_st, Stack_sign* sign_st) {
  double result = 0.0;
  double num1 = pop_digit(digit_st);
  double num2 = pop_digit(digit_st);
  char sign = pop_sign(sign_st);
  result = math(num1, num2, sign);
  return result;
}

double math(double num1, double num2, char sign) {
  double result = 0.0;
  switch (sign) {
    case '+':
      result = num2 + num1;
      break;
    case '-':
      result = num2 - num1;
      break;
    case '*':
      result = num2 * num1;
      break;
    case '/':
      result = num2 / num1;
      break;
  }
  return result;
}
