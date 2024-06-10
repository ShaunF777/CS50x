// Averages three numbers using an array, a constant, and a helper function

#include <cs50.h>
#include <stdio.h>

// Constant
const int N = 3; // declared a contant N = 3

// Prototype, 
float average(int length, int array[]); // introduce average function, will return a float, giving it the array and the length thereof

int main(void)
{
    // Get scores
    int scores[N];  // declaring var array scores, with N size
    for (int i = 0; i < N; i++) //iterating from i to N
    {
        scores[i] = get_int("Score: "); // asking as they get plugged into scores
    }

    // Print average
    printf("Average: %f\n", average(N, scores)); // print out the average, automatically by
    // calling av function, pass in array length and the array itself, hoping that it'll return float to printf
}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for (int i = 0; i < length; i++)
    {
        sum += array[i]; // sum  = sum + array[i];
    }
    return sum / (float) length;   //sum of N array entries / array length
}



