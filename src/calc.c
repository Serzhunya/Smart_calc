#include "s21_calc.h"

int main(void) {
  Stack_sign sign_st;
  Stack_digit digit_st;
  char* input = "1.2*3.5+2/2+1";
  char* polish_notation = create_polish_notation(input, sign_st);
  printf("polish_notation:%s\n", polish_notation);
  create_output(polish_notation, &sign_st, &digit_st);
  free(polish_notation);
  return 0;
}

char* create_polish_notation(char* input, Stack_sign sign_st) {
  char* pol_notation = NULL;
  pol_notation = calloc(255, sizeof(char));
  createEmptyStack_sign(&sign_st);

  for (int i = strlen(input); i >= 0; i--) {
    if (strlen(input) == 0) {
      break;
    }

    char* lexem = create_lexem(input);  // получение лексемы
    input = input + strlen(lexem);
    distribution_lexem(lexem, &sign_st,
                       pol_notation);  // распределение лексемы
                                       // printf("зашло:%s\n", lexem);
    printf("lexem:%s\n", lexem);
    free(lexem);
  }

  while (!isempty_sign(&sign_st)) {
    char sign_in_stack = peek_sign(&sign_st);
    char array_sign_in_stack[2] = {sign_in_stack, '\0'};
    strcat(pol_notation, array_sign_in_stack);
    pop_sign(&sign_st);
  }
  printStack_sign(&sign_st);
  return (char*)pol_notation;
}

char* create_output(char* pol_notation, Stack_sign* sign_st,
                    Stack_digit* digit_st) {
  char* output = calloc(255, sizeof(char));
  for (int i = strlen(output); i > 0; i--) {
    if (strlen(output) == 0) {
      break;
    }
    char* lexem = create_lexem(output);
    output = output + strlen(lexem);
    /*
    распределяет в стэк диджитов либо в стэк сайнов
    1. если встретит первый сайн, берет из стэка диджитов два числа и кладет
    результат в стэк диджитов
    2. получает число в стэке диджитов это и будет ответ
    */
    output = parsing_pol_notation(lexem, sign_st, digit_st);
    free(lexem);
  }
  return output;
}
