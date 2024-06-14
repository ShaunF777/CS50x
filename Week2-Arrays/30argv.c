#include <cs50.h>
#include <stdio.h>

int main(int argc, string argv[]) // argc is the number of inputs the prog receives including program name
                                  // if typing ./mario 8, then argc = 2, because theres 2 arguments
                                  // also now argv has 2 strings inside, argv[0] = ./mario & argv[1] = 8
// the 1st element of argv is always found in argv[0] , the last always at argv[argc-1]

{
    //loop throught all the indexes in argv
    for (int i = 0; i < argc; i++)
    {
        printf("argv[%i] is %s\n", i, argv[i]);
    }
}
