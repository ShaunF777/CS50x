#include <stdio.h>

void meow(int n); //decraring meow function to be used in main

int main(void) //return type int, name of the function main, argumnet /return value void
{
  // for (int i = 0; i < 3; i++) loop is now inside the meow function
    meow(10000); //only extraction is used now, but argument can now easily be adjusted to allow better loop control
}

//actual code for meow function
void meow(int n) //the function prototype has no return value BUT an argument now
{
    for(int i = 0; i < n; i++)
    {
            printf("meow\n");
    }
}
