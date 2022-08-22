#include "s21_calc.h"

int create_lexem(char* input, char* array_lexem[300]) {
  int res = 0;
  char* sign = "+-*/()^m";
  char* s1 = input;
  int index;
  // нашли первый индекс вхождения
  for (int i = 0; i < strlen(s1); i++) {
    index = strcspn(s1, sign);  // получили индекс первого делиметра
    strncpy((unsigned char*)array_lexem, s1, index);  // в 0 индексе лежит 2222
    while (*s1 != '\0' && *s1 != *array_lexem) {
      s1++;
    }
  }

  //   printf("%d", index);
  return res;
}

int main(void) {
  char* input = "2222+3+2.2";
  char* array_lexem[255];

  create_lexem(input, array_lexem);
  //   for (int i = 0; i < 1; i++) {
  printf("%s", &array_lexem[0]);
  //   }
  return 0;
}