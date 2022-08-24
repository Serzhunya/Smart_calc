#include "s21_calc.h"

char* create_lexem(char* input) {
  char* sign = "+-*/()^";
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