#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stck
{
  /* data */ int top;
  unsigned capa;
  int *arr;
};
struct stck *createStack(unsigned capa)
{
  struct stck *stack = (struct stck *)malloc(sizeof(struct stck));
  stack->top = -1;
  stack->capa = capa;
  stack->arr = (int *)malloc(stack->capa * sizeof(int));
  return stack;
}
int isFull(struct Stck *stack)
{
  return stack->top == stack->capacity - 1;
}
