#include <stdio.h>
#include <stdlib.h>

void quickSort(int* ar, int p, int r);
int randomizedPartition(int* ar, int p, int r);
void swap(int i, int j, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Randomized Quick Sort.\n\n");

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

    int p = 0;
    int r = n-1;
    quickSort(ar, p, r);

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void quickSort(int* ar, int p, int r)
{
    if(p < r) // At p == q, only 1 element will be left in that sub-array so cannot/no need to further partition.
    {
        int q = randomizedPartition(ar, p, r);
        quickSort(ar, p, q-1);
        quickSort(ar, q+1, r);
    }
}

int randomizedPartition(int* ar, int p, int r)
{
    int i = p;
    int j = r;
    int q;
    int pivotIndex = (rand() % (r - p + 1)) + p;
    swap(p, pivotIndex, ar);
    int pivot = ar[p];

    while(i < j)
    {
        while(ar[i] <= pivot && i <= r)
            i++;
        while(ar[j] > pivot && i >= p)
            j--;
        if(i < j)
            swap(i, j, ar);
    }
    swap(j, p, ar);
    return j;
}

void swap(int i, int j, int* ar)
{
    int temp = ar[i];
    ar[i] = ar[j];
    ar[j] = temp;
}
