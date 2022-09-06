#include <stdio.h>
#include <stdlib.h>

void radixSort(int n, int* ar);
void countingSort(int n, int* ar, int pos);
int minFind(int n, int* ar);
int maxFind(int n, int* ar);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Radix Sort.\n\n");

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

    radixSort(n, ar);

    if(checkNegative < 0);
        for(int i = 0; i < n; i++)
            ar[i] = ar[i] + checkNegative;
    

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void radixSort(int n, int* ar)
{
    int max = maxFind(n, ar);
    for(int pos = 1; max/pos > 0; pos*=10)
        countingSort(n, ar, pos);
}

void countingSort(int n, int* ar, int pos)
{
    int count[10] = {0};
    int* br = (int*) calloc(n, sizeof(int));

    for(int i = 0; i < n; i++)
        count[(ar[i] / pos) % 10]++;
    
    for(int i = 1; i < 10; i++)
        count[i] = count[i] + count[i-1];
    
    for(int i = n-1; i >= 0; i--)
        br[--count[(ar[i] / pos) % 10]] = ar[i];

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