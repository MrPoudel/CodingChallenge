/* This program will find the smallest missing positive integer in a given Array of size N. */

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
