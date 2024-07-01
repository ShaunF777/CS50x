#include <stdio.h>

int minIndex(int a[], int i, int j);
void recurSelectionSort(int a[], int n, int index);

int main()
{
    int arr[] = {3, 1, 5, 2, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    // Calling function
    recurSelectionSort(arr, n, 0);

    // Printing sorted array
    for (int i = 0; i < n; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");
    return 0;
}

                    //index, n-1
int minIndex(int a[], int i, int j) // Return minimum index
{
    if (i == j)
        return i;

    int k = minIndex(a, i + 1, j); // Find minimum of remaining elements
    //if a[i] < a[k], then return i, else return k
    return (a[i] < a[k]) ? i : k; // Return minimum of current and remaining.
}

void recurSelectionSort(int a[], int n, int index) // Recursive selection sort. n is size of a[] and index is index of starting element.
{
    if (index == n) // Return when starting and size are the same
        return;

    int k = minIndex(a, index, n - 1); // calling minimum index function for the minimum index

    if (k != index) // Swapping when index and minimum index are not the same
    {
        int temp = a[k];
        a[k] = a[index];
        a[index] = temp;
    }
    recurSelectionSort(a, n, index + 1); // Recursively calling selection sort function
}

/* From https://users.cs.utah.edu/~germain/PPS/Topics/recursion.html#:~:text=Recursion%20can%20be%20equally%20well,computing%20a%20Factorial%2C%20and%20Sudoku.
 to practice recursion ive found this page to help with it

For example, we can define the operation "find your way home" as:

If you are at home, stop moving.

Take one step toward home.

"find your way home".

Here the solution to finding your way home is two steps (three steps).
First, we don't go home if we are already home.
Secondly, we do a very simple action that makes our situation simpler to solve.
Finally, we redo the entire algorithm.

OR

Finding the maximum value in a list of numbers.
The maximum value in a list is either the first number or the biggest of the remaining numbers.
Here is how we would write the pseudocode of the algorithm:
Function find_max( list )

            possible_max_1 = first value in list
            possible_max_2 = find_max ( rest of the list );

            if ( possible_max_1 > possible_max_2 )
              answer is possible_max_1
            else
              answer is possible_max_2
            end

          end
*/
