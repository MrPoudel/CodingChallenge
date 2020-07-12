#include <stdio.h> 
#include <string.h>

void BinaryReversal(char str[]) {

  // code goes here
  unsigned int inStrLen1 = 0U;
  unsigned int convNum1 =0U;
  unsigned int cntPadBit = 0U;
  unsigned int rverseRst = 0U;
  unsigned int tmpIdx = 0U;
  unsigned int tmpVal = 0U;


  /*#### change string to number ###*/
  inStrLen1 = strlen(str);
  //printf("\n%s\n", str);

  for(tmpIdx = 0U; tmpIdx < inStrLen1; tmpIdx++)
  {
    tmpVal = (str[tmpIdx] - '0');
    convNum1 = 10*convNum1+tmpVal;  
  }

  tmpVal = convNum1;
  while(tmpVal > 0U)
  {
    tmpVal = tmpVal/255U;
    cntPadBit = cntPadBit+8U;
  }
 
  for(tmpIdx = 0U; tmpIdx < cntPadBit; tmpIdx++)
  {
    tmpVal =  (convNum1>>tmpIdx)&1U ;
    rverseRst = (rverseRst << 1) + tmpVal;   
  }
  printf("%d\n", rverseRst);
}

int main(void) { 
   
  // keep this function call here
  BinaryReversal(gets(stdin));
  return 0;
    
}
