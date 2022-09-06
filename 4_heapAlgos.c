#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void buildMinHeap();
void buildMaxHeap();
void deleteEleMinHeap(int flag);
void deleteEleMaxHeap(int flag);
void insertEleMinHeap();
void insertEleMaxHeap();
void minHeapify(int* arHeap, int heapSize, int i);
void maxHeapify(int* ar, int heapSize, int i);
void heapSortAsc();
void heapSortDesc();

void swapInt(int* a, int *b);
void printHeap();

int* arHeap;
int heapSize;
int arSize;

void main()
{
    printf("\n\n\nProgram implementing various Heap Algorithms.\n\n");

    char outerChoice;
    int midChoice;
    int innerChoice;

    heapSize;
    printf("\nEnter Heap Size: ");
    do
    {
        scanf("%d", &heapSize);
        if(heapSize < 1)
            printf("Invalid entry. Heap size cannot be < 1. Enter again: ");
    } while(heapSize < 1);

    arHeap = (int*) calloc(heapSize, sizeof(int));

    printf("\nEnter elements to form a Heap out of them:\n");
    for(int i = 0; i < heapSize; i++)
        scanf("%d", &arHeap[i]);

    arSize = heapSize;

    printf("\n\n------------Main Menu------------\n");
    printf("\n\nPress 1 or 2 to work with Min-Heap Algos or Max-Heap Algos respectively: ");

    do
    {
        scanf("%d", &midChoice);
        if(midChoice != 1 && midChoice != 2)
            printf("\nInvalid entry. Enter again: ");
    } while (midChoice != 1 && midChoice != 2);
        
    do
    {
        if(midChoice == 1)
        {
            printf("\n\n------------Main Menu Min Heap------------\n\n");
            printf("1. Building Min-Heap using a given array.\n");
            printf("2. Deleting an element from an entered Min-Heap.\n");
            printf("3. Inserting an element to an entered Min-Heap.\n");
            printf("4. Heapify method for buidling Min-Heap.\n");
            printf("5. Heap sort (Ascending Order).\n");
            printf("\nEnter here: ");
            
            do
            {
                scanf("%d", &innerChoice);
                if(innerChoice < 1 || innerChoice > 5)
                    printf("\n\nInvalid Entry. Enter again: ");
            } while(innerChoice < 1 || innerChoice > 5);

            switch(innerChoice)
            {
                case 1: buildMinHeap(); break;
                case 2: deleteEleMinHeap(1); break;
                case 3: insertEleMinHeap(); break;
                case 4: 
                {
                    for(int i = floor(heapSize/2)-1; i >= 0; i--)
                        minHeapify(arHeap, heapSize, i);
                }
                printHeap();
                break;
                case 5: heapSortAsc(); break;
            }
        }

        else if(midChoice == 2)
        {
            printf("\n\n------------Main Menu Max Heap------------\n\n");
            printf("1. Building Max-Heap using a given array.\n");
            printf("2. Deleting an element from an entered Max-Heap.\n");
            printf("3. Inserting an element to an entered Max-Heap.\n");
            printf("4. Heapify method for buidling Max-Heap.\n");
            printf("5. Heap sort (Descending Order).\n");
            printf("\nEnter here: ");
            
            do
            {
                scanf("%d", &innerChoice);
                if(innerChoice < 1 || innerChoice > 5)
                    printf("\n\nInvalid Entry. Enter again: ");
            } while(innerChoice < 1 || innerChoice > 5);

            switch(innerChoice)
            {
                case 1: buildMaxHeap(); break;
                case 2: deleteEleMaxHeap(1); break;
                case 3: insertEleMaxHeap(); break;
                case 4: 
                {
                    for(int i = floor(heapSize/2)-1; i >= 0; i--)
                        maxHeapify(arHeap, heapSize, i);
                }
                printHeap();
                break;
                case 5: heapSortDesc(); break;
            }
        }

        printf("\n\nEnter 'Y' or 'y' to continue or any key to exit (re-run the program to select Min/Max Heap again): ");
        while ((getchar()) != '\n');
        scanf("%c", &outerChoice);

    } while(outerChoice == 'y' || outerChoice == 'Y');
    
}

void swapInt(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void printHeap()
{
    printf("\nThe Heap in array form: ");
    for(int i = 0; i < heapSize; i++)
        printf("%d ", arHeap[i]);

    printf("\n");

    printf("\nThe Heap in Complete/Almost Complete Binary Tree form (Except the root element, Left Child: Cyan & Right Child = Purple):\n\n");
    int noOfLev = floor(log2(heapSize));
    int k = 0;
    int color = 1;
    for(int i = 0; i <= noOfLev; i++)
    {
        for(int j = 0; j < pow(2, i) && k < heapSize ; j++)
        {
            if(color == 1 && i != 0)
            {
                printf("\033[0;35m");
                color--;
            }
            else if(color == 0 && i != 0)
            {
                printf("\033[0;36m");
                color++;
            }
            printf("%d ", arHeap[k]);
            k++;
        }
        printf("\n\n");
    }
    printf("\033[0m");
}

void buildMinHeap()
{
    for(int i = 1; i < heapSize; i++)
    {
        for(int j = i; j > 0; j = floor((j-1)/2))
        {
            int k = floor((j-1)/2);
            if(arHeap[j] < arHeap[k])
                swapInt(&arHeap[j], &arHeap[k]);
        }
    }
    printHeap();
}

void buildMaxHeap()
{
    for(int i = 1; i < heapSize; i++)
    {
        for(int j = i; j > 0; j = floor((j-1)/2))
        {
            int k = floor((j-1)/2);
            if(arHeap[j] > arHeap[k])
                swapInt(&arHeap[j], &arHeap[k]);
        }
    }
    printHeap();
}

void deleteEleMinHeap(int flag)
{
    if(heapSize == 0)
    {
        printf("\nNo element left to delete.\n");
        return;
    }

    if(flag == 0) 
        printf("%d ", arHeap[0]);

    arHeap[0] = arHeap[heapSize - 1];
    heapSize--;

    // or buildMinHeap();
    for(int i = floor(heapSize/2)-1; i >= 0; i--)
        minHeapify(arHeap, heapSize, i); 

    if(flag == 1)
        printHeap();
}

void deleteEleMaxHeap(int flag)
{
    if(heapSize == 0)
    {
        printf("\nNo element left to delete.\n");
        return;
    }

    if(flag == 0) 
        printf("%d ", arHeap[0]);

    arHeap[0] = arHeap[heapSize - 1];
    heapSize--;
    
    // or buildMaxHeap();
    for(int i = floor(heapSize/2)-1; i >= 0; i--)
        maxHeapify(arHeap, heapSize, i); 

    if(flag == 1)
        printHeap();
}

void insertEleMinHeap()
{
    printf("\nEnter the element to be inserted: ");
    int ele; 
    scanf("%d", &ele);

    heapSize++;
    arHeap[heapSize-1] = ele;
    buildMinHeap();
}

void insertEleMaxHeap()
{
    printf("\nEnter the element to be inserted: ");
    int ele; 
    scanf("%d", &ele);

    heapSize++;
    arHeap[heapSize-1] = ele;
    buildMaxHeap();
}

void minHeapify(int* arHeap, int heapSize, int i)
{
    int smallest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < heapSize && arHeap[l] < arHeap[smallest])
        smallest = l;
    if(r < heapSize && arHeap[r] < arHeap[smallest])
        smallest = r;
    if(smallest != i)
    {
        swapInt(&arHeap[smallest], &arHeap[i]);
        minHeapify(arHeap, heapSize, smallest);
    }
}

void maxHeapify(int* arHeap, int heapSize, int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    if(l < heapSize && arHeap[l] > arHeap[largest])
        largest = l;
    if(r < heapSize && arHeap[r] > arHeap[largest])
        largest = r;
    if(largest != i)
    {
        swapInt(&arHeap[largest], &arHeap[i]);
        maxHeapify(arHeap, heapSize, largest);
    }
}

void heapSortAsc()
{
    printf("\n\nSorted Array in Ascending order: ");
    for(int i = floor(heapSize/2)-1; i >= 0; i--)
        minHeapify(arHeap, heapSize, i); 
    for(int i = 0; i < arSize; i++)
    {
        deleteEleMinHeap(0);
    }
}

void heapSortDesc()
{
    printf("\n\nSorted Array in Descending order: ");
    for(int i = floor(heapSize/2)-1; i >= 0; i--)
        maxHeapify(arHeap, heapSize, i); 
    for(int i = 0; i < arSize; i++)
    {
        deleteEleMaxHeap(0);
    }
}