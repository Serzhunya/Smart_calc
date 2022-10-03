#include "s21_calc.h"

void createEmptyStack_digit(Stack_digit *stack) {
  stack->top = -1;
  stack->count = 0;
}

int isfull_digit(Stack_digit *stack) {
  if (stack->top == STACK_MAX_SIZE - 1)
    return 1;
  else
    return 0;
}

int isempty_digit(Stack_digit *stack) {
  if (stack->top == -1)
    return 1;
  else
    return 0;
}

void push_digit(Stack_digit *stack, double newitem) {
  if (isfull_digit(stack)) {
    printf("STACK FULL");
    exit(STACK_OVERFLOW);
  } else {
    stack->top++;
    stack->data[stack->top] = newitem;
  }
  stack->count++;
}

double pop_digit(Stack_digit *stack) {
  if (isempty_digit(stack)) {
    exit(STACK_UNDERFLOW);
  }
  stack->count--;
  return stack->data[stack->top--];
}

double peek_digit(Stack_digit *stack) {
  if (stack->top <= 0) {
    exit(STACK_UNDERFLOW);
  }
  return stack->data[stack->top - 1];
}
void printStack_digit(Stack_digit *stack) {
  printf("Stack_digit: ");
  for (int i = 0; i < stack->count; i++) {
    printf("%f ", stack->data[i]);
  }
  printf("\n");
}
