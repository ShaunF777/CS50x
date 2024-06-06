#include <cs50.h>
#include <stdio.h>

// void is a place holder for "nothing" i.e. main has an int return value
// void main(void) has not return(output) or arguments(inputs)
int main(void)
{
    // Arithmatic Operators
    int x, y;       // declare x and y variables of type integer
    x *= 5;         // easiest way to make x = x * 5
    y /= 3;         // easiest way to make y = y / 3
    x++;            // easiest way to increase x by 1
    y--;            // easiest way to decrease y by 1
    int a = 13 % 4  // modulo gives you 1 as remainder i.e. what's right of the comma
    int b = 12345678 % 10;           // modulo gives you 8
    int c = 12345678 % 20;           // if using random numbers, modulo gives you value of 0 to 19
    int d = (12345678 % 100) / 10;   // gives you 7, for int the decimal 8 will be truncated
    // Logical operators OR(||) is true if at least one operand is true
    // Logical operator AND(&&) is true only if all operands are true
    // Logical operator NOT(!) turns a TRUE statement into FALSE, vice versa
    // Relational Operators are like (x <= y) or (y >= x)

//Conditional Statements
int z;
if (boolean-expression) // Simple if then else conditional
    {
        z = x * 5;     // this runs if the bool expression is true
    }
    else
    {
        z = y / 3;      // else this runs if bool expression is false
    }

// Ternary conditional statments is an abbreviated version of 'if-then-else'
int z = (boolean-expression) ? x * 5 : y / 3;   // this does the exact same as the above code
// use ternary operator to shorten conditional code where curly brace actions are small


if (bool-expr1)         // if-else if-else chain all branches mutually exclusive
{ first-branch }        // can only run, one at a time if condition is true
else if (bool-expr2)    // this chain will stop if any bool-expr is true
{ second-branch }       // otherwise only the last else branch
else { third-branch }   // CANNOT RUN 'then' ACTIONS SIMULTANEOUSLY

if (bool-expr1)         // 'if-if' chain of non mutual exclusive branches
{ first-branch }        // program will run through each and CAN saticfy almost all
if (bool-expr2)         // almost like tick boxes, if ticked 'then' actions will start
{ second-brnach }
if (bool-expr3 )        // CAN RUN 'then' ACTIONS SIMULTANEOUSLY
{ third-branch }        // in this chain only the last 'then' and 'else' are mutualy exclusive
else { fourth-branch }  // 'else' only binds with the nearest 'if'

//switch conditional expression
int r = get_int();              // instead of relying on one true/false Bool expression
switch(r)                       // switch(r) checks the input number, if its 1 or 2 or 3
{                               // switch(r) permits enumeration of discrete cases
    case 1: printf("One!\n");   // if user typed in '1', then therminal prints 'One!'
            break;              // and then breaks or stops the statement
    case 2: printf("Two!\n");   // if non are true only 'default' action is taken 'Sorry!'
            break;
    case 3: printf("Three!\n");
            break;              // without the 'break;' between each case it'll run each
    default: printf("Sorry!\n");// concecutive action going further down the cases
}

int t = get_int();              // instead of relying on one true/false Bool expression
switch(t)                       // switch(t) checks the input number, if its 5 or 4 or 3 or 2
{                               // switch(t) permits enumeration of discrete cases
    case 5: printf("Five! ");
    case 4: printf("Four! ");  // if user typed in '4', then therminal prints:
    case 3: printf("Three! "); // 'Four! Three! Two! One! Party Time!
    case 2: printf("Two! ");
    case 1: printf("One! ");
    default: printf("Party Time!\n");
}


}
