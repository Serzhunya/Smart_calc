#include "s21_calc.h"

double calc(char* input) {
    double output = 0.0;
    Stack_sign sign_st;
    Stack_digit digit_st;
    char* input_change = create_input_change(input);  // меняется
    char* polish_notation = create_polish_notation(input_change, sign_st);  // создается польская нотация
    output = create_output(polish_notation, sign_st, digit_st);  // создается оутпут
    free(polish_notation);
    free(input_change);
    return output;
}

char* create_input_change(char* input) {
    int minus = 0;
    int minus_after_brace = 0;
    char* input_change = calloc(255, sizeof(char));
    for (size_t i = 0; i < strlen(input); i++) {
        if (input[i] == '-' && i == 0) {
            minus = 1;
        }
        if (input[i] == '(' && input[i + 1] == '-') {
            minus_after_brace = 1;
        }
        if (minus) {
            input_change[i] = '~';
        } else if (minus_after_brace) {
            input_change[i] = '(';
            input_change[i + 1] = '~';
            i++;
        } else {
            input_change[i] = input[i];
        }
        minus = 0;
        minus_after_brace = 0;
    }
    return input_change;
}

char* create_polish_notation(char* input_change, Stack_sign sign_st) {
    char* pol_notation = calloc(255, sizeof(char));
    createEmptyStack_sign(&sign_st);
    for (int i = strlen(input_change); i >= 0; i--) {
        if (strlen(input_change) == 0) {
            break;
        }
        char* lexem = create_lexem(input_change);
        distribution_lexem(lexem, &sign_st, pol_notation);
        input_change = input_change + strlen(lexem);
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
    double output = 0.0;
    createEmptyStack_digit(&digit_st);
    createEmptyStack_sign(&sign_st);
    for (int i = strlen(pol_notation); i >= 0; i--) {
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
