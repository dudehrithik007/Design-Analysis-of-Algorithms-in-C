#include <stdio.h>
#include <stdlib.h>

void SelectionSort(int n, int* ar);
void swap(int i, int j, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Selection Sort.\n\n");

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

    SelectionSort(n, ar);

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void SelectionSort(int n, int* ar)
{
    for(int i = 0; i < n - 1; i++)
    {
        int min = i;
        for(int j = i + 1; j < n; j++)
        {
            if(ar[j] < ar[min])
                min = j;
        }
        if(min != i)
            swap(min, i, ar);
    }
}

void swap(int i, int j, int* ar)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}