#include <cs50.h>
#include <stdio.h>
#include <stdlib.h> //has the a-to-i string converter

void print_row(int spaces, int bricks);

// argc = number of program inputs/indexes at cli
// argv = array of strings being put into our program at cli
// at cli type "cowsay -f dragon "RAWR" "
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./mario number\n");
        return 1; // return 1 means something whent wrong
    }
    int height = atoi(argv[1]); // use atoi function to convert argv[1] to integer
    // segmentation faults ocur when looking too far in an array argv[1] assumes i have 2 arguments
    for (int i = 0; i < height; i++)
    {
        // Print row of bricks
        print_row(height - (i + 1), i + 1);
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

