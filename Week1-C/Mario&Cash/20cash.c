#include <cs50.h>
#include <stdio.h>

int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Prompt the user for the change owed, in cents
    int cents;
    do
    {
        cents = get_int("Change owed: ");
    }
    while (cents < 0);

    // Calculate qty quarters to give customer. Subtract quarters' value  from cents.
    int quarters = calculate_quarters(cents);
    cents = cents - (quarters * 25);

    // Calculate qty dimes to give customer. Subtract dimes' value  from cents.
    int dimes = calculate_dimes(cents);
    cents = cents - (dimes * 10);

    // Calculate qty nickels to give customer. Subtract nickels' value  from cents.
    int nickels = calculate_nickels(cents);
    cents = cents - (nickels * 5);

    // Calculate qty pennies to give customer. Subtract pennies' value  from cents.
    int pennies = calculate_pennies(cents);
    cents = cents - (pennies * 1);

    // Sum the number of quarters, dimes, nickels, and pennies used.
    int sum = quarters + dimes + nickels + pennies;
    // Print that sum.
    printf("%i\n", sum);

    // Testing outputs
    // printf("Cents Rem: %i  ", cents);
    // printf("Number of quarters: %i  ", quarters);
    // printf("Number of dimes: %i  ", dimes);
    // printf("Number of nickels: %i  ", nickels);
    // printf("Number of pennies: %i  \n", pennies);
}
int calculate_quarters(int cents)
{
    int quarters = 0;
    while (cents >= 25)
    {
        quarters++;
        cents = cents - 25;
    }
    // Retuns the int value of this local quarters into the main program
    // in the place where the function calculate_quarters(cents) was called
    return quarters;
}
int calculate_dimes(int cents)
{
    int dimes = 0;
    while (cents >= 10)
    {
        dimes++;
        cents = cents - 10;
    }
    return dimes;
}
int calculate_nickels(int cents)
{
    int nickels = 0;
    while (cents >= 5)
    {
        nickels++;
        cents = cents - 5;
    }
    return nickels;
}
int calculate_pennies(int cents)
{
    int pennies = 0;
    while (cents >= 1)
    {
        pennies++;
        cents = cents - 1;
    }
    return pennies;
}
