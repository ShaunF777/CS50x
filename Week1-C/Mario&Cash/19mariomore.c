#include <cs50.h>
#include <stdio.h>

void print_row(int spaces, int bricks);

int main(void)
{
    // Prompt the user for the pyramid's height
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n < 1);
    // Print a pyramid of that height
    for (int i = 0; i < n; i++)
    {
        // Print row of bricks
        print_row(n - (i + 1), i + 1);
        // runs print_row n times, n - (i + 1) & i + 1 are function argument
        // spaces value changes like 7,6,5,4,3,2,1 till the loop stops
        // bricks value changes like 1,2,3,4,5,6,7,8 till the loop stops
    }
}

void print_row(int spaces, int bricks)
{
    // loop prints 1 less than n times, then 1 less each time as
    // spaces arg decreases in main loop
    for (int j = 0; j < spaces; j++)
    {
        printf(" ");
    }
    // loop prints once, but now stops because j=1, then twice, but now stops because j=2,
    // then thrice, but now stops because j=3. this continues till main loop stops
    for (int k = 0; k < bricks; k++)
    {
        printf("#");
    }
    printf("\n");
}
