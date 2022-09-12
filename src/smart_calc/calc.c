#include "s21_calc.h"

// int main(void) {
//   Stack_sign sign_st;
//   Stack_digit digit_st;

//  char* input = "2^3^2+34/2+s1+2)";
//  char* polish_notation = create_polish_notation(input, sign_st);
//  printf("polish_notation: %s\n", polish_notation);
//  double output = create_output(polish_notation, sign_st, digit_st);
//  printf("output: %.7f\n", output);
//  free(polish_notation);
//  return 0;
// }

char* create_polish_notation(char* input, Stack_sign sign_st) {
  char* pol_notation = calloc(255, sizeof(char));
  char minus;
  createEmptyStack_sign(&sign_st);
  if (input[0] == '-') {
    minus = input[0];
    input = input + 1;
  }
  for (int i = strlen(input); i >= 0; i--) {
    if (strlen(input) == 0) {
      break;
    }
    char* lexem = create_lexem(input);
    // if (minus) {
    //   memmove(lexem + 1, lexem, strlen(lexem));
    //   lexem[0] = '-';
    // }
    input = input + strlen(lexem);
    distribution_lexem(lexem, &sign_st, pol_notation);
    free(lexem);
  }
  while (!isempty_sign(&sign_st)) {
    char sign_in_stack = peek_sign(&sign_st);
    char array_sign_in_stack[3] = {sign_in_stack, ' ', '\0'};
    strcat(pol_notation, array_sign_in_stack);
    pop_sign(&sign_st);
  }
  return pol_notation;
}

double create_output(char* pol_notation, Stack_sign sign_st,
                     Stack_digit digit_st) {
  double output = 0.2;
  createEmptyStack_digit(&digit_st);
  createEmptyStack_sign(&sign_st);
  for (int i = strlen(pol_notation); i > 0; i--) {
    if (strlen(pol_notation) == 0) {
      break;
    }
    char* lexem = create_lexem(pol_notation);
    parsing_pol_notation(lexem, &sign_st, &digit_st);
    pol_notation = pol_notation + strlen(lexem);
    free(lexem);
  }
  output = pop_digit(&digit_st);
  return output;
}
