#include "s21_calc.h"

int validation(char *input_str) {
  int code = 0;
  int count_opened_braces = 0;
  int count_closed_braces = 0;
  if (input_str[0] == '*' || input_str[0] == '/' || input_str[0] == '^' ||
      input_str[0] == '.' || input_str[0] == ')') {
    code = 1;
  }
  if (input_str[strlen(input_str) - 1] == '*' ||
      input_str[strlen(input_str) - 1] == '/' ||
      input_str[strlen(input_str) - 1] == '^' ||
      input_str[strlen(input_str) - 1] == '.' ||
      input_str[strlen(input_str) - 1] == '(' ||
      input_str[strlen(input_str) - 1] == '+' ||
      input_str[strlen(input_str) - 1] == '-') {
    code = 1;
  }
  for (int i = strlen(input_str); i >= 0; i--) {
    if (strlen(input_str) == 0) {
      break;
    }
    if (strchr(input_str, 40)) {
      count_opened_braces++;
    }
    if (strchr(input_str, 41)) {
      count_closed_braces++;
    }
    if (count_opened_braces != count_closed_braces) {
      code = 1;
    }
    int index_1 = strcspn(input_str, "+-*/^");
    int index_2 = strcspn(input_str, "0123456789");
    int index_3 = strcspn(input_str, ".");
    int index_4 = strcspn(input_str, ")");
    int index_5 = strcspn(input_str, "(");
    char char_valid_1 = input_str[index_1 + 1];
    char char_valid_2 = input_str[index_2 + 1];
    char char_valid_3 = input_str[index_3 + 1];
    char char_valid_4 = input_str[index_4 + 1];
    char char_valid_5 = input_str[index_5 + 1];
    if (char_valid_1 == '-' || char_valid_1 == '+' || char_valid_1 == '*' ||
        char_valid_1 == '/' || char_valid_1 == '^' || char_valid_1 == '.' ||
        char_valid_1 == ')') {
      code = 1;
    }
    if (char_valid_2 == 'c' || char_valid_2 == 's' || char_valid_2 == 't' ||
        char_valid_2 == 'a' || char_valid_2 == '(' || char_valid_2 == 'l') {
      code = 1;
    }
    if (char_valid_3 == 'c' || char_valid_3 == 's' || char_valid_3 == 't' ||
        char_valid_3 == 'a' || char_valid_3 == '(' || char_valid_3 == ')' ||
        char_valid_3 == '+' || char_valid_3 == '-' || char_valid_3 == 'l' ||
        char_valid_3 == '*' || char_valid_3 == '/' || char_valid_3 == '^') {
      code = 1;
    }
    if (char_valid_4 == 'c' || char_valid_4 == 's' || char_valid_4 == 't' ||
        char_valid_4 == 'a' || char_valid_4 == 'l' || char_valid_4 == '(' ||
        char_valid_4 == '1' || char_valid_4 == '2' || char_valid_4 == '3' ||
        char_valid_4 == '4' || char_valid_4 == '5' || char_valid_4 == '6' ||
        char_valid_4 == '7' || char_valid_4 == '8' || char_valid_4 == '9' ||
        char_valid_4 == '0' || char_valid_4 == '.') {
      code = 1;
    }
    if (char_valid_5 == ')' || char_valid_5 == '.' || char_valid_5 == '+' ||
        char_valid_5 == '*' || char_valid_5 == '/' || char_valid_5 == '^') {
      code = 1;
    }
    input_str = input_str + index_1 + 1;
    // input_str++;
  }
  return code;
}
