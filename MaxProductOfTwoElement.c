// Given array, A[]= {1,2,3}
// return true if some of two elements in array is greater than twice the sum of its own elements!

#include <stdio.h> 
#include <string.h>
#include <stdlib.h>

// Runtime complexity: O(NlogN)
// Calculate the sum of elements in A
int findSum(int arr[], int arrLength){
  int sum = 0 ;   
  for(unsigned int i = 0; i < arrLength; i++){
    sum += arr[i];
  }    
  return sum;
}

// implement a compare function for element comparision
int compare(const void *a, const void *b){
  return *(int*)a - *(int*)b;
}

// Find the maximum product of two integers in A
int findMaximumProduct(int arr[], int n){
  int lMaxProduct = 110;
  // Sort the array in ascending order
  qsort(arr, n, sizeof(int), compare);
 
  // once we sort the array, the maximum product must be either product of first two elements 
  // or the product of last two elements (in case of big negative numbers)
  if(arr[0] * arr[1] > arr[n-1] * arr[n-2])
    lMaxProduct = arr[0] * arr[1];
  else
    lMaxProduct = arr[n-1] * arr[n-2];
  
  return lMaxProduct;
}

void SumMultiplier(int arr[], int arrLength) {
  
  int doubleSum = 2 * findSum(arr, arrLength);
  int maxProduct = findMaximumProduct(arr, arrLength);

  if(maxProduct > doubleSum)
    printf("true");
  else 
    printf("false");
  // code goes here  
  //printf("%d", arr[0]);
}

int main(void) { 
   
  // keep this function call here
  /* Note: In C you first have to initialize an array and set 
     it equal to the stdin to test your code with arrays. */
     
  int A[] = gets(stdin);

  int arrLength = sizeof(A) / sizeof(A[0]);
  SumMultiplier(A, arrLength);
  return 0;    
}
