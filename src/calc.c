#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* create_lexem(char* input) {
  char* sign = "+-*/()^";
  int index = strcspn(input, sign);
  char* lexem = calloc(1, sizeof(strlen(input + index)));
  if (index == 0) {
    lexem[index] = input[index];
  } else {
    for (int i = 0; i < index; i++) {
      lexem[i] = input[i];
    }
  }
  return lexem;
}
int main(void) {
  char* input = "2222+(3.345-2.2)+3423423424";
  char* buffer = calloc(1, sizeof(strlen(input)));
  for (int i = 0; i <= strlen(input) + 1; i++) {
    char* res = create_lexem(input);
    int count = 0;
    printf("%s\n", res);
    //функция распределения res либо в стэк либо в аутпут
    input = input + strlen(res);
    free(res);
  }
  return 0;
}

// int create_buffer_digit(char* input, char* buffer) {
//   int res = 0;
//   int count = 0;
//   // int count_sign = 0;
//   // char* stak = calloc(1, sizeof(200));
//   double num = 0.0;
//   for (int i = 0; i <= strlen(input); i++) {
//     num = 0.0;
//     if ((input[i] >= 48 && input[i] <= 57) || input[i] == 46) {
//       buffer[count] = input[i];
//       count++;
//     }
//     // buffer[count] = '\0';
//   }
//   num = atof(buffer);
//   printf("double:%f\n", num);
//   count = 0;
//   return res;
// }

// int main(void) {
//   char* input = "2222+3*2.2/35 + 2222";
//   char* buffer_digit = calloc(1, sizeof(255));
//   create_buffer_digit(input, buffer_digit);
//   return 0;
// }