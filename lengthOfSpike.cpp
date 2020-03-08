#include <bits/stdc++.h> 
#include <vector> 

int solution(vector<int> &A) {
    // write your code in C++14 (g++ 6.2.0)
   
    if (A.size() == 0)
        return 0;
    
    if(A.size() == 1)
        return 1;
     
    // define two vectors to store the ascending and descending values  
    vector<int> v1, v2; 
    unordered_map <int, int> mpp;
    
    // Sort the array
    sort(A.begin(), A.end());
    
    // extract the repeated elements into another vector
    for (unsigned int i = 0; i < A.size(); i++)
	{
	  // Increase the count
	  mpp[A[i]]++;
	  
	  if (mpp[A[i]] == 1) 
          v1.push_back(A[i]);
	  else
          v2.push_back(A[i]);
	}
    
    // Sort in increasing order 
    sort(v1.begin(), v1.end()); 
    
    // Sort in decreasing order 
    sort(v2.begin(), v2.end(), greater<int>()); 
   
    //append the elements from vector 2 if they are smaller than the last elements in vector v1 
    for (unsigned int i = 0; i < v2.size(); i++) 
    {
      if(v2[i] < v1[v1.size()-1]) 
      v1.push_back(v2[i]);
    }
    
    // Return the lenght of spike
    return v1.size();
}
