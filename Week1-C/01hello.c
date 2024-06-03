#include <cs50.h>
#include <stdio.h>

int main(void)
{
    string answer = get_string("What's your name? "); //get_string saves the return value
    printf("hello, %s\n", answer); 
}

