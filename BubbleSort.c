/* Bubble sorting implementation */
/* Worst case complexity: O(n^2) */
/* Best-case: O(n) */

#include <stdio.h>
#include <stdbool.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int A[], int N)
{
    for(int i = 0; i < N-1; i++)
    {  
        printf("\nSorting taking place!");
        
        bool isSwapped = false;
        
        for (int j = 0; j < N-1; j++)
        {
           if(A[j] > A[j+1])
           {
              swap(&A[j], &A[j+1]);
              isSwapped = true;
           }
        }        
        if(!isSwapped)
        {
            printf("\nList is already sorted!");
            break;            
        }
    }
}

int main()
{
    int A[] = { 9, 2, 3, 4};
    
    bubbleSort(A, 4);
    
    for(int i = 0; i < 4; i++)
    {
        printf("\n%d", A[i]);
    }
    
    return 0;
}
