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

char pop_sign(Stack_sign *stack) {
  if (isempty_sign(stack)) {
    // printf("STACK EMPTY");
  } else {
    stack->count--;
    return stack->data[stack->top--];
  }
  // stack->top--;
}

char peek_sign(Stack_sign *stack) {
  if (stack->top <= 0) {
    printf("STACK SIGN IS EMPTY\n");
  }
  return stack->data[stack->top];
}
void printStack_sign(Stack_sign *stack) {
  printf("Stack: ");
  for (int i = 0; i < stack->count; i++) {
    printf("%c ", stack->data[i]);
  }
  printf("\n");
}