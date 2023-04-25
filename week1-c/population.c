#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size

    int n;
  do
  {
      n = get_int("Start size: ");
  }
  while (n<9);

    // TODO: Prompt for end size
    int i;
  do
  {
      i = get_int("End size: ");
  }

  while (i<n);

    // TODO: Calculate number of years until we reach threshold
    int z=0;
    while (n < i)
    {
      n = n + (n/3) - (n/4);
      z++;
    }
    // TODO: Print number of years
    printf("Years: %d\n", z);

}