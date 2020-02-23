
#include <stdio.h>
#include <stdbool.h>

int solution(int N) {

    int max = 0;
		int counter = 0;
		bool isCounting = false;
		
		while(N > 0) 
		{
			if((N & 1) == 1) 
			{
				if(isCounting) 
				{
					max = max > counter? max:counter;
					counter = 0;
				} 
				else
				{
					isCounting = true;
					counter = 0;
				}
			} 
			
			else 
			{
				if(isCounting) 
				{
					counter++;
				}
			}
			
			N >>= 1;
		}
		
		return max;
}

int main()
{   
    int gap = solution(33); // 100001 --> 4
    printf("\n%d", gap);
    
    gap = solution(9);  // 1001 --> 2
    printf("\n%d", gap);

    return 0;
}
