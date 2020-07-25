#include <stdio.h>
#include <limits.h>
#include <stdarg.h>

/* ref: codeforwin */
/* Function declarations */
int max(int args, ...);
int min(int args, ...);



int main() 
{   
    /*
     * Demonstrate the use of variable argument list
     */
    printf("Maximum of three numbers: (10, 30, 20) = %d\n", max(3, 10, 30, 20));
    printf("Maximum of five numbers: (5, -45, 4, 60, 100) = %d\n", max(5, -45, 4, 60, 100));
    
    printf("Minimum of four numbers: (-5, 0, 10, 50) = %d\n", min(4, -5, 0, 10, 50));
    printf("Minimum of two numbers: (10, 20) = %d", min(2, 10, 20));
    
    return 0;
}


/**
 * Find maximum between two or more integer variables
 * @param args Total number of integers
 * @param ... List of integer variables to find maximum
 * @return Maximum among all integers passed
 */
int max(int args, ...)
{
    int i, max, cur;
    va_list valist;
    va_start(valist, args);
    
    max = INT_MIN;
    
    for(i=0; i<args; i++)
    {
        cur = va_arg(valist, int); // Get next elements in the list
        if(max < cur)
            max = cur;
    }
    
    va_end(valist); // Clean memory assigned by valist
    
    return max;
}

/**
 * Find minimum between two or more integer variables
 * @param args Total number of integers
 * @param ... List of integer variables to find minimum
 * @return Minimum among all integers passed
 */
int min(int args, ...) 
{
    int i, min, cur;
    va_list valist;
    va_start(valist, args);
    
    min = INT_MAX;
    
    for(i=0; i<args; i++)
    {
        cur = va_arg(valist, int);
        if(min > cur)
            min = cur;
    }
    
    va_end(valist);
    
    return min;
}
