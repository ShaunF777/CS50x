#include <cs50.h>
#include <stdio.h>
// test triangle lengths & print true
// lengths need to be +
// the sum of 2 lengths is always greater than the 3rd length, ie. h cannot be longer than a + o
bool valid_triangle(float x, float y, float z);

int main(void)
{
    float a = get_float("Adjacent side: ");
    float o = get_float("Opposite side: ");
    float h = get_float("Hypotenuse side: ");

    printf("triangle validity %s\n", valid_triangle(a,o,h) ? "true" : "false");
}

bool valid_triangle(float x, float y, float z)
{
    // check for all positive sides
    if (x <= 0 || y <= 0 || z <= 0)
    {
        return false;
    }
    // check that sum of any two sides greater than third
    if ((x + y <= z) || (x + z <= y) || (y + z <= x))
    {
        return false;
    }
    // if we passed both tests, we're good
    return true;
}
