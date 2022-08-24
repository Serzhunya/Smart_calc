#include "s21_calc.h"

// int count = 0;

void createEmptyStack_sign(Stack_sign *stack) {
  stack->top = -1;
  stack->count = 0;
}

int isfull_sign(Stack_sign *stack) {
  if (stack->top == STACK_MAX_SIZE - 1)
    return 1;
  else
    return 0;
}

int isempty_sign(Stack_sign *stack) {
  if (stack->top == -1)
    return 1;
  else
    return 0;
}

void push_sign(Stack_sign *stack, char newitem) {
  if (isfull_sign(stack)) {
    printf("STACK FULL");
  } else {
    stack->top++;
    stack->data[stack->top] = newitem;
  }
  stack->count++;
}

double pop_sign(Stack_sign *stack) {
  if (isempty_sign(stack)) {
    exit(STACK_UNDERFLOW);
  }
  stack->top--;
  stack->count--;
  return stack->data[stack->top];
}

double peek_sign(Stack_sign *stack) {
  if (stack->top <= 0) {
    exit(STACK_UNDERFLOW);
  }
  return stack->data[stack->top - 1];
}
void printStack_sign(Stack_sign *stack) {
  printf("Stack: ");
  for (int i = 0; i < stack->count; i++) {
    printf("%c ", stack->data[i]);
  }
  printf("\n");
}