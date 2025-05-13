#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

int stack[SIZE];
int top = -1;

void push(int value)
{
  if (top == SIZE - 1)
  {
    printf("Stack Overflow\n");
    return;
  }
  top++;
  stack[top] = value;
  printf("%d pushed to stack\n", value);
}

int pop()
{
  if (top == -1)
  {
    printf("Stack Underflow\n");
    return -1;
  }
  int val = stack[top--];
  printf("%d popped from stack\n", val);
  return val;
}

void display()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack from top to bottom: ");
  for (int i = top; i >= 0; i--)
  {
    printf("%d ", stack[i]);
  }
  printf("\n");
}

int peek()
{
  if (top == -1)
  {
    printf("Stack is empty\n");
    return -1;
  }
  return stack[top];
}

int main()
{
  int ch, val;

  while (1)
  {
    printf("\n--- Stack Menu ---\n");
    printf("1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
      printf("Enter value to push: ");
      scanf("%d", &val);
      push(val);
      break;
    case 2:
      pop();
      break;
    case 3:
      printf("Top element is: %d\n", peek());
      break;
    case 4:
      display();
      break;
    case 5:
      printf("Exiting...\n");
      exit(0);
    default:
      printf("Invalid choice. Try again.\n");
    }
  }

  return 0;
}
