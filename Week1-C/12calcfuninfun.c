#include <cs50.h>
#include <stdio.h>

int add(int a, int b);// copy of prototype declared
int main(void)
{
    int x = get_int("x: "); //Problem solved using sustitute var in add function
    int y = get_int("y: "); // x & y is only usable inside these curly braces, inside this scope

   // int z = add(x, y);        //in stead of x + y we are outsourcing the function and putting its anwer inside z
                                //but now we must fill the add functions arguments with our vars

    printf("%i\n", add(x, y)); //NOW use add funtion inside printf in stead of having to first declare a placeholder
}
// make reusable add function
int add(int a, int b)//this function has an int return value and declares a & b as int arguments as substitute placeholders for x & y calculations in main
{
    return a + b;   //other names can be used instead of a & b, but must then be used function and prototype declarations
}
