// Section video - Doubling up
// Create an array of integers in which each integer is 2 time the value of the previouse integer
// The first element is 1.
// Print the array, integer by integer
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int size = get_int(" Enter size:"); // get user input for size
    int sequence[size];
    sequence[0] = 1;
    printf("%i\n", sequence[0]);

    // can be initialised with sequence index 0 at value 1 for (int i = 0, sequence[5]=1; i<s; i++)
    for (int i = 1; i<size; i++)
    {
        sequence[i] = sequence[i-1] * 2; // multiply whatever is in the index of array
    //  sequence[1] = sequence[0] wich has value 1 * 2, so now index gets the element 2 stored in it
        printf("%i\n", sequence[i]);
    }
}
