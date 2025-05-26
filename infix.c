#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int prec(char c)
{
  if (c == '^')
    return 3;
  else if (c == '*' || c == '/')
    return 2;
  else if (c == '+' || c == '-')
    return 1;
  else
    return -1;
}

char assoc(char c)
{
  if (c == '^')
    return 'R'; // Right-associative
  return 'L';   // Left-associative
}

void infixToPostfix(char *exp)
{
  int len = strlen(exp);
  char result[len + 1];
  char stack[len];
  int j = 0;
  int top = -1;

  for (int i = 0; i < len; i++)
  {
    char c = exp[i];

    // If operand, add to result
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
      result[j++] = c;
    }

    // If '(', push to stack
    else if (c == '(')
    {
      stack[++top] = c;
    }

    // If  the scanned charcter is an ') pop and add to the the ouptut string from the stack .until an '('is un counteer
    else if (c == ')')
    {
      while (top != -1 && stack[top] != '(')
      {
        result[j++] = stack[top--];
      }
      if (top != -1 && stack[top] == '(')
        top--; // Pop '('
    }

    // If operator
    else
    {
      while (top != -1 && prec(stack[top]) > prec(c) || prec(stack[top]) == prec(c) && assoc(c) == 'L')
      {
        result[j++] = stack[top--];
      }
      stack[++top] = c;
    }
  }

  // Pop remaining operators
  while (top != -1)
  {
    result[j++] = stack[top--];
  }

  result[j] = '\0';
  printf("Postfix: %s\n", result);
}

int main()
{
  char exp[100];
  printf("Enter infix expression: ");
  scanf("%s", exp);

  infixToPostfix(exp);
  return 0;
}