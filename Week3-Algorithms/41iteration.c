#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height); // assume theres a function that will draw a pyramid
}

void draw(int n)
{
    for (int i = 0; i < n; i++) // outer loop for rows, n times starting at 0
    // n = height, this will iterate over every row top to bottom
    {
        for (int j = 0; j < i+ 1; j++) // inner loop for columns
        // when i = 0 has to start with 1 #, then ##, then ###, ####
        {
            printf("#");
        }
        printf("\n");
    }
}
