#include <stdio.h>

int main(void) //printing 2d code blocks without doing it manualy like printf("####\n")
{
    const int n = 50;            //use constant n to allow easy manipulation of output, disallowing changes further down the line
    for (int i = 0; i < n; i++) //runs the horizontal printer & goes to next line n times
    {
        for (int j = 0; j < n; j++)//runs horizontal printer n time
        {
            printf("#");
        }
        printf("\n");           //takes code to next line everytime till done
    }
}


