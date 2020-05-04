#include <stdio.h> 
#include <string.h>
#include <stdlib.h>
#include <math.h>

void BinaryReversal(char str[]) {
  
  int integerForm, mask = 1, length = 0, nBits = 0;
  char *bits, *output;

  integerForm = atoi(str);
  bits = calloc( 64 + 1, sizeof(char) );
  output = calloc( 64 + 1 ,sizeof(char));

  while(mask <= integerForm)
  {
    for(int index = nBits; index >= 0; index--)
      bits[index+1] = bits[index];

    if( (integerForm & mask) == 0 )
      bits[0] = '0';
    else
      bits[0] = '1';
    mask *= 2;
    nBits++;
  }
  bits[nBits] = '\0';

  length = strlen(bits);
  if( length%8 > 0)
    length = (length/8+1)*8;

  sprintf(output, "%*s", length, bits);
  free(bits);

  for(int index = 0; index < length; index++)
    if(output[index] == ' ')
        output[index] = '0';
  
  int i = length -1, j = 0;
  char ch;
  
  while(i > j)
  {
    ch = output[i];
    output[i] = output[j];
    output[j] = ch;
    i--;
    j++;
  }

  int pw = 0, intOutput = 0;
  for(int index = length-1; index >= 0; index--)
  {
    if( output[index] == '1')
      intOutput += pow(2, pw);  
    pw++;
  }

  printf("%d\n", intOutput );
  
}

int main(void) { 
   
  // keep this function call here
  BinaryReversal(gets(stdin));
  return 0;
    
}
