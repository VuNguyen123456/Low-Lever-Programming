#include <stdio.h>
#include <stdlib.h>

int main()
{
  //int i, count
  int i,count;
  //int sum = 0;
  int sum;
  char Buffer[100];

  printf("Enter an integer -> ");
  fgets(Buffer, 100, stdin);
  //sscanf(Buffer, "%d", count);
  sscanf(Buffer, "%d", &count);
  //for (i == 0; i < count; i++);
  //for (i = 0; i < count; i++);
  //for (i = 0; i < count; i++)
  for (i = 0; i < count+1; i++)
  {
    //sum = count;
    sum += i;
    printf("i = %d sum = %d\n", i, sum); // Added for Debugging
  }

  printf("The sum of integers 0 to %d is: %d\n", count, sum);

  return 0;
}
