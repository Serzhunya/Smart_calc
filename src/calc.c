#include "s21_calc.h"

int main(void) {
  Stack_digit digit_st;
  Stack_sign sign_st;

  createEmptyStack_digit(&digit_st);
  createEmptyStack_sign(&sign_st);
  char* input = "2+3";
  for (int i = strlen(input); i > 0; i--) {
    if (strlen(input) == 0) {
      break;
    }
    char* res = create_lexem(input);
    distribution_res(res, &digit_st, &sign_st);
    input = input + strlen(res);
  }
  printStack_digit(&digit_st);
  printStack_sign(&sign_st);
  return 0;
}
