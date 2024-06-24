// Week3-Section excersize
// The factorial seing what makes up a number like 5 or a pyramid hight 5

#include <cs50.h>
#include <stdio.h>

int factorial(int n);

int main(void)
{
    //Get positive value for n
    int n;
    do
    {
        n = get_int("n: ");
    }
    while (n < 0);

    // Print factorial
    printf("%i\n", factorial(n));
}

int factorial(int n)
{
    // First code the cenario that we know the answer to
    if (n == 1)                                 // Base case
    {
        return 1; // return ends the function factorial
    }
    // add recursive call going down -1 everytime till 1
    // if n = 4, calc 4 * factorial(3)
    return n * factorial(n - 1);                // Recursive case
    // 4! = 4 * 3!, thus 4! = 4 * 3 * 2 * 1
}
