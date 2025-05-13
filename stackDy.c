#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int data;
  struct Node *Next;
};

struct Node *Top = NULL;

void push(int data)
{
  struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
  newNode->data = data;
  newNode->Next = Top;
  Top = newNode;
  printf("%d pushed to stack\n", data);
}

void pop()
{
  if (Top == NULL)
  {
    printf("Stack underflow\n");
    return;
  }
  struct Node *temp = Top;
  printf("%d popped from stack\n", Top->data);
  Top = Top->Next;
  free(temp);
}

void display()
{
  struct Node *temp = Top;
  if (Top == NULL)
  {
    printf("Stack is empty\n");
    return;
  }
  printf("Stack from top to bottom: ");
  while (temp != NULL)
  {
    printf("%d -> ", temp->data);
    temp = temp->Next;
  }
  printf("NULL\n");
}

int main()
{
  int choice, data;
  while (1)
  {
    printf("\n--- Stack Menu ---\n");
    printf("1. Push\n2. Pop\n3. Display\n4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
      printf("Enter value to push: ");
      scanf("%d", &data);
      push(data);
      break;
    case 2:
      pop();
      break;
    case 3:
      display();
      break;
    case 4:
      printf("Exiting program.\n");
      exit(0);
    default:
      printf("Invalid choice! Try again.\n");
    }
  }
  return 0;
}
