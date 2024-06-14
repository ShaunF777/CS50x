#include <cs50.h>
#include <stdio.h>

void set_array(int array[4]);
void set_int(int x);

int main(void)
{
    int a = 10;
    int b[4] = { 0, 1, 2, 3 };
    set_int(a);
    set_array(b);
    printf("%d %d\n", a, b[0]);
}

// arrays are passed by reference
void set_array(int array[4]) // THIS MEANS IT'LL PRINT FOR b[0] = 22
{
    array[0] = 22;
}

// other types are passed by value
void set_int(int x) // THIS MEANS IT'LL PRINT FOR a = 10
{
    x = 22;
}
