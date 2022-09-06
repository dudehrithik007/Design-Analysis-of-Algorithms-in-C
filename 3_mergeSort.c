#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int* mergeSort(int* ar, int lower, int upper);
int* merge(int* ar1, int* ar2, int lower, int q, int upper);

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Merge Sort.\n\n");

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

     int* ar2 = (int*) calloc(n, sizeof(int)); // ar2 stores the sorted array as returned by the mergeSort() function.

    ar2 = mergeSort(ar, 0, n-1);

    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%d\t", ar2[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

// Best understood when dry ran thoroughly.

int* mergeSort(int* ar, int lower, int upper) // Recursive function to divide the array into smaller arrays. The merge function conquers and combines the arrays.
{
   int q = floor((lower + upper) / 2);
   if(lower != upper)
   {
        int* ar1 = mergeSort(ar, lower, q);
        int* ar2 = mergeSort(ar, q+1, upper);
        return merge(ar1, ar2, lower, q, upper);
   }
   else
        return &ar[lower]; // or upper, as lower == upper here. // This returns an array of size 1 in which the single element is already in itself sorted. Using merge() we sort and combine the two arrays.
}

int* merge(int* ar1, int* ar2, int lower, int q, int upper)
{
    int i = 0, j = 0, k = 0;

    int m = upper - lower + 1;
    int* ar3 = (int*) calloc(m, sizeof(int));

    while(k < m && i < q - lower + 1 && j < upper - q) // j < upper - (q+1) - 1 // These are the number of elements in respectively the resultant, first and the second array.
    { // k < m is unnecessary above because atmost in the while loop only m-1 elements can be inserted, and the remaining one element will be inserted in the below if-else. This is because we exit the while loop as soon as one of the array's elements are all fully copied in the resultant array. So here k (index) will always be less than m and = m-1 in the last iteration. This m-1 th position will be filled below in the if-else. (0 to m-2 are m-1 elements). Either of the other two conditions above will make the while condition false, not both. That is why && is used that if either of the conditions becomes false, we exit the loop. Both needs to be true for the loop to run.
        if(ar1[i] >= ar2[j]) // Here changing > or < will change to descending order from ascending order sorting.
        {
            ar3[k] = ar2[j];
            j++;
            k++;
        }
        else
        {
           ar3[k] = ar1[i]; 
           i++;
           k++;
        }
    }
    // After all the elements of any of the arrays are fully copied in the resultant array ofc according to their correct positions, then the remaining elements of the other array are copied in the same order as each of the two arrays are already sorted.
    if(j == upper - q)
    {
        for(int r = i; r < q - lower + 1; r++, k++)
            ar3[k] = ar1[r];
    }
    else if(i == q - lower + 1)
    {
        for(int r = j; r < upper - q; r++, k++)
            ar3[k] = ar2[r];
    }

    return ar3; // returning the current sorted and merged array. a1 and a2 are merged accordingly.
}