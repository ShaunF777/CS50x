#include <stdio.h>

void meow(void); //decraring meow function to be used in main

int main(void) //return type int, name of the function main, argumnet /return value void
{
   for (int i = 0; i < 3; i++)
   {
        meow(); //but i need this meow function to exist somehwere else so i can call it from anywhere
   }
}

void meow(void) //the function prototype has no return value or argument, hence void
{
    printf("meow\n");
}
