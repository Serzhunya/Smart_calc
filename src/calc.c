#include "s21_calc.h"

int main(void) {
  Stack_sign sign_st;
  char* input = "1.2*(3.5+4-3.5*3)*10/(3+1+1)-20*2+4^3-5-2";
  double result_main = create_calc(input, sign_st);
  printf("result_main: %f\n", result_main);
  return 0;
}

double create_calc(char* input, Stack_sign sign_st) {
  double result_main = 0.0;
  char pol_notation[255] = {'\0'};
  createEmptyStack_sign(&sign_st);
  for (int i = strlen(input); i > 0; i--) {
    if (strlen(input) == 0) {
      break;
    }
    char* lexem = create_lexem(input);  // получение лексемы
    distribution_lexem(lexem, &sign_st,
                       pol_notation);  // распределение лексемы
    input = input + strlen(lexem);  // передвигается указатель
  }
  while (!isempty_sign(&sign_st)) {
    char sign_in_stack = peek_sign(&sign_st);
    char array_sign_in_stack[2] = {sign_in_stack, '\0'};
    strcat(pol_notation, array_sign_in_stack);
    pop_sign(&sign_st);
  }
  printf("pol_notation:%s\n", pol_notation);
  printStack_sign(&sign_st);

  return result_main;
}
