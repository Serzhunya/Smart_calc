#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int create_buffer_digit(char* input, char* buffer) {
  int res = 0;
  int count = 0;
  int count_sign = 0;
  char* stak = calloc(1, sizeof(200));
  for (int i = 0; i <= strlen(input); i++) {
    if ((input[i] >= 48 && input[i] <= 57) || input[i] == 46) {
      buffer[count++] = input[i];
    } else {
      buffer[count++] = ' ';
    }
  }
  for (int i = 0; i <= strlen(input); i++) {
    if ((input[i] >= 40 && input[i] <= 43) || input[i] == 45 ||
        input[i] == 45) {
      stak[count_sign++] = input[i];
    }
  }
  return res;
}

// int create_buffer_sign(char* input, char* buffer) {
//   int res = 0;
//   int count = 0;
//   for (int i = 0; i <= strlen(input); i++) {
//     if ((input[i] >= 48 && input[i] <= 57) || input[i] == 46) {
//       buffer[count++] = input[i];
//     } else {
//       buffer[count++] = ' ';
//     }
//   }
//   return res;
// }

int main(void) {
  char* input = "2222+3+(2.2+35)";
  char* buffer_digit = calloc(1, sizeof(255));
  create_buffer_digit(input, buffer_digit);
  printf("buffer:%s", buffer_digit);
  return 0;
}