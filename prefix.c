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
    return 'L';     // Left-associative
}

// Function to reverse a string
void reverse(char *exp)
{
    int n = strlen(exp);
    for (int i = 0; i < n / 2; i++)
    {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
}

// Function to swap '(' and ')' in expression
void swapParens(char *exp)
{
    for (int i = 0; exp[i]; i++)
    {
        if (exp[i] == '(')
            exp[i] = ')';
        else if (exp[i] == ')')
            exp[i] = '(';
    }
}

void infixToPrefix(char *exp)
{
    int len = strlen(exp);
    char result[len + 1];
    char stack[len];
    int j = 0;
    int top = -1;

    // Step 1: Reverse the expression
    reverse(exp);

    // Step 2: Swap ( and )
    swapParens(exp);

    // Step 3: Infix to Postfix (on reversed expression)
    for (int i = 0; i < len; i++)
    {
        char c = exp[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
        {
            result[j++] = c;
        }
        else if (c == '(')
        {
            stack[++top] = c;
        }
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                result[j++] = stack[top--];
            }
            if (top != -1 && stack[top] == '(')
                top--;
        }
        else
        {
            while (top != -1 && prec(stack[top]) > prec(c))
            {
                result[j++] = stack[top--];
            }
            while (top != -1 && prec(stack[top]) == prec(c) && assoc(c) == 'L')
            {
                result[j++] = stack[top--];
            }
            stack[++top] = c;
        }
    }

    while (top != -1)
    {
        result[j++] = stack[top--];
    }

    result[j] = '\0';

    // Step 4: Reverse postfix result to get prefix
    reverse(result);

    printf("Prefix: %s\n", result);
}

int main()
{
    char exp[100];
    printf("Enter infix expression: ");
    scanf("%s", exp);

    infixToPrefix(exp);
    return 0;
}
