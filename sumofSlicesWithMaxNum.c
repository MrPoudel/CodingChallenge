// CPP program to calculate max sum lengths of
// non overlapping contiguous subarrays with k as
// max element

#include <bits/stdc++.h>
using namespace std;

// Returns max sum of lengths with maximum element
// as k
int calculateMaxSumLength(int arr[], int n, int k)
{
	//int ans = 0; // final sum of lengths
	int sum = 0;

	// number of elements in current subarray
	//int count = 0;

	// variable for checking if k appeared in subarray
	int flag = 0;

	for (int i = 0; i < n;) {
		//count = 0;
		flag = 0;

		int sliceSum = 0;

		// count the number of elements which are
		// less than equal to k
		while (arr[i] <= k && i < n) {

			sliceSum += arr[i];

			//count++;
			if (arr[i] == k)
				flag = 1;
			i++;
		}

		// if current element appeared in current
		// subarray add count to sumLength
		if (flag == 1)
		{
			//ans += count;
			sum += sliceSum;
		}

		// skip the array elements which are
		// greater than k
		while (arr[i] > k && i < n)
			i++;
	}
	return sum;
}

// driver program
int main()
{
	int arr[] = { 2, 1, 4, 9, 2, 3, 8, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int k = 4;
	int ans = calculateMaxSumLength(arr, size, k);
	cout << "Max sum :: " << ans << endl; // this will print --> 14 --> [2, 1, 4] and [3,4]
	return 0;
}
