#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");
    // cant use printf("x + y\n"); because we want the actual values
    printf("%i\n", x + y);  //print the value of an integer placeholder, use arithmatic opperators available for calculations(+,-,*,/,%)
                            //(% is a modulo calc & gives the remainder of a devision)
}

