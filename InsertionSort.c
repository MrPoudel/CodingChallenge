/* Bubble sorting implementation */
/* Worst case complexity: O(n^2) */
/* Best-case: O(n) */

#include <stdio.h>

void insertionSort(int A[], int N)
{
    for(int i = 1; i < N; i++)
    {  
        int val = A[i];
        int index = i;
        
        while(index > 0 && (A[index -1] > val))
        {
            A[index] = A[index - 1];
            index = index - 1;
        }
        
        A[index] = val;
    }
}

#define ARRAY_SIZE 7
int main()
{
    int A[] = { 19, 2, 33, 4, -6, 0, 99};
    
   insertionSort(A, ARRAY_SIZE);
    
    for(int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("\n%d", A[i]);
    }

    return 0;
}
