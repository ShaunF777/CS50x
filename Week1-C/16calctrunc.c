#include <cs50.h>
#include <stdio.h>
// demonstrating floating poit imprecision
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    float z = (float) x / (float) y;    //using typecasting to convert ints to float for the sake of z
                                        //even when using (double) where float is, the number will start vering off further because of finite memory
    printf("%.20f\n", z);                //.20 increases display size after the .
}
