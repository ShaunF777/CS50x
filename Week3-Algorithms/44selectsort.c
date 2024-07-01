// from https://www.geeksforgeeks.org/selection-sort-algorithm-2/?ref=lbp

// C program for implementation of selection sort
#include <stdio.h>

void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void printArray(int arr[], int size);

// Driver program to test above functions
int main()
{
    int arr[] = {64, 25, 12, 22, 11, 100, 85, 72, 54, 4, 39};
    int n = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr, n);
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
        //(min_idx, i)
void swap(int *xp, int *yp) /* '*xp' is the mem address min_idx. '*yp' is the mem address i.
Using the asterisks'*' , array pointers (index addresses or memory locations) are passed into the function rather than the actual values, but their respective
values can now be changed within each memory location*/
{
    int temp = *xp; // temp gets value inside min_idx address of arr == 4
    *xp = *yp;      // value in memory location min_idx = value in memory location i == 64
    *yp = temp;     // value in memory location i == 4
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)           //outer loop: i gets the first index address '0', then goes to next '1', then '2'...
    {
        // Find the minimum element in unsorted array
        min_idx = i;                    //min_idx gets the first index address '0', but check what happens inside the inner loop
        for (j = i+1; j < n; j++)       //j gets the next index address, and will stay i+1 for every iteration
            if (arr[j] < arr[min_idx])  //check actual value in idx[0] comparing to value in idx[1]
            min_idx = j;                //min_idx now gets the smallest value's index address

        // Swap the found minimum element with the first element if smaller value was found
        if(min_idx != i)                //min_idx address not same as index address i
            swap(&arr[min_idx], &arr[i]);
            /*In the statement swap(&arr[min_idx], &arr[i]);, the '&' operator is used to pass the index addresses of the elements in
            the 'arr' array to the 'swap' function. This means that the function 'swap' is expecting pointers '*' to the elements in the array,
            rather than the actual values. Now it can directly access and modify the values of the variables that the pointers are pointing to,
            rather than working with copies of the values.*/
    }
}

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/*Count elements in an array:
In C and C++ programming, the sizeof operator is used to determine the size of a variable or a type in bytes.
When sizeof(arr) is used, it returns the total size of the array (arr) in bytes.
This includes the size of all elements in the array, as well as any padding that might be necessary for memory alignment purposes. The result of sizeof(arr) is typically
used in scenarios where the size of an array needs to be calculated at compile time or when working with memory allocation and manipulation.

The line "int n = sizeof(arr)/sizeof(arr[0]);" in a C or C++ program calculates the number of elements in the array "arr".
It accomplishes this by dividing the total size of the array in bytes (obtained by using "sizeof(arr)") by the size of
a single element in the array (obtained by using "sizeof(arr[0])").
The result is the number of elements in the array, which is then stored in the variable "n" as an integer.
This is a common technique used to determine the size of an array at runtime in C and C++ programming.*/

/*Using the & operator:
In the statement swap(&arr[min_idx], &arr[i]);, the & operator is used to pass the addresses of the elements in the arr array to the swap function.
This means that the function swap is expecting pointers to the elements in the array, rather than the actual values.

By using the & operator, you are passing the memory addresses of arr[min_idx] and arr[i] to the swap function.
This allows the swap function to modify the actual values of these elements in the array arr, rather than just working with copies of the values.
This is a common technique in C and C++ programming when you need to swap values in an array or when you want to pass variables by reference for modification within a function.*/

/* Using the asterisk'*' pointers:
In the function declaration void swap(int *xp, int *yp), the * operator is used to define pointer parameters.

When a function parameter is declared with an asterisk (*), it means that the function expects a pointer to a variable of the specified type.
In this case, int *xp and int *yp indicate that the swap function expects pointers to integer variables.

By using pointers, the function can directly access and modify the values of the variables that the pointers are pointing to, rather than working with copies of the values.
This is useful when you want a function to be able to modify variables that are passed to it as arguments,
as changes made to the variables through their pointers will persist outside the function.*/

/*Pointers are one of the most important and powerful features of the C programming language. They allow us to manipulate memory directly, which can be very useful
in many programming scenarios. In C, a pointer is simply a variable that holds a memory address.*/
