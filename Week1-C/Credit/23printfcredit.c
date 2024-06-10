#include <cs50.h>
#include <stdio.h>

int clast, c2last, c3last, c4last, c5last, c6last, c7last, c8last, c9last, c10last, c11last, c12last, c13last;
int c14last, c15last, c16last;

void num(long n, int countn);
int totalevens(int countn);

int main(void)
{
    // Prompt user for card number input while testing for size validity
    long cardn;
    int countn = 0;
    do
    {
    cardn = get_long("Credit card number: ");
    // Count the number of digits
    long l = cardn;
    for (int i = 0; l != 0; i++)
        {

            countn = i+1;
            printf("l = %li\n" , l);
            printf("countn = %i\n" , countn);
            l = l / 10;
        }
    printf("Number of digits: %i\n" , countn);
    }
    while(countn < 9 || countn > 16);


    // get cardnumbers individualy into globals
    num(cardn, countn);

    // do additions for Luhn checksum
    int odds  = clast + c3last + c5last + c7last + c9last + c11last + c13last + c15last;
    printf("Total odd numbers = %i\n", odds);
    int sumcheck = (odds + totalevens(countn)) % 10;
    if (sumcheck == 0)
    {
        if (c13last == 4 && countn == 13)
        {
            printf("VISA\n");
        }
        else if (c16last == 4 && countn == 16)
        {
            printf("VISA\n");
        }
        else if (countn == 16 && c16last == 5)
        {
            if (c15last == 1 || c15last == 2 || c15last == 3 || c15last == 4 || c15last == 5)
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if (countn == 15 && c15last == 3)
        {
            if (c14last == 4 || c14last == 7)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("Checksum = %i ", sumcheck );
        printf("Checksum failed\n");
    }

}


void num(long n, int countn)
{
    long mod = 10;
    long dif = 1;
    if (countn > 12 && countn < 17)
    {
        clast = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf("Number from back: %i", clast);
        c2last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c2last);
        c3last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c3last);
        c4last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c4last);
        c5last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c5last);
        c6last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c6last);
        c7last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c7last);
        c8last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c8last);
        c9last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c9last);
        c10last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c10last);
        c11last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c11last);
        c12last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c12last);
        c13last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i", c13last);
    }
    if (countn > 13 && countn < 17)
    {
        c14last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i\n", c14last);
    }
    if (countn > 14 && countn < 17)
    {
        c15last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i\n", c15last);
    }
    if (countn > 15 && countn < 17)
    {
        c16last = n % mod / dif;
        mod *= 10;
        dif *= 10;
        printf(",%i\n", c16last);
    }

}

// function returns the total of even numbers per digit
int totalevens(int countn)
{
    int totaladd = 0;
    // Test if *2 will give a 2 digit number thats more than 9, and then * 2 all even numbers
    if ( c2last > 4 )
    {
        int a0 = (c2last * 2) % 100 / 10;
        int a1 = (c2last * 2) % 10;
        printf("%i", a0);
        printf(",%i", a1);
        totaladd = totaladd + a0 + a1;
    }
    else
    {
        int a = c2last * 2;
        printf("%i", a);
        totaladd = totaladd + a;
    }
    if ( c4last > 4 )
    {
        int b0 = (c4last * 2) % 100 / 10;
        int b1 = (c4last * 2) % 10;
        printf(",%i", b0);
        printf(",%i", b1);
        totaladd = totaladd + b0 + b1;
    }
    else
    {
        int b = c4last * 2;
        printf(",%i", b);
        totaladd = totaladd + b;
    }
    if ( c6last > 4 )
    {
        int c0 = (c6last * 2) % 100 / 10;
        int c1 = (c6last * 2) % 10;
        printf(",%i", c0);
        printf(",%i", c1);
        totaladd = totaladd + c0 + c1;
    }
    else
    {
        int c = c6last * 2;
        printf(",%i", c);
        totaladd = totaladd + c;
    }
    if ( c8last > 4 )
    {
        int d0 = (c8last * 2) % 100 / 10;
        int d1 = (c8last * 2) % 10;
        printf(",%i", d0);
        printf(",%i", d1);
        totaladd = totaladd + d0 + d1;
    }
    else
    {
        int d = c8last * 2;
        printf(",%i", d);
        totaladd = totaladd + d;
    }
    if ( c10last > 4 )
    {
        int e0 = (c10last * 2) % 100 / 10;
        int e1 = (c10last * 2) % 10;
        printf(",%i", e0);
        printf(",%i", e1);
        totaladd = totaladd + e0 + e1;
    }
    else
    {
        int e = c10last * 2;
        printf(",%i", e);
        totaladd = totaladd + e;
    }
    if ( c12last > 4 )
    {
        int f0 = (c12last * 2) % 100 / 10;
        int f1 = (c12last * 2) % 10;
        printf(",%i", f0);
        printf(",%i", f1);
        totaladd = totaladd + f0 + f1;
    }
    else
    {
        int f = c12last * 2;
        printf(",%i\n", f);
        totaladd = totaladd + f;
    }
    if (countn > 13 && countn < 17)
    {
        if ( c14last > 4 )
        {
            int g0 = (c14last * 2) % 100 / 10;
            int g1 = (c14last * 2) % 10;
            printf(",%i", g0);
            printf(",%i", g1);
            totaladd = totaladd + g0 + g1;
        }
        else
        {
            int g = c14last * 2;
            printf(",%i", g);
            totaladd = totaladd + g;
        }
    }
    if (countn == 16)
    {
        if ( c16last > 4 )
        {
            int h0 = (c16last * 2) % 100 / 10;
            int h1 = (c16last * 2) % 10;
            printf(",%i", h0);
            printf(",%i", h1);
            totaladd = totaladd + h0 + h1;
        }
        else
        {
            int h = c16last * 2;
            printf(",%i\n", h);
            totaladd = totaladd + h;
        }
    }
    printf("Total added evens= %i\n", totaladd);
    return totaladd;
}




