#include <stdio.h>
#include <stdlib.h>

int** MatrixMultiply(int** x, int** y, int i, int k, int j);
int** MatrixChainMultiply(int*** ars, int** s, int i, int j);
void MatrixChainOrder(int n, int* p, int** m, int** s);

int* p;
int** mul;

int main()
{
    printf("\n\nProgram to multiply a chain of matrices in the optimal way (in terms of the no. of multiplication operations) using the Dynamic Programming design approach.\n\n");

    printf("\nEnter the number of matrices: ");
    int n;
    do // Input validation for variable 'n'.
    {
        scanf("%d", &n);
        if(n <= 0)
            printf("\nInvalid entry. Enter again: ");
    } while (n <= 0);

    printf("\nEnter the size of each matrix in the way: p0, p1, p2, ... , pn. Where size of matrix 0 is p0 x p1, matrix 1 is p1 x p2, ... matrix n-1 is pn-1 x pn.\n");
    p = (int*) calloc(n+1, sizeof(int));
    for(int i = 0; i <= n; i++)
    {
        do
        {
            scanf("%d", &p[i]);
            if(p[i] <= 0)
                printf("\nInvalid entry. Enter again: ");
        } while (p[i] <= 0);
    }

    int*** ars = (int***) calloc(n, sizeof(int**));
    int r = 0; 
    int c = 1;
    for(int i = 0; i < n; i++, r++, c++)
    {
        ars[i] = (int**) calloc(p[r], sizeof(int*));
        for(int j = 0; j < p[r]; j++)
        {
            ars[i][j] = (int*) calloc(p[c], sizeof(int));
        }
    }

    printf("\nEnter matrix elements:\n\n");
    r = 0; 
    c = 1;
    for(int i = 0; i <= n-1; i++, r++, c++)
    {
        printf("\nEnter matrix elements in matrix %d:\n", i);
        for(int j = 0; j < p[r]; j++)
        {
            for(int k = 0; k < p[c]; k++)
            {
                scanf("%d", &ars[i][j][k]);
            }
        }
    }

    printf("\nEntered matrices are:\n\n\n");
    r = 0; 
    c = 1;
    for(int i = 0; i <= n-1; i++, r++, c++)
    {
        printf("\nMatrix %d:\n", i);
        for(int j = 0; j < p[r]; j++)
        {
            for(int k = 0; k < p[c]; k++)
            {
                printf("%d ", ars[i][j][k]);
            }
            printf("\n");
        }
        printf("\n\n");
    }

    int** s = (int**) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
        s[i] = (int*) calloc(n, sizeof(int));

    int** m = (int**) calloc(n, sizeof(int));
    for(int i = 0; i < n; i++)
        m[i] = (int*) calloc(n, sizeof(int));

    MatrixChainOrder(n, p, m, s);
    int** resultant = MatrixChainMultiply(ars, s, 0, n-1);

    printf("\nMatrix m:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
                printf("%d ", m[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\nMatrices' parenthesisation using matrix s:\n");
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
                printf("%d ", s[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    printf("\nProduct of the chain of matrices computed in the optimal no. of multiplication operations:\n\n");
    for(int i = 0; i < p[0]; i++)
    {
        for(int j = 0; j < p[n]; j++)
        {
            printf("%d ", resultant[i][j]);
        }
        printf("\n");
    }

    printf("\nThe optimal number of multiplications are: %d", m[0][n-1]);
    
    printf("\n\nEnd of code reached.\n\n\n");
    return 0;
}

int** MatrixMultiply(int** x, int** y, int i, int k, int j)
{
    int** mul = (int**) calloc(p[i], sizeof(int*));
    for(int t = 0; t < p[i]; t++)
        mul[t] = (int*) calloc(p[j+1], sizeof(int));

    for(int ii = 0; ii < p[i]; ii++)    
    {    
        for(int jj = 0; jj < p[j+1]; jj++)    
        {    
            mul[ii][jj] = 0;    
            for(int kk = 0; kk < p[k+1]; kk++)    
            {    
                mul[ii][jj] += x[ii][kk] * y[kk][jj];    
            }    
        }    
    }    
    return mul;
}

int** MatrixChainMultiply(int*** ars, int** s, int i, int j)
{
    if(j > i)
    {
        int** x = MatrixChainMultiply(ars, s, i, s[i][j]);
        int** y = MatrixChainMultiply(ars, s, s[i][j] + 1, j);
        return MatrixMultiply(x, y, i, s[i][j], j);
    }
    else
        return ars[i];
}

void MatrixChainOrder(int n, int* p, int** m, int** s)
{
    for(int i = 0; i < n; i++)
        m[i][i] = 0;
    
    for(int len = 1; len < n; len++)
    {
        for(int i = 0; i < n-len; i++)
        {
            int j = i + len;
            m[i][j] = 2147483647;
            for(int k = i; k < j; k++)
            {
                int q = m[i][k] + m[k+1][j] + p[i]*p[k+1]*p[j+1];
                if(q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }
}