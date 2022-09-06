#include <stdio.h>
#include <stdlib.h>

int randomizedSelection(int* ar, int p, int r, int i);
int randomizedPartition(int* ar, int p, int r);
void swap(int i, int j, int* ar);

int main()
{
    printf("\n\nProgram to find the i th min element using the Randomized Selection Method based on the Randomized Quick Sort's Randomized Partition method.\n\n");

    printf("\nEnter the size of the list: ");
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

    printf("\n\nEnter the value of i to find the i th min element in the array: ");
    int i;
    do // Input validation for variable 'i'.
    {
        scanf("%d", &i);
        if(i <= 0 || i > n)
            printf("\nInvalid entry. Enter again: ");
    } while (i <= 0 || i > n);
    
    int p = 0;
    int r = n-1;
    int iMin = randomizedSelection(ar, p, r, i);

    printf("\nThe %dth min element is: %d\n", i, iMin);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

int randomizedSelection(int* ar, int p, int r, int i)
{
    if(p == r)
        return ar[p];

    int q = randomizedPartition(ar, p, r);
    int k = q - p + 1;
    if(i <= k)
        randomizedSelection(ar, p, q-1, i);
    else
        randomizedSelection(ar, q+1, r, i-k);
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
        while(ar[j] > pivot && j >= p)
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