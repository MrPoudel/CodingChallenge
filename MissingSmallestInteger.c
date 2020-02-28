/* This program will find the smallest missing positive integer in a given Array of size N. */
/* Complexity: O(n^2) */

#include <stdbool.h>
#include <assert.h>

int solution(int A[], int N)
{
    assert(N < 100000);
    assert(N > 0);
    
    
    bool found;
    
    unsigned int smallest = 1;
    unsigned int outer, inner;
    
    for ( outer = 1; outer < N+1; outer++)
    {
        found = false; // imagine number is not present
        
        for( inner = 0; inner < N; inner++)
        {
            assert(A[inner] < 1000000);
            assert(A[inner] > -1000000);
            
            if (A[inner] == outer )
            {
                found = true; // number is present
                break;
            }
        }
        
        if(found == false) // number is not present
        {
            smallest = outer;
            break;
        }
    }
    
    if(found == true)
    {
       smallest = N+1;
    }
    
    return smallest;
}

// Solution from geeksforgeeks.org

// /* C program to find the smallest positive missing number */
// #include <stdio.h> 
// #include <stdlib.h> 

// /* Utility to swap to integers */
// void swap(int* a, int* b) 
// { 
// 	int temp; 
// 	temp = *a; 
// 	*a = *b; 
// 	*b = temp; 
// } 

// /* Utility function that puts all 
// non-positive (0 and negative) numbers on left 
// side of arr[] and return count of such numbers */
// int segregate(int arr[], int size) 
// { 
// 	int j = 0, i; 
// 	for (i = 0; i < size; i++) { 
// 		if (arr[i] <= 0) { 
// 			swap(&arr[i], &arr[j]); 
// 			j++; // increment count of non-positive integers 
// 		} 
// 	} 

// 	return j; 
// } 

// /* Find the smallest positive missing number 
// in an array that contains all positive integers */
// int findMissingPositive(int arr[], int size) 
// { 
// 	int i; 

// 	// Mark arr[i] as visited by making arr[arr[i] - 1] negative. 
// 	// Note that 1 is subtracted because index start 
// 	// from 0 and positive numbers start from 1 
// 	for (i = 0; i < size; i++) { 
// 		if (abs(arr[i]) - 1 < size && arr[abs(arr[i]) - 1] > 0) 
// 			arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1]; 
// 	} 

// 	// Return the first index value at which is positive 
// 	for (i = 0; i < size; i++) 
// 		if (arr[i] > 0) 
// 			// 1 is added because indexes start from 0 
// 			return i + 1; 

// 	return size + 1; 
// } 

// /* Find the smallest positive missing 
// number in an array that contains 
// both positive and negative integers */
// int findMissing(int arr[], int size) 
// { 
// 	// First separate positive and negative numbers 
// 	int shift = segregate(arr, size); 

// 	// Shift the array and call findMissingPositive for 
// 	// positive part 
// 	return findMissingPositive(arr + shift, size - shift); 
// } 

// int main() 
// { 
// 	int arr[] = { 0, 10, 2, -10, -20 }; 
// 	int arr_size = sizeof(arr) / sizeof(arr[0]); 
// 	int missing = findMissing(arr, arr_size); 
// 	printf("The smallest positive missing number is %d ", missing); 
// 	getchar(); 
// 	return 0; 
// } 
