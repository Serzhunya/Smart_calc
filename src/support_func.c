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

// 1.2 3.5 4 + 3.5 3 * - * 10 * 3 1 + 1 + / 20 - 4 3 ^ + 5 -
// 1.2 3.5 4 + 3.5 3 * - * 10 * 3 1 + 1 + / 20 - 4 3 ^ 5-+

int distribution_lexem(char* lexem, Stack_sign* sign_st, char* pol_notation) {
  int err = 0;
  char sign_cur = *lexem;
  char sign_in_stack;
  if (sign_cur >= 48 && sign_cur <= 57) {
    strcat(pol_notation, lexem);
  }
  if (sign_cur == '-' || sign_cur == '+' || sign_cur == '/' ||
      sign_cur == '*' || sign_cur == '^') {
    if (!isempty_sign(sign_st)) {
      sign_in_stack = peek_sign(sign_st);
    }

    if (priority(sign_cur) <= priority(sign_in_stack)) {
      char array_sign_in_stack[2] = {sign_in_stack, '\0'};
      strcat(pol_notation, array_sign_in_stack);
      pop_sign(sign_st);
    }
    push_sign(sign_st, sign_cur);
  }
  if (sign_cur == '(') {
    push_sign(sign_st, sign_cur);
  }
  if (sign_cur == ')') {
    sign_in_stack = peek_sign(sign_st);
    while (sign_in_stack != '(') {
      char array_sign_in_stack[2] = {sign_in_stack, '\0'};
      strcat(pol_notation, array_sign_in_stack);
      pop_sign(sign_st);
      sign_in_stack = peek_sign(sign_st);
    }
    pop_sign(sign_st);
  }
  printStack_sign(sign_st);
  return err;
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
      // case '(':
      //   prioritet = 4;
      //   break;
    case '^':
      prioritet = 4;
      break;
  }
  return prioritet;
}

// double get_operation(Stack_digit* digit_st, Stack_sign* sign_st) {
//   double result = 0.0;
//   double num1 = pop_digit(digit_st);
//   double num2 = pop_digit(digit_st);
//   char sign = pop_sign(sign_st);
//   result = math(num1, num2, sign);
//   return result;
// }

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
