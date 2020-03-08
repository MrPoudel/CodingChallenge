// This program calcualtes maximum sum of two non overlapping subarrays in a given array.

// CPP program to calculate max sum lengths of
// non overlapping contiguous subarrays with k as
// max element
#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

int maxSum(int nums[], int N, int L, int M);

int maxSumTwoNoOverlap(int nums[],int N, int L, int M) {

   if ( N == 0 || N < L + M)
       return -1;

   return maxSum(nums, N, L, M);
}

int maxSum(int nums[], int N, int L, int M) {

    for (int i = 1; i < N; ++i)
        nums[i] += nums[i - 1];

    int res = nums[L + M - 1], Lmax = nums[L - 1], Mmax = nums[M - 1];

    for (int i = L + M; i < N; ++i) {

        //Lmax is the case when L contiguous elements are taken first
        Lmax = max(Lmax, nums[i - M] - nums[i - L - M]);

        //Mmax is the case when M contiguous elements are taken first
        Mmax = max(Mmax, nums[i - L] - nums[i - L - M]);
        int x = Lmax + nums[i] - nums[i - M];
        int y = Mmax + nums[i] - nums[i - L];

        res = max(res, max(x, y));
    }
    return res;
}

// driver program
int main()
{
	int arr[] = { 2, 1, 4, 9, 2, 3, 8, 3, 4 };
	int size = sizeof(arr) / sizeof(arr[0]);

	int ans = maxSumTwoNoOverlap(arr, size, 1, 2);
	cout << "Max sum :: " << ans << endl;
	return 0;
}
