#include "s21_calc.h"

int validation(char* input_str) {
  int code = 0;
  for (int i = strlen(input_str); i >= 0; i--) {
    if (strlen(input_str) == 0) {
      break;
    }
    int index_1 = strcspn(input_str, "+-*/^");
    char char_valid_1 = input_str[index_1 + 1];
    if (char_valid_1 == '-' || char_valid_1 == '+' || char_valid_1 == '*' ||
        char_valid_1 == '/' || char_valid_1 == '^') {
      code = 1;
    }
    // char* lexem = create_lexem(input);
    // input = input + strlen(lexem);
  }
  //   int index_1 = strcspn(input_str, "+-*/^");
  //   char char_valid_1 = input_str[index_1 + 1];
  //   if (char_valid_1 == '-' || char_valid_1 == '+' || char_valid_1 == '*' ||
  //       char_valid_1 == '/' || char_valid_1 == '^') {
  //     code = 1;
  //   }
  //   input = input + strlen(lexem);
  return code;
}