#include "s21_calc.h"

char* create_lexem(char* input) {
  char* sign = "+-*/() ^mcstainqlo=";
  int index = strcspn(input, sign);
  char* lexem = calloc(255, sizeof(char));
  if (index == 0) {
    lexem[index] = input[index];
  } else {
    for (int i = 0; i < index; i++) {
      lexem[i] = input[i];
    }
  }
  return lexem;
}

void distribution_lexem(char* lexem, Stack_sign* sign_st, char* pol_notation) {
  char sign_in_stack = '\0';
  if (*lexem >= 48 && *lexem <= 57) {
    strcat(pol_notation, lexem);
    strcat(pol_notation, " ");
  }
  char sign_cur = *lexem;
  if (sign_cur == '-' || sign_cur == '+' || sign_cur == '/' ||
      sign_cur == '*' || sign_cur == '^' || sign_cur == 'm') {
    if (!isempty_sign(sign_st)) {
      sign_in_stack = peek_sign(sign_st);
    }
    while (priority(sign_cur) <= priority(sign_in_stack) && sign_cur != '^') {
      char array_sign_in_stack[3] = {sign_in_stack, ' ', '\0'};
      strcat(pol_notation, array_sign_in_stack);
      pop_sign(sign_st);
      if (isempty_sign(sign_st)) {
        break;
      }
      sign_in_stack = peek_sign(sign_st);
    }
    push_sign(sign_st, sign_cur);
  }

  if (sign_cur == 's' || sign_cur == 'c' || sign_cur == 't' ||
      sign_cur == 'a' || sign_cur == 'i' || sign_cur == 'n' ||
      sign_cur == 'q' || sign_cur == 'l' || sign_cur == 'o') {
    push_sign(sign_st, sign_cur);
    push_sign(sign_st, '(');
  }
  if (sign_cur == '(') {
    push_sign(sign_st, sign_cur);
  }
  if (sign_cur == ')') {
    if (!isempty_sign(sign_st)) {
      sign_in_stack = peek_sign(sign_st);
    }
    while (sign_in_stack != '(') {
      char array_sign_in_stack[3] = {sign_in_stack, ' ', '\0'};
      strcat(pol_notation, array_sign_in_stack);
      pop_sign(sign_st);
      if (!isempty_sign(sign_st)) {
        sign_in_stack = peek_sign(sign_st);
      }
    }
    pop_sign(sign_st);
  }
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
    case 'm':
      prioritet = 3;
      break;
    case '^':
      prioritet = 4;
      break;
    case 's':
    case 'c':
    case 't':
    case 'a':
    case 'i':
    case 'n':
    case 'q':
    case 'l':
    case 'o':
      prioritet = 5;
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

double get_operation_unary(Stack_digit* digit_st, Stack_sign* sign_st) {
  double result = 0.0;
  double num1 = pop_digit(digit_st);
  char sign = pop_sign(sign_st);
  result = math_unary(num1, sign);
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
    case 'm':
      result = fmod(num2, num1);
      break;
    case '^':
      result = pow(num2, num1);
      break;
  }
  return result;
}

double math_unary(double num1, char sign) {
  double result = 0.0;
  switch (sign) {
    case 's':
      result = sin(num1);
      break;
    case 'c':
      result = cos(num1);
      break;
    case 't':
      result = tan(num1);
      break;
    case 'a':
      result = acos(num1);
      break;
    case 'i':
      result = asin(num1);
      break;
    case 'n':
      result = atan(num1);
      break;
    case 'q':
      result = sqrt(num1);
      break;
    case 'l':
      result = log10(num1);
      break;
    case 'o':
      result = log(num1);
      break;
  }
  return result;
}

void parsing_pol_notation(char* lexem, Stack_sign* sign_st,
                          Stack_digit* digit_st) {
  char sign_cur = *lexem;
  if (sign_cur >= 48 && sign_cur <= 57) {
    double num = atof(lexem);
    push_digit(digit_st, num);
  }
  if (sign_cur == '-' || sign_cur == '+' || sign_cur == '/' ||
      sign_cur == '*' || sign_cur == '^' || sign_cur == 'm') {
    push_sign(sign_st, sign_cur);
    double result = get_operation(digit_st, sign_st);
    push_digit(digit_st, result);
  }
  if (sign_cur == 's' || sign_cur == 'c' || sign_cur == 't' ||  // sin cos tan
      sign_cur == 'a' || sign_cur == 'i' ||
      sign_cur == 'n' ||  // acos asin atan
      sign_cur == 'q' || sign_cur == 'l' || sign_cur == 'o') {  // sqrt ln log
    push_sign(sign_st, sign_cur);
    double result = get_operation_unary(digit_st, sign_st);
    push_digit(digit_st, result);
  }
}
