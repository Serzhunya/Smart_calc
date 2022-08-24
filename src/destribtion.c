#include "s21_calc.h"

int distribution_res(char* res, Stack_digit* digit_st, Stack_sign* sign_st) {
  int err = 0;
  if (*res >= 48 && *res <= 57) {
    double num = atof(res);
    printf("num:%f\n", num);
    push_digit(digit_st, num);
  } else {
    // char sign = *res;
    char sign = res[0];
    push_sign(sign_st, sign);
    printf("sign:%c\n", sign);
  }
  return err;
}
