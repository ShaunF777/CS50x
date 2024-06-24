#include <cs50.h>
#include <stdio.h>

void draw(int n);

int main(void)
{
    int height = get_int("Height: ");
    draw(height); // assume theres a function that will draw a pyramid
}
// Loop's are used mainly for iteration, we are going for recursion now
void draw(int n)
{
    // to prevent error: all paths through this function will call itself(because n can actually become -2Billion befor it underflows)
    // make sure n never reaches -1, stop
    if (n <= 0) // so this is my base case or smallest case
    // like no lokkers left, or person not found in phonebook
    {
        return; //ends the execution of a function, and returns control to the calling function.
    }

    //what is pyramid of height 6?  Pyramid 6 = Pyramid 5+1
    //so if a pyramid of height n needs to be drawn, lets first draw pyramid of n-1
    draw(n -1) // 1stly this will print pyramid of n-1

    //how to draw one more row? A: Use only single iteration to print n
    for (int i = 0; i < n; i++) // 2ndly print one more row
    {
        printf("#");
    }
    printf("\n");

}
