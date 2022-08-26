#include "s21_calc.h"

int main(void) {
  Stack_digit digit_st;
  Stack_sign sign_st;
  char* input = "12+(9+6+10-1)/2=";
  double result_main = create_calc(input, digit_st, sign_st);
  printf("result_main: %f\n", result_main);
  return 0;
}

double create_calc(char* input, Stack_digit digit_st, Stack_sign sign_st) {
  double result_main = 0.0;
  createEmptyStack_digit(&digit_st);
  createEmptyStack_sign(&sign_st);
  int open_brace = 0;
  double result;
  for (int i = strlen(input); i > 0; i--) {
    if (strlen(input) == 0) {  // int str_length = strlen(input);
      break;
    }
    printf("\n");
    char* res = create_lexem(input);
    int check = check_operator(res, &sign_st);
    // printf("open_brace%d", open_brace);
    // printf("check%d", check);
    if (check == 1) {
      if (open_brace != 1) {
        result = get_operation(&digit_st, &sign_st);
        push_digit(&digit_st, result);
      } else {
        open_brace++;
      }
    } else if (check == 2) {
      result = get_operation(&digit_st, &sign_st);
      push_digit(&digit_st, result);
      pop_sign(&sign_st);
      open_brace = 0;
    } else if (check == 3) {
      open_brace = 1;
    }
    distribution_res(res, &digit_st, &sign_st);
    input = input + strlen(res);
    if (!(*res >= 48 && *res <= 57)) {
      if (peek_sign(&sign_st) == '=' && isempty_digit(&digit_st)) {
        pop_sign(&sign_st);
        result_main = get_operation(&digit_st, &sign_st);
      } else if (peek_sign(&sign_st) == '=' && !isempty_digit(&digit_st)) {
        pop_sign(&sign_st);
        result = get_operation(&digit_st, &sign_st);
        result_main = result;
      }
    }
  }
  printStack_digit(&digit_st);
  printStack_sign(&sign_st);
  return result_main;
}
