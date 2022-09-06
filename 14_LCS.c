#include <stdio.h>
#include <stdlib.h>

void lcs(int n1, int n2, char* ar, char* br);
void lcsPrint(char* br,char** arrows, int i, int j);
 
int main()
{
    printf("\n\nProgram to find the Longest Common Subsequnce in the two inputted sequences of characters.\n\n");

    printf("\nEnter the length of the first sequence: ");
    int n1;
    do
    {
        scanf("%d", &n1);
        if(n1 < 0)
            printf("\nInvalid input. Size is always >= 0. Please enter again: ");
    } while (n1 < 0);

    n1++;

    printf("\nEnter the first sequence:\n");
    char* ar = malloc(n1*sizeof(char));
    fflush(stdin);
    for(int i = 1; i < n1; i++)
        scanf("%c", &ar[i]);    

    printf("\nEnter the length of the second sequence: ");
    int n2;
    do
    {
        scanf("%d", &n2);
        if(n2 < 0)
            printf("\nInvalid input. Size is always >= 0. Please enter again: ");
    } while (n2 < 0);

    n2++;

    printf("\nEnter the second sequence:\n");
    char* br = malloc(n2*sizeof(char));
    fflush(stdin);
    for(int i = 1; i < n2; i++)
        scanf("%c", &br[i]); 
    
    lcs(n1, n2, ar, br);

    printf("\nEnd of code reached.\n\n");

    return 0;
}

void lcs(int n1, int n2, char* ar, char* br) 
{
    int** cr = (int**) malloc(n1*sizeof(int));
    for(int i = 0; i < n1; i++)
        cr[i] = (int*) malloc(n2*sizeof(int));

    char** arrows = (char**) malloc(n1*sizeof(char));
    for(int i = 0; i < n1; i++)
        arrows[i] = (char*) malloc(n2*sizeof(char));

    for(int i = 0; i < n1; i++)
    {
        for(int j = 0; j < n2; j++)
        {
            if(i == 0 || j == 0)
                cr[i][j] = 0;
            
            else if(ar[i] != br[j])
            {
                if(cr[i-1][j] >= cr[i][j-1])
                {
                    cr[i][j] = cr[i-1][j];
                    arrows[i][j] = 'u'; // 'u' means the upwards arrow.
                }
                else
                {
                    cr[i][j] = cr[i][j-1];
                    arrows[i][j] = 'l'; // 'l' means the leftwards arrow.
                }    
            }

            else if(ar[i] == br[j])
            {
                cr[i][j] = cr[i-1][j-1] + 1;
                arrows[i][j] = 'd'; // 'd' means the diagonal arrow.
            }
        }
    }    

    printf("\nLongest Common Subsequnce of the entered sequences is of length = %d", cr[n1-1][n2-1]);

    printf("\n\nOne of the Longest Common Subsequnce of the entered sequences is: ");

    int i = n1-1;
    int j = n2-1;
    lcsPrint(ar,arrows, i, j);

    printf("\n\n");
}

void lcsPrint(char* ar,char** arrows, int i, int j)
{
    if(i == 0 || j == 0)
        return;
    
    if(arrows[i][j] == 'd')
    {
        lcsPrint(ar, arrows, i-1, j-1);
        printf("%c", ar[i]);
    }

    else if(arrows[i][j] == 'u')
        lcsPrint(ar, arrows, i-1, j);

    else // for if leftwards arrow:
        lcsPrint(ar, arrows, i, j-1);
}