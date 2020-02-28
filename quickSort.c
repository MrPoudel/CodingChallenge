// Quick sort
// Reference: geeksforgeeks.org

#include<stdio.h> 

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Select the last elelment as the pivot element and place the pivot to it's correct position 
// All the elements that are smaller than the pivot will be on the left side
// All the elements that are bigger than the pivot will be on the right side
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
	
	printf("Returning the pivot position:%d\n", i+1);
	printArray(arr, high); 
	return (i + 1); 
} 

/* Break divide the array into two parts from pivot element and do the sorting */
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
		printf("%d ", arr[i]); 
	printf("\n"); 
} 

// Test program
int main() 
{ 
	int arr[] = {97, 17, 54, -9, 10, 85}; 
	int n = sizeof(arr)/sizeof(arr[0]); 
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
