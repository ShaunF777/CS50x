#include <cs50.h>
#include <stdio.h>

int ARRAY[] = {72, 73, 33}; // syntax to make global arrays

int main(void)
{
//    int score1 = 72;
//    int score2 = 72;
//    int score3 = 33;

//    printf("Average: %f\n", (score1 + score2 + score3) / 3.0 ); changing 3 to 3.0 promotes float return
// other way of doing
    cont int N = 3; // always capitolise constants to draw attention
    int scores[N];
    for (int i = 0; i < N; i++)
    {
        scores[i] = get_int("Score: ");
    }
    printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) / (float) N); // (float) typecast used to convert N to float
}


