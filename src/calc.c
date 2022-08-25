#include "s21_calc.h"

int main(void) {
  Stack_digit digit_st;
  Stack_sign sign_st;
  char* input = "2-9+3/1*100/5=";
  double result_main = create_calc(input, digit_st, sign_st);
  printf("result_main: %f\n", result_main);
  return 0;
}

double create_calc(char* input, Stack_digit digit_st, Stack_sign sign_st) {
  double result_main = 0.0;
  createEmptyStack_digit(&digit_st);
  createEmptyStack_sign(&sign_st);
  double result;
  for (int i = strlen(input); i > 0; i--) {
    if (strlen(input) == 0) {
      break;
    }
    printf("\n");
    char* res = create_lexem(input);
    int check = check_operator(res, &sign_st);
    if (check == 1) {
      result = get_operation(&digit_st, &sign_st);
      printf("%f\n", result);
      push_digit(&digit_st, result);
    }
    distribution_res(res, &digit_st, &sign_st);
    input = input + strlen(res);
    char sign = peek_sign(&sign_st);
    if (sign == '=') {
      pop_sign(&sign_st);
      result_main = get_operation(&digit_st, &sign_st);
    }
  }
  printStack_digit(&digit_st);
  printStack_sign(&sign_st);
  return result_main;
}
