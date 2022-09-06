#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void bucketSort(int n, float* ar);
float minFind(int n, float* ar);
float maxFind(int n, float* ar);
void insertionSort(int n, float* ar);

/*  
    This program accepts all real numbers which are then converted in the range [0, 1] to sort them using The Bucket Sort Algorithm
    and then these are again after sorting converted to the original numbers to form a sorted list of real numbers.
*/

int main()
{
    printf("\n\nProgram to sort a list of numbers as entered by the user using The Bucket Sort.\n\n");

    printf("\nEnter the size of the list to be sorted: ");
    int n;
    do // Input validation for variable 'n'.
    {
        scanf("%d", &n);
        if(n <= 0)
            printf("\nInvalid entry. Enter again: ");
    } while (n <= 0);
    
    printf("\nEnter the elements in the list:\n");
    float* ar = (float*) calloc(n, sizeof(float)); // Program is based on int values due to declaring the array as int. // Dynamic array declaration and initialisation using pointers.
    for(int i = 0; i < n; i++)
        scanf("%f", &ar[i]);
    
    printf("\nThe entered list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%f\t", ar[i]);

    float checkNegative = minFind(n, ar); // Converting negative nos. to positive nos.
    if(checkNegative < 0);
        for(int i = 0; i < n; i++)
            ar[i] = ar[i] - checkNegative;

    float* dr = (float*) calloc(n, sizeof(float));

    for(int i = 0; i < n; i++) // Finding and storing the no. of digits of each array element in another array in the corresponding index.
    {
        int a = ar[i];
        while(a % 10 != 0)
        {
            dr[i]++;
            a = a/10;
        }
        float b = ar[i];
        while(b - floor(b) != 0)
        {
            b = b*10;
            dr[i]++;
        }
    }

    int maxD = maxFind(n, dr);
    int pos = 1;
    for(int i = 0; i < maxD; i++)
        pos = pos*10;

    for(int i = 0; i < n; i++) // Converting all integers > 1 and floating point nos. < 1 to floating point numbers < 1.
        ar[i] = ar[i]/pos;

    bucketSort(n, ar);

    for(int i = 0; i < n; i++) 
        ar[i] = ar[i]*pos;

    if(checkNegative < 0);
        for(int i = 0; i < n; i++)
            ar[i] = ar[i] + checkNegative;


    printf("\n\nThe sorted list is:\n\n");
    for(int i = 0; i < n; i++)
        printf("%f\t", ar[i]);

    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

void bucketSort(int n, float* ar)
{
    float br[10][10];
    for(int i = 0; i < 10; i++)
        for(int j = 0; j < 10; j++)
            br[i][j] = 0;

    int c[10];
    for(int i = 0; i < 10; i++)
        c[i] = 0;

    int p;
    int q;

    for(int i = 0; i < n; i++)
    {
        p = floor(n*ar[i]);
        q = c[p];
        br[p][q] = ar[i];
        c[p]++;
    }

    for(int i = 0; i < 10; i++)
        insertionSort(c[i], br[i]);
    
    int f = 0;

    for(int i = 0; i < 10; i++)
        for(int k = 0; k < c[i]; k++)
        {    
            ar[f] = br[i][k];
            f++;
        }
}

float minFind(int n, float* ar)
{
    float min = ar[0]; 
    
    for(int i = 1; i < n; i++) 
        if(ar[i] < min) 
            min = ar[i];

    return min;        
}

float maxFind(int n, float* ar)
{
    float max = ar[0]; 
    
    for(int i = 1; i < n; i++) 
        if(ar[i] > max) 
            max = ar[i];

    return max;        
}

void insertionSort(int n, float* ar)
{
    int j; 
    float key;
    for(int i = 1; i < n; i++) 
    {
        key = ar[i]; 
        j = i - 1;
        while(j > -1 && key < ar[j])
        { 
            ar[j+1] = ar[j]; 
            j--; 
        }
        ar[j+1] = key; 
    } 
}