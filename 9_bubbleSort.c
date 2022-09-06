#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int n, int* ar);
void swap(int i, int j, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Bubble Sort.\n\n");

    printf("\nEnter the size of the list to be sorted: ");
    int n;
    do // Input validation for variable 'n'.
    {
        scanf("%d", &n);
        if(n <= 0)
            printf("\nInvalid entry. Enter again: ");
    } while (n <= 0);
    
    printf("\nEnter the elements in the list:\n");
    int* ar = (int*) calloc(n, sizeof(int)); // Program is based on int values due to declaring the array as int. // Dynamic array declaration and initialisation using pointers.
    for(int i = 0; i < n; i++)
        scanf("%d", &ar[i]);

    printf("\nThe entered list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    bubbleSort(n, ar);

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    printf("\n\n\nEnd of code reached.\n\n\n");
    return 0;
}

void bubbleSort(int n, int* ar)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n-1; j++)
        {
            if(ar[j] > ar[j+1])
                swap(j, j+1, ar);
        }
    }
}

void swap(int i, int j, int* ar)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}