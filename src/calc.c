// #include "s21_calc.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_buffer(char* input, char* buffer[]) {
  int res = 0;
  char* sign = "+-*/()^m";
  for (int i = 0; i < strlen(input); i++) {
    if(*input >= 48 && *input <= 57 && *input == 46) {
      buffer[i] = input;
    }
  }
  return res;
}

int main(void) {

  char* input = "2222+3+2.2";
  char* buffer[255];

  create_buffer(input, buffer);

  // for (int i = 0; i < strlen(*buffer); i++) {
  printf("%s", buffer[0]);
  // }
  return 0;
}