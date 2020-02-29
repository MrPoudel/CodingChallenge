#include <stdio.h>
#include <stdbool.h>
// Finds a number in a list that is repeated more than half of the element numbers.

#include <string.h>

int a[10000001];

void findMajority(int arr[], int n)
{
    memset(a, 0, sizeof(a));
    
    bool flag = false;
        for(int i =0;i<n;i++)
        {
            a[arr[i]]++;
            if(a[arr[i]] > n/2)
            {
               printf("\n %d", arr[i]);
               flag = true;
            }
        }
        
        if(flag == false){
            printf("-1");
        }   
}

int main() 
{ 
	int arr[] = {12, 5, 5, 5, 5, 19, 26}; 
	int n = sizeof(arr)/sizeof(arr[0]), k = 3; 
	findMajority(arr, n); 
	return 0; 
}
