#include <stdio.h>
#include <stdlib.h>

void minFind(int n, int* ar);

void main()
{
    printf("\n\nProgram to find the min value in a list of values entered by the user.\n\n");

    printf("\nEnter the number of values to be entered: ");
    int n;
    do // Input validation for variable 'n'.
    {
        scanf("%d", &n);
        if(n <= 0)
            printf("\nInvalid entry. Pls enter again: ");
    } while (n <= 0);

    int* ar = (int*) calloc(n, sizeof(int)); // Program is based on int values due to declaring the array as int. // Dynamic array declaration and initialisation using pointers.
    
    printf("\nEnter the values:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    minFind(n, ar);

    printf("\n\nEnd of Program is reached.\n\n\n");
}

void minFind(int n, int* ar)
{
    int min = ar[0]; // Considering only one element at present in the list so it'll be the min element in that list.
    
    for(int i = 1; i < n; i++) // Iterating over each element in the list starting from the 2nd element thereby the logic: Increasing size of the list by 1 in each iteration in which the min element has been found after the completion of that iteration.
        if(ar[i] < min) // If current element is less than the minimum element assumed. (in the list till ith element)
            min = ar[i]; // Then the new minimum element is the current element. (in the list till ith element)
        
    printf("\nThe minimum element in the list is: %d", min); // After reaching the end of the loop above. (in the list till nth element)
}