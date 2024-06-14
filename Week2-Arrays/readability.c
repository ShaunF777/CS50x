#include <cs50.h>
#include <ctype.h> // word character id
#include <math.h>  // more complex calcs like ceil, floor, log2, pow, sqrt, round
#include <stdio.h>
#include <string.h> // string

int nletters(string sent);
int nwords(string sent);
int nsent(string sent);
// use Colman-Liau Index to calculate readability index = 0.0588 * L - 0.296 * S - 15.8
// where L = ave n letters / 100 words , S = ave n sentences / 100 words
int main(void)
{
    string sentence = get_string("Text: ");
    float nl = nletters(sentence);
    // printf("Number of letters in sentence: %f \n", nl);
    float nw = nwords(sentence);
    // printf("Number of words in sentence: %f \n", nw);
    float ns = nsent(sentence);
    // printf("Number of sentences in sentence: %f \n", ns);

    // workout L = ave nletters / 100 words
    float l = nl / (nw / 100);
    // printf("L = ave nletters / 100 words: %f \n", l);
    //  workout s = ave nsentences /100 words
    float s = ns / (nw / 100);
    // printf("S = ave nsentences / 100 words: %f \n", s);
    //  work out Coleman-Liau index
    float index = 0.0588 * l - 0.296 * s - 15.8;
    int rindex = round(index);
    if (rindex > 0 && rindex < 16)
    {
        printf("Grade %i\n", rindex);
    }
    else if (rindex < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (rindex > 15)
    {
        printf("Grade 16+\n");
    }
}

// count n of letters in sentence
int nletters(string sent)
{
    int count = 0;
    for (int i = 0, length = strlen(sent); i < length; i++)
    {
        if (isalpha(sent[i]))
        {
            count++;
        }
    }
    return count;
}

// count n of words in sentence
int nwords(string sent)
{
    int count = 1;
    for (int i = 0, length = strlen(sent); i < length; i++)
    {
        if (isblank(sent[i]))
        {
            count++;
        }
    }
    return count;
}

// count n of sentences in phrase
int nsent(string sent)
{
    int count = 0;
    for (int i = 0, length = strlen(sent); i < length; i++)
    {
        if (sent[i] == '.' || sent[i] == '!' || sent[i] == '?')
        {
            count++;
        }
    }
    return count;
}
