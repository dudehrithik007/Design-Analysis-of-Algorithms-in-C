#include <stdio.h>
#include <stdlib.h>

void countingSort(int n, int* ar, int k);
int minFind(int n, int* ar);
int maxFind(int n, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Counting Sort.\n\n");

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

    int checkNegative = minFind(n, ar);
    if(checkNegative < 0);
        for(int i = 0; i < n; i++)
            ar[i] = ar[i] - checkNegative;

    int k = maxFind(n, ar);

    countingSort(n, ar, k);

    if(checkNegative < 0);
        for(int i = 0; i < n; i++)
            ar[i] = ar[i] + checkNegative;
    

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void countingSort(int n, int* ar, int k)
{
    int* count = (int*) calloc(k+1, sizeof(int));
    int* br = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++)
        count[ar[i]]++;
    
    for(int i = 1; i < k+1; i++)
        count[i] = count[i] + count[i-1];
    
    for(int i = n-1; i >= 0; i--)
        br[--count[ar[i]]] = ar[i];

    for(int i = 0; i < n; i++)
        ar[i] = br[i];
}

int minFind(int n, int* ar)
{
    int min = ar[0]; 
    
    for(int i = 1; i < n; i++) 
        if(ar[i] < min) 
            min = ar[i];

    return min;        
}

int maxFind(int n, int* ar)
{
    int max = ar[0]; 
    
    for(int i = 1; i < n; i++) 
        if(ar[i] > max) 
            max = ar[i];

    return max;        
}