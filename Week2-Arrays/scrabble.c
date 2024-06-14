#include <cs50.h>
#include <ctype.h> // checks character types, and converts upper to lower vise versa
#include <stdio.h>
#include <string.h> // strlen function works from this header

// Points assigned to each letter of the alphabet
//              A  B  C  D  E  F  G  H  I  J  K  L  M  N  O  P  Q   R  S  T  U  V  W  X  Y  Z
int Points[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int calcscore(string word);

int main(void)
{
    // Prompt the user for two words
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Compute the score of each word
    int score1 = calcscore(word1);
    // printf("Score1 = %i\n", score1);
    int score2 = calcscore(word2);
    // printf("Score2 = %i\n", score2);

    // Print the winner
    if (score1 > score2)
    {
        printf("Player 1 wins!");
    }
    else if (score1 < score2)
    {
        printf("Player 2 wins!");
    }
    else if (score1 == score2)
    {
        printf("Tie!");
    }
    printf("\n");
}

int calcscore(string word)
{
    // keep track of score
    int score = 0;
    // calc score for each character
    for (int i = 0, length = strlen(word); i < length; i++)
    {
        if (isupper(word[i]))
        {
            // if char = U(int value of 85), points[20] i.e. 85 - 65 ,cause 'A's int value is 65
            score += Points[word[i] - 'A'];
        }
        else if (islower(word[i]))
        {
            // if char = z(int value of 122), points[20] i.e. 122 - 97 ,cause 'a's int value is 97
            score += Points[word[i] - 'a'];
        }
        // printf("%i ", score);
    }
    // printf("\n");
    return score;
}
