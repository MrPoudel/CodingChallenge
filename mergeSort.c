#include <stdio.h>

void merge(int arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    int L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[left..right]*/
    i = 0; // Starting index of first subarray 
    j = 0; // Starting index of second subarray 
    k = l; // Starting index of merged subarray 
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k++] = L[i++];             
        } 
        else
        { 
            arr[k++] = R[j++];            
        }        
    } 
  
    /* If there are remaining elements in L[] then copy them all */
    while (i < n1) 
    { 
        arr[k++] = L[i++]; 
    } 
  
    /* If there are remaining elements in R[] then copy them all */
    while (j < n2) 
    { 
        arr[k++] = R[j++]; 
    } 
}

/* left is for left index and right is right index of the 
   sub-array of arr to be sorted */
void mergeSort(int arr[], int left, int right) 
{ 
    if (left < right) 
    { 
        // Avoid overflow for large array
        int mid = left+(right-left)/2; 
  
       
        mergeSort(arr, left, mid); // sort the left array recursively
        mergeSort(arr, mid+1, right); // sort the right array recursively
  
        merge(arr, left, mid, right); 
    } 
} 

int main()
{
    printf("Hello World\n");
    
    int arr[] = {-12,11, 5 , -4}; 
    int size = sizeof(arr)/sizeof(arr[0]); 
  
    mergeSort(arr, 0, size - 1); 
    
    for (int i=0; i < size; i++) 
        printf("%d \t", arr[i]); 
  
    return 0; 
}
