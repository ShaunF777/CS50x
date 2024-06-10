#include <cs50.h>
#include <stdio.h>
#define MAX 17

void printDigit(long N);

int main()
{
    long cardn;
    cardn = get_long("Credit card number: ");

    printDigit(cardn);
    printf("\n");
    return 0;

}
// Function to print the digit of
// number N
void printDigit(long N)
{
    // To store the digit of the number N
    int arr[MAX];
    int i = 0;
    int j, r;

    // Till N becomes 0
    for ( ; N != 0; i++)
    {
        // Extract the last digit of N
        r = N % 10;
        // Put the digit in arr[]
        arr[i] = r;
        // Update N to N/10 to extract
        // next last digit
        N = N / 10;
    }

    // Print the digit of N by traversing
    // arr[] reverse
    for (j = i - 1; j > -1; j--)
    {
        printf("%d ", arr[j]);
    }

}
