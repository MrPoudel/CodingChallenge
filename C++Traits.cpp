#include <iostream>
#include <limits>

using namespace std;

template< class T > 
T findMax(const T * data, 
         const size_t numItems) { 
  // Obtain the minimum value for type T 
  T largest = 
      std::numeric_limits< T >::min(); 
  for(unsigned int i=0; i<numItems; ++i) 
  if (data[i] > largest) 
  largest = data[i]; 
  return largest; 
} 

int main()
{
	const int a[] = { 2,3,5,6,1};
	
	cout << findMax(a, 5) << endl; 
	
	const float b[] = { 20.3, 3, 89, 5, 688.012,1};
	
	cout << findMax(b, 7) << endl; 

	return 0;
}
