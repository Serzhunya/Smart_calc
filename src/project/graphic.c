#include "s21_calc.h"

double create_graphic(char* input, Stack_sign sign_st, double x) {
    Stack_digit digit_st;
    double output;
    char* polish_notation = create_polish_notation(input, sign_st);
    output = create_output_xy(polish_notation, &sign_st, &digit_st, x);
    return output;
}


double create_output_xy(char* polish_notation, Stack_sign* sign_st, Stack_digit* digit_st, double x) {
    double output = 0.0;
    createEmptyStack_digit(digit_st);
    createEmptyStack_sign(sign_st);
    for (int i = strlen(polish_notation); i > 0; i--) {
        if (strlen(polish_notation) == 0) {
            break;
        }
        char* lexem = create_lexem(polish_notation);
        parsing_pol_notation_xy(lexem, sign_st, digit_st, x);
        polish_notation = polish_notation + strlen(lexem);
        free(lexem);
    }
    output = pop_digit(digit_st);
    return output;
}

void parsing_pol_notation_xy(char* lexem, Stack_sign* sign_st,
                          Stack_digit* digit_st, double x) {
  char sign_cur = *lexem;
  if (sign_cur >= 48 && sign_cur <= 57) {
    double num = atof(lexem);
    push_digit(digit_st, num);
  }
  if (sign_cur == 120) {
       push_digit(digit_st, x);
  }
  if (sign_cur == '-' || sign_cur == '+' || sign_cur == '/' ||
      sign_cur == '*' || sign_cur == '^' || sign_cur == 'm') {
    push_sign(sign_st, sign_cur);
    double result = get_operation(digit_st, sign_st);
    push_digit(digit_st, result);
  }
  if (sign_cur == 's' || sign_cur == 'c' || sign_cur == 't' ||  // sin cos tan
      sign_cur == 'a' || sign_cur == 'i' ||
      sign_cur == 'n' ||  // acos asin atan
      sign_cur == 'q' || sign_cur == 'l' || sign_cur == 'o') {  // sqrt ln log
    push_sign(sign_st, sign_cur);
    double result = get_operation_unary(digit_st, sign_st);
    push_digit(digit_st, result);
  }
}
