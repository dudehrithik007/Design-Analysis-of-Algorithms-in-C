#include <stdio.h>
#include <stdlib.h>

void insertionSort(int n, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Insertion Sort.\n\n");

    printf("\nEnter the size of the list to be sorted: ");
    int n;
    do // Input validation for variable 'n'.
    {
        scanf("%d", &n);
        if(n <= 0)
            printf("\nInvalid entry. Enter again: ");
    } while (n <= 0);

    int* ar = (int*) calloc(n, sizeof(int)); // Program is based on int values due to declaring the array as int. // Dynamic array declaration and initialisation using pointers.
    
    printf("\nEnter the elements in the list:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    printf("\nThe entered list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    insertionSort(n, ar);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void insertionSort(int n, int* ar)
{
    int j, key;
    for(int i = 1; i < n; i++) // Starting from 1 indicates that the 0th element in the array is itself sorted and we've to put elements from the remaining unsorted list into the sorted list (at the correct position) starting from the sorted list of size 1 containing the 0th element. In each iteration of this for loop, one element from the unsorted list is inserted into the sorted list at the correct position.
    {
        key = ar[i]; // Current element to be inserted in the sorted list. It is stored in a variable 'key' as we might later in the while loop update the element at the ith position. And then the then ith element which is in key is used to put the then ith element in the correct position in the sorted list.
        j = i - 1; // j is the rightmost position in the sorted array from which we start comparing in the sorted list and we move from right to left while comparing. This is done because in any order the list is being sorted, the sorted list's elements are larger/smaller than all of its left elements amd smaller/larger than all of its right elements in case of descending/ascending order. Also, we move left to right in the unsorted list while comparing. The leftmost element in the unsorted list is the next element to the rightmost element in the sorted list.
        while(j > -1 && key < ar[j]) // This loop finds the correct position of the ith element in the sorted list where it'll be inserted by the statement just after the completion of this. The first condition in the while loop indicates out of bounds condition of the array. After j-- in the last iteration we may reach there and exit the loop and at the 0th position the key element will be inserted in that case.
        { // If we use the opposite sign in the above while condition, we'll be finding the descending order. Right now we're finding the ascending order.
            ar[j+1] = ar[j]; // This is done to shift the jth element one position to the right to make space for the key element. While doing this in the first iteration of this while loop, we overwrite the ith element due to which we stored it in a temporary variable 'key'.
            j--; // Moving left in the unsorted list one time in each iteration.
        }
        ar[j+1] = key; // If we don't enter the above while loop, then as j was i - 1, we insert the ith element which is key at j + 1 = ith position itself.
    } // In the last iteration of the while loop, jth position contains the element which is now less than the key element and therefore we exit the loop and at the next position to j insert the key element which is now at the correct position in the sorted list.

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);
}