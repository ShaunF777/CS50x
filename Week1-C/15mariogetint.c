#include <stdio.h>
#include <cs50.h>

int main(void)                  //printing 2d code blocks without doing it manualy like printf("####\n")
{
    int n;                      //just to declare n for global scope
    do                          //Use do while for an initial and thereafter looped size request
    {
        n = get_int("Size: ");  //do while loop prompts user for input at least once, but again and again if incorrect
    }
    while (n < 1);

    for (int i = 0; i < n; i++) //runs the horizontal printer & goes to next line n times
    {
        for (int j = 0; j < n; j++)//runs horizontal printer n time
        {
            printf("#");
        }
        printf("\n");           //takes code to next line everytime till done
    }
}
