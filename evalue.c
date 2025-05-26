#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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
int isFull(struct stck *stack)
{
  return stack->top == stack->capa - 1;
}
int isEmpty(struct stck *stack)
{
  return stack->top == -1;
}
void push(struct stck *stack, int item)
{
  stack->arr[++stack->top] = item;
}

int pop(struct stck *stack)
{
  if (!isEmpty(stack))
    return stack->arr[stack->top--];
}

int evlaue(char *exp)
{
  struct stck *stack = createStack(strlen(exp));
  int i;

  for (i = 0; exp[i]; ++i)
  {
    if (isdigit(exp[i]))
      push(stack, exp[i] - '0');
    else
    {
      int val1 = pop(stack);
      int val2 = pop(stack);
      printf("\n%d%d", val1, val2);
      switch (exp[i])
      {
      case '/':
        push(stack, val2 / val1);
        break;
      case '*':
        push(stack, val2 * val1);
        break;
      case '+':
        push(stack, val2 + val1);
        break;
      case '-':
        push(stack, val2 - val1);
        break;
      }
    }
  }
  return pop(stack);
}

int main()
{
  char exp[100];
  printf("Enter postfix expression: ");
  scanf("%s", exp);

  printf("\n postfix:%d", evlaue(exp));
  return 0;
}