#include <stdio.h>
#define SIZE 100

void enqueue();
int dequeue();
void show();
void clear();

int items[SIZE];
int backIndex = 0;
int frontIndex = 0;

int main()
{
  int option;
  short isRunning = 1;

  while (isRunning)
  {
    printf("[QUEUE App] Choose an operation:");
    printf("\n 1 - Enqueue");
    printf("\n 2 - Dequeue");
    printf("\n 3 - Display Queue");
    printf("\n 4 - Clear Queue");
    printf("\n 5 - Exit");
    printf("\n\nEnter operation number: ");
    scanf("%d", &option);

    switch (option)
    {
    case 1:
      enqueue();
      break;

    case 2:
      dequeue();
      break;

    case 3:
      show();
      break;

    case 4:
      clear();
      break;

    case 5:
      isRunning = 0;
      break;

    default:
      printf("\n\n** INVALID OPERATION **\n\n");
      break;
    }
  }

  return 0;
}

void enqueue()
{
  int newValue;

  if (backIndex == SIZE - 1)
  {
    printf("\n\n ** YOU CAN'T ADD MORE ITEMS ** \n\n");
    return;
  }

  printf("\n\nEnter a number to include: ");
  scanf("%d", &newValue);

  items[backIndex] = newValue;
  backIndex++;

  show();
}

int dequeue()
{
  int dequeuedValue;

  if (frontIndex == backIndex)
  {
    printf("\n\n ** QUEUE IS EMPTY ** \n\n");
    return 0;
  }

  dequeuedValue = items[frontIndex];
  printf("\n\nElement deleted from the Queue: %d\n\n", dequeuedValue);
  frontIndex++;

  show();

  return dequeuedValue;
}

void show()
{
  if (frontIndex == backIndex)
  {
    printf("\n\n ** QUEUE IS EMPTY ** \n\n");
    return;
  }

  printf("\n\n ** QUEUE VALUES ** \n\n");
  for (int i = frontIndex; i < backIndex; i++)
  {
    printf("%d ", items[i]);
  }

  printf("\n\n");
}

void clear()
{
  // clear memory
  for (int i = 0; i <= SIZE; i++)
  {
    items[i] = 0;
  }

  frontIndex = 0;
  backIndex = 0;

  show();
}