// Collatz conjunction steps calculator
#include <cs50.h>
#include <stdio.h>

int collatz(int n);
int steps = 0;

int main(void)
{
    int n = get_int("Test Collatz conjecture: ");

    printf("Collatz series:\n");

    printf("Total steps needed: %i", collatz(n));

    printf("\n");
    return 0;
}

int collatz(int n)
{
    if (n == 1)
    {
        return 0;
    }
    else if (n % 2 == 0) // if i devide n by 2, will there be no remainder?
    {
        printf("%i is even.", n);
        steps++;
        printf("Step %i\n", steps);
        return 1 + collatz(n/2);    //instead of printf("%i ", collatz(n/2));
    }

    else
    {
        printf("%i is odd.", n);
        steps++;
        printf("Step %i\n", steps);
        return 1 + collatz(n*3+1); //instead of print("%i ", collatz(n*3+1));
    }

    return 0;
}




