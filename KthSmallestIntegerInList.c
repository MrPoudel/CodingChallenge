#include <stdio.h>

//Utility function to swap
void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
}

int partition (int low, int high, int arr[]) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than the pivot 
		if (arr[j] < pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	
	//printf("Returning the pivot position:%d\n", i+1);
	//printArray(arr, high); 
	return (i + 1); 
} 


void quickSort(int arr[], int low, int high)
{
    if (low < high) 
	{ 
		/* pivot_position is the correct position of the pivot element */
		int pivot_position = partition(low, high, arr); 

		// Separately sort elements before pivot and after pivot
		quickSort(arr, low, pivot_position - 1); 
		quickSort(arr, pivot_position + 1, high); 
	} 
}

/* Utility function to print an array */
void printArray(int arr[], int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		printf("\t%d ", arr[i]); 
	printf("\n"); 
} 

int findKthSmallest(int arr[], int n, int k) 
{
    int smallest = 0;
    
    // Do the quck sort of the list 
    quickSort(arr, 0, n-1);
    
    printArray(arr, n);
    
    for(int i =0; i < n; i++)
    {
      if(i == (k-1))
      {
          smallest = arr[i];
          break;
      }
    }
    
    return smallest;
}

int main()
{
    printf("Hello World\n");
    
    int arr[] =  {7, 10, 4, 3, 20, 15};
    int k = 3;
    
    printf("\n%dth smallest number is: %d", k, findKthSmallest(arr, sizeof(arr)/sizeof(arr[0]), k));

    return 0;
}
